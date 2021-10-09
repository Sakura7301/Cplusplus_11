#pragma once
#include"TaskQueue.hpp"

template<typename T>
class ThreadPool
{
public:
	ThreadPool(int min, int max);

	~ThreadPool();

	// 给线程池添加任务
	void threadPoolAdd(Task<T> task);

	// 获取线程池中工作的线程的个数
	int threadPoolBusyNum();

	// 获取线程池中活着的线程的个数
	int threadPoolAliveNum();

private:
	// 工作的线程(消费者线程)任务函数
	static void* worker(void* arg);
	// 管理者线程任务函数
	static void* manager(void* arg);
	/*设置为静态的原因是:
	如果该函数非静态,那么在该对象实例化之前不会分配内存空间;
	我们的构造函数就无法使用它作为线程的回调函数;
	因此,我们声明为静态,在实例化之前就已经分配内存空间;
	这样一来,在构造函数调用时就可以获取到地址了*/

	// 单个线程退出
	void threadExit();


private:
	TaskQueue<T> *taskQueue;				//任务队列

	pthread_t managerID;				 // 管理者线程ID
	pthread_t *workerIDs;				 // 工作的线程ID

	int minNum;							 // 最小线程数量
	int maxNum;							 // 最大线程数量
	int busyNum;						 // 忙的线程的个数
	int liveNum;						 // 存活的线程的个数	
	int exitNum;						 // 要销毁的线程个数

	static const int NUMBER = 2;			 //每次要添加的线程数

	pthread_mutex_t mutexPool;			// 锁整个的线程池

	pthread_cond_t notFull;				// 条件变量:队列不为空
	//pthread_cond_t notEmpty;			// 不需要这个是因为我们使用了STL容器,因此队列不可能位满

	bool shutdown;						// 是否销毁线程池的标记
};




template<typename T>
ThreadPool<T>::ThreadPool(int min, int max)
{
	do
	{
		//初始化任务队列
		taskQueue = new TaskQueue<T>;
		if (taskQueue == nullptr)
		{
			std::cout << "taskQueue init error" << std::endl;
			break;
		}

		//初始化工作线程ID
		workerIDs = new pthread_t[max];
		if (workerIDs == nullptr)
		{
			std::cout << "workerIDs init error" << std::endl;
			break;
		}
		//初始化
		memset(workerIDs, 0, sizeof(pthread_t)*(unsigned int)max);
		minNum = min;
		maxNum = max;
		busyNum = 0;
		liveNum = min;
		exitNum = 0;
		shutdown = false;

		//初始化锁&条件变量
		if (pthread_cond_init(&notFull, NULL) != 0 ||
			pthread_mutex_init(&mutexPool, NULL) != 0)
		{
			std::cout << "mutex or cond init error" << std::endl;
			break;
		}

		//创建管理者线程
		pthread_create(&managerID, NULL, manager, this);
		/*静态成员函数内部没有this指针,无法访问非静态成员变量
		  所以我们吧this指针作为参数传递过去*/

		  //循环创建工作者线程
		for (int i = 0; i < min; i++)
		{
			pthread_create(&workerIDs[i], NULL, worker, this);
		}
		return;
	} while (0);

	//如若失败,需要释放的申请的资源
	if (taskQueue) delete taskQueue;
	if (workerIDs) delete[]workerIDs;
	return;
}

template<typename T>
ThreadPool<T>::~ThreadPool()
{
	//关闭线程池
	this->shutdown = true;

	//阻塞回收管理者线程
	pthread_join(this->managerID, NULL);
	//唤醒工作者线程
	for (int i = 0; i < this->liveNum; i++)
	{
		pthread_cond_signal(&this->notFull);
	}

	//释放堆区内存
	if (taskQueue)
	{
		delete taskQueue;
	}
	if (workerIDs)
	{
		delete[]workerIDs;
	}

	//销毁锁和条件变量
	pthread_cond_destroy(&notFull);
	pthread_mutex_destroy(&mutexPool);
}


//向线程池添加任务
template<typename T>
void ThreadPool<T>::threadPoolAdd(Task<T> task)
{
	if (shutdown)
	{
		return;
	}

	//该函数内部已有线程同步操作,因此无需额外加锁
	taskQueue->addTask(task);//添加任务

	//唤醒线程
	pthread_cond_signal(&notFull);
}


//获取忙线程数量
template<typename T>
int ThreadPool<T>::threadPoolBusyNum()
{
	pthread_mutex_lock(&mutexPool);
	int ret = this->busyNum;
	pthread_mutex_unlock(&mutexPool);
	return ret;
}

//获取存活线程数量
template<typename T>
int ThreadPool<T>::threadPoolAliveNum()
{
	pthread_mutex_lock(&mutexPool);
	int ret = this->liveNum;
	pthread_mutex_unlock(&mutexPool);
	return ret;
}


//工作者线程任务函数
template<typename T>
void * ThreadPool<T>::worker(void * arg)
{
	//强制类型转换
	ThreadPool* pool = static_cast<ThreadPool*>(arg);

	//持续工作
	while (1)
	{
		//加锁
		pthread_mutex_lock(&pool->mutexPool);

		while (pool->taskQueue->getQueueSize() == 0 && !pool->shutdown)
		{
			//阻塞工作者线程
			pthread_cond_wait(&pool->notFull, &pool->mutexPool);

			//判断是不是要销毁线程
			if (pool->exitNum > 0)
			{
				pool->exitNum--;
				if (pool->liveNum > pool->minNum)
				{
					pool->liveNum--;
					pthread_mutex_unlock(&pool->mutexPool);
					pool->threadExit();
				}
			}
		}

		//判断线程池是不是关闭了
		if (pool->shutdown)
		{
			pthread_mutex_unlock(&pool->mutexPool);
			pool->threadExit();
		}

		//以上都不是,表示线程池正常工作
		//取出一个任务
		Task<T> task = pool->taskQueue->takeTask();
		pool->busyNum++;
		//取出任务后解锁
		pthread_mutex_unlock(&pool->mutexPool);

		//开始执行任务
		std::cout << "thread " << std::to_string(pthread_self()) << " [start] working..." << std::endl;
		task.function(task.arg);
		delete task.arg;
		std::cout << "thread " << std::to_string(pthread_self()) << " [ end ] working..." << std::endl;

		//工作完成,忙线程个数-1
		pthread_mutex_lock(&pool->mutexPool);
		pool->busyNum--;
		pthread_mutex_unlock(&pool->mutexPool);
	}
	return nullptr;
}

//管理者线程任务函数
template<typename T>
void * ThreadPool<T>::manager(void * arg)
{
	//强制类型转换
	ThreadPool* pool = static_cast<ThreadPool*>(arg);
	while (!pool->shutdown)
	{
		// 每隔5s检测一次
		sleep(5);
		// 取出线程池中的任务数和线程数量
		//  取出工作的线程池数量
		long queueSize = pool->taskQueue->getQueueSize();
		int liveNum = pool->liveNum;
		int busyNum = pool->busyNum;


		// 当前任务个数>存活的线程数 && 存活的线程数<最大线程个数
		if (queueSize > liveNum && liveNum < pool->maxNum)
		{
			// 线程池加锁
			pthread_mutex_lock(&pool->mutexPool);
			int num = 0;
			for (int i = 0; i < pool->maxNum && num < NUMBER && pool->liveNum < pool->maxNum; i++)
			{
				if (pool->workerIDs[i] == 0)
				{
					pthread_create(&pool->workerIDs[i], NULL, worker, pool);
					num++;
					pool->liveNum++;
				}
			}
			pthread_mutex_unlock(&pool->mutexPool);
		}

		// 销毁多余的线程
		// 忙线程*2 < 存活的线程数目 && 存活的线程数 > 最小线程数量
		if (busyNum * 2 < liveNum && liveNum > pool->minNum)
		{
			pthread_mutex_lock(&pool->mutexPool);
			pool->exitNum = NUMBER;
			pthread_mutex_unlock(&pool->mutexPool);
			for (int i = 0; i < NUMBER; ++i)
			{
				pthread_cond_signal(&pool->notFull);
			}
		}
	}
	return nullptr;
}


//线程退出函数
template<typename T>
void ThreadPool<T>::threadExit()
{
	//找到目标线程并通知
	pthread_t t_id = pthread_self();
	for (int i = 0; i < this->maxNum; i++)
	{
		if (t_id == workerIDs[i])
		{
			workerIDs[i] = 0;
			std::cout << "threadExit() called , " << std::to_string(t_id) << " exiting!" << std::endl;
			break;
		}
	}
	pthread_exit(NULL);
}
