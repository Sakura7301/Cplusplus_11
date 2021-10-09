#pragma once
#pragma once
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<unistd.h>

#define NUMBER 2

//�������
typedef struct Task Task;

//�̳߳�
typedef struct ThreadPool ThreadPool;

// �����̳߳ز���ʼ��
ThreadPool *threadPoolCreate(int min, int max, int queueSize);

// �����̳߳�
int threadPoolDestroy(ThreadPool* pool);

// ���̳߳��������
void threadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg);

// ��ȡ�̳߳��й������̵߳ĸ���
int threadPoolBusyNum(ThreadPool* pool);

// ��ȡ�̳߳��л��ŵ��̵߳ĸ���
int threadPoolAliveNum(ThreadPool* pool);

// �������߳�(�������߳�)������
void* worker(void* arg);

// �������߳�������
void* manager(void* arg);

// �����߳��˳�
void threadExit(ThreadPool* pool);