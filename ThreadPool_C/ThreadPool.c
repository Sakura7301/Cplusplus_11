#include"ThreadPool.h"


// 任务结构体
struct Task
{
	void(*function)(void* arg);
	void* arg;
};



// 线程池结构体
struct ThreadPool
{
	// 任务队列
	Task* taskQueue;
	int queueCapacity;					// 容量
	int queueSize;						// 当前任务个数
	int queueFront;						// 队头 -> 取数据
	int queueRear;						// 队尾 -> 放数据

	pthread_t managerID;				 // 管理者线程ID
	pthread_t *workerIDs;				 // 工作的线程ID

	int minNum;							 // 最小线程数量
	int maxNum;							 // 最大线程数量
	int busyNum;						 // 忙的线程的个数
	int liveNum;						 // 存活的线程的个数	
	int exitNum;						 // 要销毁的线程个数

	pthread_mutex_t mutexPool;			// 锁整个的线程池
	pthread_mutex_t mutexBusy;			// 锁busyNum变量

	pthread_cond_t notFull;				// 条件变量:队列不为空
	pthread_cond_t notEmpty;			// 条件变量:队列不为满

	bool shutdown;						// 是否销毁线程池的标记
};

// 创建线程池并初始化
ThreadPool* threadPoolCreate(int min,  int max, int queueSize)
{
	if (max <= 0 || min>max || queueSize<=0 )
	{
		//传入的线程池属性不合法
		return NULL;
	}
	ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));
	do
	{
		if (pool == NULL)
		{
			//线程池内资源分配失败
			printf("malloc threadpool fail...\n");
			break;
		}

		pool->workerIDs = (pthread_t*)malloc(sizeof(pthread_t) * (unsigned int)max);
		if (pool->workerIDs == NULL)
		{
			//工作者资源分配失败
			printf("malloc workerIDs fail...\n");
			break;
		}
		memset(pool->workerIDs, 0, sizeof(pthread_t) * (unsigned int)max);
		pool->minNum = min;
		pool->maxNum = max;		
		pool->busyNum = 0;		//初始忙线程个数为0
		pool->liveNum = min;    // 和最小个数相等
		pool->exitNum = 0;		//初始要退出的线程为0

		if (pthread_mutex_init(&pool->mutexPool, NULL) != 0 ||
			pthread_mutex_init(&pool->mutexBusy, NULL) != 0 ||
			pthread_cond_init(&pool->notEmpty, NULL) != 0 ||
			pthread_cond_init(&pool->notFull, NULL) != 0)
		{
			//锁或条件变量初始化失败
			printf("mutex or condition init fail...\n");
			break;
		}

		// 初始化任务队列属性
		pool->taskQueue = (Task*)malloc(sizeof(Task) * (unsigned int)queueSize);
		if (pool->taskQueue == NULL)
		{
			printf("malloc taskQueueueue fail......\n");
			break;
		}
		pool->queueCapacity = queueSize;
		pool->queueSize = 0;
		pool->queueFront = 0;
		pool->queueRear = 0;
		pool->shutdown = false;

		// 创建线程
		pthread_create(&pool->managerID, NULL, manager, pool);
		for (int i = 0; i < min; ++i)
		{
			pthread_create(&pool->workerIDs[i], NULL, worker, pool);
		}
		return pool;	
	} while (0); 

	/*如果执行到此,说明线程池初始化失败了,释放资源即可*/
	if (pool && pool->workerIDs) free(pool->workerIDs);
	if (pool && pool->taskQueue) free(pool->taskQueue);
	if (pool) free(pool);
	return NULL;
}

//销毁线程池
int threadPoolDestroy(ThreadPool* pool)
{
	if (pool == NULL)
	{
		return -1;
	}

	// 关闭线程池
	pool->shutdown = true;
	// 阻塞回收管理者线程
	pthread_join(pool->managerID, NULL);
	
	for (int i = 0; i < pool->liveNum; ++i)
	{
		// 唤醒阻塞的工作者线程
		pthread_cond_signal(&pool->notEmpty);
	}

	// 释放堆内存
	if (pool->taskQueue)
	{
		free(pool->taskQueue);
	}
	if (pool->workerIDs)
	{
		free(pool->workerIDs);
	}

	//释放锁和条件变量
	pthread_mutex_destroy(&pool->mutexPool);
	pthread_mutex_destroy(&pool->mutexBusy);
	pthread_cond_destroy(&pool->notEmpty);
	pthread_cond_destroy(&pool->notFull);

	free(pool);
	pool = NULL;

	return 0;
}

// 给线程池添加任务
void threadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg)
{
	//锁整个线程池
	pthread_mutex_lock(&pool->mutexPool);
	while (pool->queueSize == pool->queueCapacity && !pool->shutdown)
	{
		// 事件队列已满,阻塞生产者线程
		pthread_cond_wait(&pool->notFull, &pool->mutexPool);
	}
	if (pool->shutdown)
	{
		pthread_mutex_unlock(&pool->mutexPool);
		return;
	}
	// 添加任务
	pool->taskQueue[pool->queueRear].function = func;
	pool->taskQueue[pool->queueRear].arg = arg;
	//使用%实现循环队列(用数组模拟)
	pool->queueRear = (pool->queueRear + 1) % pool->queueCapacity;
	pool->queueSize++;

	//唤醒工作者线程
	pthread_cond_signal(&pool->notEmpty);

	//操作完毕,解锁
	pthread_mutex_unlock(&pool->mutexPool);
}

//获取忙线程个数
int threadPoolBusyNum(ThreadPool* pool)
{
	pthread_mutex_lock(&pool->mutexBusy);
	int busyNum = pool->busyNum;
	pthread_mutex_unlock(&pool->mutexBusy);
	return busyNum;
}

//获取存活线程个数
int threadPoolAliveNum(ThreadPool* pool)
{
	pthread_mutex_lock(&pool->mutexPool);
	int aliveNum = pool->liveNum;
	pthread_mutex_unlock(&pool->mutexPool);
	return aliveNum;
}

//工作的线程(消费者线程)任务函数
void* worker(void* arg)
{
	ThreadPool* pool = (ThreadPool*)arg;

	while (1)
	{
		pthread_mutex_lock(&pool->mutexPool);
		// 当前任务队列是否为空
		while (pool->queueSize == 0 && !pool->shutdown)
		{
			// 队列空,阻塞工作线程
			pthread_cond_wait(&pool->notEmpty, &pool->mutexPool);

			// 判断是不是要销毁线程
			if (pool->exitNum > 0)
			{
				pool->exitNum--;
				if (pool->liveNum > pool->minNum)
				{
					pool->liveNum--;
					pthread_mutex_unlock(&pool->mutexPool);
					threadExit(pool);
				}
			}
		}

		// 判断线程池是否被关闭了(如果shutdown为true,则线程自动退出)
		if (pool->shutdown)
		{
			pthread_mutex_unlock(&pool->mutexPool);
			threadExit(pool);
		}

		// 从任务队列中取出一个任务
		Task task;
		task.function = pool->taskQueue[pool->queueFront].function;
		task.arg = pool->taskQueue[pool->queueFront].arg;
		// 移动头指针
		pool->queueFront = (pool->queueFront + 1) % pool->queueCapacity;
		pool->queueSize--;
		
		//唤醒生产者线程
		pthread_cond_signal(&pool->notFull);
		// 解锁
		pthread_mutex_unlock(&pool->mutexPool);

		printf("thread %ld start working...\n", pthread_self());
		pthread_mutex_lock(&pool->mutexBusy);
		pool->busyNum++;
		pthread_mutex_unlock(&pool->mutexBusy);
		task.function(task.arg);
		free(task.arg);
		task.arg = NULL;

		printf("thread %ld end working...\n", pthread_self());
		pthread_mutex_lock(&pool->mutexBusy);
		pool->busyNum--;
		pthread_mutex_unlock(&pool->mutexBusy);
	}
	return NULL;
}

// 管理者线程任务函数
void* manager(void* arg)
{ 
	ThreadPool* pool = (ThreadPool*)arg;
	while (!pool->shutdown)
	{
		// 每隔3s检测一次
		sleep(3);

		// 取出线程池中任务的数量和当前线程的数量
		pthread_mutex_lock(&pool->mutexPool);
		int queueSize = pool->queueSize;
		int liveNum = pool->liveNum;
		pthread_mutex_unlock(&pool->mutexPool);

		// 取出忙的线程的数量
		pthread_mutex_lock(&pool->mutexBusy);
		int busyNum = pool->busyNum;
		pthread_mutex_unlock(&pool->mutexBusy);

		// 添加线程
		// 任务的个数>存活的线程个数 && 存活的线程数<最大线程数
		if (queueSize > liveNum && liveNum < pool->maxNum)
		{
			pthread_mutex_lock(&pool->mutexPool);
			int counter = 0;
			for (int i = 0; i < pool->maxNum && counter < NUMBER
				&& pool->liveNum < pool->maxNum; ++i)
			{
				if (pool->workerIDs[i] == 0)
				{
					pthread_create(&pool->workerIDs[i], NULL, worker, pool);
					counter++;
					pool->liveNum++;
				}
			}
			pthread_mutex_unlock(&pool->mutexPool);
		}
		// 销毁线程
		// 忙的线程*2 < 存活的线程数 && 存活的线程>最小线程数
		if (busyNum * 2 < liveNum && liveNum > pool->minNum)
		{
			pthread_mutex_lock(&pool->mutexPool);
			pool->exitNum = NUMBER;
			pthread_mutex_unlock(&pool->mutexPool);
			// 让工作的线程自杀
			for (int i = 0; i < NUMBER; ++i)
			{
				//唤醒被阻塞的工作者线程
				pthread_cond_signal(&pool->notEmpty);
			}
		}
	}
	return NULL;
}

//单个线程退出的函数
void threadExit(ThreadPool* pool)
{
	pthread_t tid = pthread_self();
	for (int i = 0; i < pool->maxNum; ++i)
	{
		if (pool->workerIDs[i] == tid)
		{
			pool->workerIDs[i] = 0;
			printf("threadExit() called, %ld exiting...\n", tid);
			break;
		}
	}
	pthread_exit(NULL);
}
