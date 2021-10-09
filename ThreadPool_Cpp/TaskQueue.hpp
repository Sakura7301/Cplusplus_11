#pragma once
#include<queue>
#include<iostream>
#include<pthread.h>
#include<string.h>
#include<string>
#include<unistd.h>
using callBack = void(*)(void* arg);

//任务类
template<typename T>
struct Task {
	Task<T>() {
		function = nullptr;
		arg = nullptr;
	}
	Task(callBack function, void* arg) {
		this->function = function;
		this->arg = static_cast<T*>(arg);
	}
	callBack function;
	T* arg;
};

template<typename T>
class TaskQueue
{
public:
	TaskQueue();
	~TaskQueue();
	//添加任务
	void addTask(Task<T>& task);
	void addTask(callBack function, void* arg);
	//取出任务
	Task<T> takeTask();
	//获取任务个数
	inline long getQueueSize() {
		return m_taskQueue.size();
	}
private:
	std::queue<Task<T>> m_taskQueue;
	pthread_mutex_t m_mutex;
};


template<typename T>
TaskQueue<T>::TaskQueue()
{
	pthread_mutex_init(&m_mutex, NULL);
}

template<typename T>
TaskQueue<T>::~TaskQueue()
{
	pthread_mutex_destroy(&m_mutex);
}

//添加任务
template<typename T>
void TaskQueue<T>::addTask(Task<T>& task)
{
	pthread_mutex_lock(&m_mutex);
	m_taskQueue.push(task);
	pthread_mutex_unlock(&m_mutex);
}

//添加任务,重载
template<typename T>
void TaskQueue<T>::addTask(callBack function, void * arg)
{
	pthread_mutex_lock(&m_mutex);
	m_taskQueue.push(Task<T>(function, arg));
	//Task<T> task;
	//task.function = function;
	//task.arg = arg;
	//m_taskQueue.push(task);
	pthread_mutex_unlock(&m_mutex);
}

//取出任务
template<typename T>
Task<T> TaskQueue<T>::takeTask()
{
	Task<T> t;
	pthread_mutex_lock(&m_mutex);
	if (!m_taskQueue.empty()) {
		t = m_taskQueue.front();
		m_taskQueue.pop();
	}
	pthread_mutex_unlock(&m_mutex);
	return t;
}