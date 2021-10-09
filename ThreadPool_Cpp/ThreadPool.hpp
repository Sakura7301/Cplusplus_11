#pragma once
#include"TaskQueue.hpp"

template<typename T>
class ThreadPool
{
public:
	ThreadPool(int min, int max);

	~ThreadPool();

	// ���̳߳��������
	void threadPoolAdd(Task<T> task);

	// ��ȡ�̳߳��й������̵߳ĸ���
	int threadPoolBusyNum();

	// ��ȡ�̳߳��л��ŵ��̵߳ĸ���
	int threadPoolAliveNum();

private:
	// �������߳�(�������߳�)������
	static void* worker(void* arg);
	// �������߳�������
	static void* manager(void* arg);
	/*����Ϊ��̬��ԭ����:
	����ú����Ǿ�̬,��ô�ڸö���ʵ����֮ǰ��������ڴ�ռ�;
	���ǵĹ��캯�����޷�ʹ������Ϊ�̵߳Ļص�����;
	���,��������Ϊ��̬,��ʵ����֮ǰ���Ѿ������ڴ�ռ�;
	����һ��,�ڹ��캯������ʱ�Ϳ��Ի�ȡ����ַ��*/

	// �����߳��˳�
	void threadExit();


private:
	TaskQueue<T> *taskQueue;				//�������

	pthread_t managerID;				 // �������߳�ID
	pthread_t *workerIDs;				 // �������߳�ID

	int minNum;							 // ��С�߳�����
	int maxNum;							 // ����߳�����
	int busyNum;						 // æ���̵߳ĸ���
	int liveNum;						 // �����̵߳ĸ���	
	int exitNum;						 // Ҫ���ٵ��̸߳���

	static const int NUMBER = 2;			 //ÿ��Ҫ��ӵ��߳���

	pthread_mutex_t mutexPool;			// ���������̳߳�

	pthread_cond_t notFull;				// ��������:���в�Ϊ��
	//pthread_cond_t notEmpty;			// ����Ҫ�������Ϊ����ʹ����STL����,��˶��в�����λ��

	bool shutdown;						// �Ƿ������̳߳صı��
};




template<typename T>
ThreadPool<T>::ThreadPool(int min, int max)
{
	do
	{
		//��ʼ���������
		taskQueue = new TaskQueue<T>;
		if (taskQueue == nullptr)
		{
			std::cout << "taskQueue init error" << std::endl;
			break;
		}

		//��ʼ�������߳�ID
		workerIDs = new pthread_t[max];
		if (workerIDs == nullptr)
		{
			std::cout << "workerIDs init error" << std::endl;
			break;
		}
		//��ʼ��
		memset(workerIDs, 0, sizeof(pthread_t)*(unsigned int)max);
		minNum = min;
		maxNum = max;
		busyNum = 0;
		liveNum = min;
		exitNum = 0;
		shutdown = false;

		//��ʼ����&��������
		if (pthread_cond_init(&notFull, NULL) != 0 ||
			pthread_mutex_init(&mutexPool, NULL) != 0)
		{
			std::cout << "mutex or cond init error" << std::endl;
			break;
		}

		//�����������߳�
		pthread_create(&managerID, NULL, manager, this);
		/*��̬��Ա�����ڲ�û��thisָ��,�޷����ʷǾ�̬��Ա����
		  �������ǰ�thisָ����Ϊ�������ݹ�ȥ*/

		  //ѭ�������������߳�
		for (int i = 0; i < min; i++)
		{
			pthread_create(&workerIDs[i], NULL, worker, this);
		}
		return;
	} while (0);

	//����ʧ��,��Ҫ�ͷŵ��������Դ
	if (taskQueue) delete taskQueue;
	if (workerIDs) delete[]workerIDs;
	return;
}

template<typename T>
ThreadPool<T>::~ThreadPool()
{
	//�ر��̳߳�
	this->shutdown = true;

	//�������չ������߳�
	pthread_join(this->managerID, NULL);
	//���ѹ������߳�
	for (int i = 0; i < this->liveNum; i++)
	{
		pthread_cond_signal(&this->notFull);
	}

	//�ͷŶ����ڴ�
	if (taskQueue)
	{
		delete taskQueue;
	}
	if (workerIDs)
	{
		delete[]workerIDs;
	}

	//����������������
	pthread_cond_destroy(&notFull);
	pthread_mutex_destroy(&mutexPool);
}


//���̳߳��������
template<typename T>
void ThreadPool<T>::threadPoolAdd(Task<T> task)
{
	if (shutdown)
	{
		return;
	}

	//�ú����ڲ������߳�ͬ������,�������������
	taskQueue->addTask(task);//�������

	//�����߳�
	pthread_cond_signal(&notFull);
}


//��ȡæ�߳�����
template<typename T>
int ThreadPool<T>::threadPoolBusyNum()
{
	pthread_mutex_lock(&mutexPool);
	int ret = this->busyNum;
	pthread_mutex_unlock(&mutexPool);
	return ret;
}

//��ȡ����߳�����
template<typename T>
int ThreadPool<T>::threadPoolAliveNum()
{
	pthread_mutex_lock(&mutexPool);
	int ret = this->liveNum;
	pthread_mutex_unlock(&mutexPool);
	return ret;
}


//�������߳�������
template<typename T>
void * ThreadPool<T>::worker(void * arg)
{
	//ǿ������ת��
	ThreadPool* pool = static_cast<ThreadPool*>(arg);

	//��������
	while (1)
	{
		//����
		pthread_mutex_lock(&pool->mutexPool);

		while (pool->taskQueue->getQueueSize() == 0 && !pool->shutdown)
		{
			//�����������߳�
			pthread_cond_wait(&pool->notFull, &pool->mutexPool);

			//�ж��ǲ���Ҫ�����߳�
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

		//�ж��̳߳��ǲ��ǹر���
		if (pool->shutdown)
		{
			pthread_mutex_unlock(&pool->mutexPool);
			pool->threadExit();
		}

		//���϶�����,��ʾ�̳߳���������
		//ȡ��һ������
		Task<T> task = pool->taskQueue->takeTask();
		pool->busyNum++;
		//ȡ����������
		pthread_mutex_unlock(&pool->mutexPool);

		//��ʼִ������
		std::cout << "thread " << std::to_string(pthread_self()) << " [start] working..." << std::endl;
		task.function(task.arg);
		delete task.arg;
		std::cout << "thread " << std::to_string(pthread_self()) << " [ end ] working..." << std::endl;

		//�������,æ�̸߳���-1
		pthread_mutex_lock(&pool->mutexPool);
		pool->busyNum--;
		pthread_mutex_unlock(&pool->mutexPool);
	}
	return nullptr;
}

//�������߳�������
template<typename T>
void * ThreadPool<T>::manager(void * arg)
{
	//ǿ������ת��
	ThreadPool* pool = static_cast<ThreadPool*>(arg);
	while (!pool->shutdown)
	{
		// ÿ��5s���һ��
		sleep(5);
		// ȡ���̳߳��е����������߳�����
		//  ȡ���������̳߳�����
		long queueSize = pool->taskQueue->getQueueSize();
		int liveNum = pool->liveNum;
		int busyNum = pool->busyNum;


		// ��ǰ�������>�����߳��� && �����߳���<����̸߳���
		if (queueSize > liveNum && liveNum < pool->maxNum)
		{
			// �̳߳ؼ���
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

		// ���ٶ�����߳�
		// æ�߳�*2 < �����߳���Ŀ && �����߳��� > ��С�߳�����
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


//�߳��˳�����
template<typename T>
void ThreadPool<T>::threadExit()
{
	//�ҵ�Ŀ���̲߳�֪ͨ
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
