#include"ThreadPool.h"


// ����ṹ��
struct Task
{
	void(*function)(void* arg);
	void* arg;
};



// �̳߳ؽṹ��
struct ThreadPool
{
	// �������
	Task* taskQueue;
	int queueCapacity;					// ����
	int queueSize;						// ��ǰ�������
	int queueFront;						// ��ͷ -> ȡ����
	int queueRear;						// ��β -> ������

	pthread_t managerID;				 // �������߳�ID
	pthread_t *workerIDs;				 // �������߳�ID

	int minNum;							 // ��С�߳�����
	int maxNum;							 // ����߳�����
	int busyNum;						 // æ���̵߳ĸ���
	int liveNum;						 // �����̵߳ĸ���	
	int exitNum;						 // Ҫ���ٵ��̸߳���

	pthread_mutex_t mutexPool;			// ���������̳߳�
	pthread_mutex_t mutexBusy;			// ��busyNum����

	pthread_cond_t notFull;				// ��������:���в�Ϊ��
	pthread_cond_t notEmpty;			// ��������:���в�Ϊ��

	bool shutdown;						// �Ƿ������̳߳صı��
};

// �����̳߳ز���ʼ��
ThreadPool* threadPoolCreate(int min,  int max, int queueSize)
{
	if (max <= 0 || min>max || queueSize<=0 )
	{
		//������̳߳����Բ��Ϸ�
		return NULL;
	}
	ThreadPool* pool = (ThreadPool*)malloc(sizeof(ThreadPool));
	do
	{
		if (pool == NULL)
		{
			//�̳߳�����Դ����ʧ��
			printf("malloc threadpool fail...\n");
			break;
		}

		pool->workerIDs = (pthread_t*)malloc(sizeof(pthread_t) * (unsigned int)max);
		if (pool->workerIDs == NULL)
		{
			//��������Դ����ʧ��
			printf("malloc workerIDs fail...\n");
			break;
		}
		memset(pool->workerIDs, 0, sizeof(pthread_t) * (unsigned int)max);
		pool->minNum = min;
		pool->maxNum = max;		
		pool->busyNum = 0;		//��ʼæ�̸߳���Ϊ0
		pool->liveNum = min;    // ����С�������
		pool->exitNum = 0;		//��ʼҪ�˳����߳�Ϊ0

		if (pthread_mutex_init(&pool->mutexPool, NULL) != 0 ||
			pthread_mutex_init(&pool->mutexBusy, NULL) != 0 ||
			pthread_cond_init(&pool->notEmpty, NULL) != 0 ||
			pthread_cond_init(&pool->notFull, NULL) != 0)
		{
			//��������������ʼ��ʧ��
			printf("mutex or condition init fail...\n");
			break;
		}

		// ��ʼ�������������
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

		// �����߳�
		pthread_create(&pool->managerID, NULL, manager, pool);
		for (int i = 0; i < min; ++i)
		{
			pthread_create(&pool->workerIDs[i], NULL, worker, pool);
		}
		return pool;	
	} while (0); 

	/*���ִ�е���,˵���̳߳س�ʼ��ʧ����,�ͷ���Դ����*/
	if (pool && pool->workerIDs) free(pool->workerIDs);
	if (pool && pool->taskQueue) free(pool->taskQueue);
	if (pool) free(pool);
	return NULL;
}

//�����̳߳�
int threadPoolDestroy(ThreadPool* pool)
{
	if (pool == NULL)
	{
		return -1;
	}

	// �ر��̳߳�
	pool->shutdown = true;
	// �������չ������߳�
	pthread_join(pool->managerID, NULL);
	
	for (int i = 0; i < pool->liveNum; ++i)
	{
		// ���������Ĺ������߳�
		pthread_cond_signal(&pool->notEmpty);
	}

	// �ͷŶ��ڴ�
	if (pool->taskQueue)
	{
		free(pool->taskQueue);
	}
	if (pool->workerIDs)
	{
		free(pool->workerIDs);
	}

	//�ͷ�������������
	pthread_mutex_destroy(&pool->mutexPool);
	pthread_mutex_destroy(&pool->mutexBusy);
	pthread_cond_destroy(&pool->notEmpty);
	pthread_cond_destroy(&pool->notFull);

	free(pool);
	pool = NULL;

	return 0;
}

// ���̳߳��������
void threadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg)
{
	//�������̳߳�
	pthread_mutex_lock(&pool->mutexPool);
	while (pool->queueSize == pool->queueCapacity && !pool->shutdown)
	{
		// �¼���������,�����������߳�
		pthread_cond_wait(&pool->notFull, &pool->mutexPool);
	}
	if (pool->shutdown)
	{
		pthread_mutex_unlock(&pool->mutexPool);
		return;
	}
	// �������
	pool->taskQueue[pool->queueRear].function = func;
	pool->taskQueue[pool->queueRear].arg = arg;
	//ʹ��%ʵ��ѭ������(������ģ��)
	pool->queueRear = (pool->queueRear + 1) % pool->queueCapacity;
	pool->queueSize++;

	//���ѹ������߳�
	pthread_cond_signal(&pool->notEmpty);

	//�������,����
	pthread_mutex_unlock(&pool->mutexPool);
}

//��ȡæ�̸߳���
int threadPoolBusyNum(ThreadPool* pool)
{
	pthread_mutex_lock(&pool->mutexBusy);
	int busyNum = pool->busyNum;
	pthread_mutex_unlock(&pool->mutexBusy);
	return busyNum;
}

//��ȡ����̸߳���
int threadPoolAliveNum(ThreadPool* pool)
{
	pthread_mutex_lock(&pool->mutexPool);
	int aliveNum = pool->liveNum;
	pthread_mutex_unlock(&pool->mutexPool);
	return aliveNum;
}

//�������߳�(�������߳�)������
void* worker(void* arg)
{
	ThreadPool* pool = (ThreadPool*)arg;

	while (1)
	{
		pthread_mutex_lock(&pool->mutexPool);
		// ��ǰ��������Ƿ�Ϊ��
		while (pool->queueSize == 0 && !pool->shutdown)
		{
			// ���п�,���������߳�
			pthread_cond_wait(&pool->notEmpty, &pool->mutexPool);

			// �ж��ǲ���Ҫ�����߳�
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

		// �ж��̳߳��Ƿ񱻹ر���(���shutdownΪtrue,���߳��Զ��˳�)
		if (pool->shutdown)
		{
			pthread_mutex_unlock(&pool->mutexPool);
			threadExit(pool);
		}

		// �����������ȡ��һ������
		Task task;
		task.function = pool->taskQueue[pool->queueFront].function;
		task.arg = pool->taskQueue[pool->queueFront].arg;
		// �ƶ�ͷָ��
		pool->queueFront = (pool->queueFront + 1) % pool->queueCapacity;
		pool->queueSize--;
		
		//�����������߳�
		pthread_cond_signal(&pool->notFull);
		// ����
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

// �������߳�������
void* manager(void* arg)
{ 
	ThreadPool* pool = (ThreadPool*)arg;
	while (!pool->shutdown)
	{
		// ÿ��3s���һ��
		sleep(3);

		// ȡ���̳߳�������������͵�ǰ�̵߳�����
		pthread_mutex_lock(&pool->mutexPool);
		int queueSize = pool->queueSize;
		int liveNum = pool->liveNum;
		pthread_mutex_unlock(&pool->mutexPool);

		// ȡ��æ���̵߳�����
		pthread_mutex_lock(&pool->mutexBusy);
		int busyNum = pool->busyNum;
		pthread_mutex_unlock(&pool->mutexBusy);

		// ����߳�
		// ����ĸ���>�����̸߳��� && �����߳���<����߳���
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
		// �����߳�
		// æ���߳�*2 < �����߳��� && �����߳�>��С�߳���
		if (busyNum * 2 < liveNum && liveNum > pool->minNum)
		{
			pthread_mutex_lock(&pool->mutexPool);
			pool->exitNum = NUMBER;
			pthread_mutex_unlock(&pool->mutexPool);
			// �ù������߳���ɱ
			for (int i = 0; i < NUMBER; ++i)
			{
				//���ѱ������Ĺ������߳�
				pthread_cond_signal(&pool->notEmpty);
			}
		}
	}
	return NULL;
}

//�����߳��˳��ĺ���
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
