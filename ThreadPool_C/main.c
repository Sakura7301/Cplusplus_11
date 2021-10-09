#include"ThreadPool.h"
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void taskFunc(void* arg)
{
	int num = *(int*)arg;
	printf("thread %ld is working, number = %d\n",
		pthread_self(), num);
	sleep(1);
}

int main()
{
	//����Ϊ�̳߳ز��Դ���
	// �����̳߳�
	ThreadPool* pool = threadPoolCreate(3, 10, 100);
	for (int i = 0; i < 200; ++i)
	{
		int* num = (int*)malloc(sizeof(int));
		*num = i + 100;
		threadPoolAdd(pool, taskFunc, num);
	}

	sleep(30);

	threadPoolDestroy(pool);
	return 0;
}
