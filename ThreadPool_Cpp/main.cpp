#include<pthread.h>
#include<stdio.h>
#include<stdlib.h> 
#include<unistd.h>
#include"ThreadPool.hpp"
void taskFunc(void* arg)
{
	int num = *(int*)arg;
	std::cout << num << std::endl;
	sleep(1);
}

int main()
{
	//以下为线程池测试代码
	// 创建线程池
	ThreadPool<int> *pool = new ThreadPool<int>(3, 10);
	for (int i = 0; i < 200; ++i)
	{
		int* num = new int(i + 100);
		pool->threadPoolAdd(Task<int>(taskFunc, num));
	}

	sleep(30);
	delete pool;
	return 0;
}
