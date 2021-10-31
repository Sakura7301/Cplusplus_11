#if 1

#include<iostream>
#include<thread>
#include<mutex>
#include<string>
#include<windows.h>
using namespace std;

mutex m_mutex;//������

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
	thread th_1(threadWork);//thread���ڿ���һ���߳�
	thread th_2(myprint2, "test_02");//���̴߳���
	thread th_3(myprint2, "test_03");//���̴߳���
	th_1.detach();	
	th_2.detach();
	th_3.detach();
	
	//th_1.join();//�����ȴ�,ֱ��th_1�߳�ִ�����


	myprint("all for one!\n");//���߳�ִ�е�����

	/*detach() �ĺ����ǣ����߳��� th_1 ����������޹�����
	��ʱ����� th_1 ���������󣬲�Ӱ�����̵߳�ִ�С�
	���� detach() ֮��,���̡߳����߳̽���ִ�У������߳�֮��û���Ⱥ��ϵ��*/
	return 0;
}





#endif // 1
