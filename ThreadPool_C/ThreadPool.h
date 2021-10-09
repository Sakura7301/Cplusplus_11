#pragma once
#pragma once
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>

#define NUMBER 2

//任务队列
typedef struct Task Task;

//线程池
typedef struct ThreadPool ThreadPool;

// 创建线程池并初始化
ThreadPool *threadPoolCreate(int min, int max, int queueSize);

// 销毁线程池
int threadPoolDestroy(ThreadPool* pool);

// 给线程池添加任务
void threadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg);

// 获取线程池中工作的线程的个数
int threadPoolBusyNum(ThreadPool* pool);

// 获取线程池中活着的线程的个数
int threadPoolAliveNum(ThreadPool* pool);

// 工作的线程(消费者线程)任务函数
void* worker(void* arg);

// 管理者线程任务函数
void* manager(void* arg);

// 单个线程退出
void threadExit(ThreadPool* pool);