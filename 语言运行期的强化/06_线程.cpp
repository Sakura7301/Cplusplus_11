#if 1

#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<windows.h>
using namespace std;

mutex m_mutex;//互斥锁

void myprint(string words)
{
	m_mutex.lock();
	for (auto i : words)
	{
		Sleep(100);
		cout << i << " ";
	}
	m_mutex.unlock();
}

void myprint2(string words)
{
	while (1)
	{
		if (m_mutex.try_lock())
		{
			for (auto i : words)
			{
				Sleep(100);
				cout << i << " ";
			}
			m_mutex.unlock();
			return;
		}
	}
}

void threadWork()
{
	myprint2("test_01");
}

int main()
{
	thread th_1(threadWork);//thread用于开启一个线程
	thread th_2(myprint2, "test_02");//给线程传参
	thread th_3(myprint2, "test_03");//给线程传参
	th_1.detach();	
	th_2.detach();
	th_3.detach();
	
	//th_1.join();//阻塞等待,直到th_1线程执行完毕


	myprint("all for one!\n");//主线程执行的任务

	/*detach() 的含义是，此线程与 th_1 这个变量毫无关联。
	这时，如果 th_1 变量析构后，不影响子线程的执行。
	并且 detach() 之后,主线程、子线程交替执行，两个线程之间没有先后关系。*/
	return 0;
}





#endif // 1
