//#include<iostream>
//#include<string>
//using namespace std;
//#include <vector>	//����������ͷ�ļ�
//#include<map>
//#include<ctime>
//#define MEISHU 1
//#define CEHUA 2
//#define YANFA 3
//
//class Worker//Ա����
//{
//public:
//	string m_name;
//	int m_wage;
//};
//
//void CreateWorker(vector<Worker>&v)//����Ա��
//{
//	string nameSeed = "ABCDEFGHIJKLMNO";
//	for (int i = 0; i < 15; i++)
//	{
//		Worker worker;
//		worker.m_name = "  Ա��";
//		worker.m_name += nameSeed[i];
//		worker.m_wage = rand() % 1000 + 1000;
//		v.push_back(worker);
//	}
//
//}
//
//void GroupWorker(vector<Worker>&v, multimap<int, Worker>&m)//Ա������
//{
//	//1  �߻�
//	//2  ����
//	//3  �з�
//	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
//	{
//		int detID = rand() % 3 + 1;
//		m.insert(make_pair(detID,(*it)));
//	}
//}
//
//void DisplayWorker(multimap<int, Worker>&m)
//{
//	cout << "-------------------------" << endl;
//	cout << "�߻����ţ�" << endl;
//	multimap<int, Worker>::iterator pos = m.find(CEHUA);//���ҵ�һ���߻����ŵ�Ա��
//	int count = m.count(CEHUA);//ͳ������
//	int index = 0;
//	for (; pos != m.end(),index<count ; pos++, index++)
//	{
//		cout << pos->second.m_name << "  ���ʣ�" << pos->second.m_wage << endl;
//	}
//	cout << "-------------------------" << endl;
//	cout << "�������ţ�" << endl;
//	pos = m.find(MEISHU);
//	count = m.count(MEISHU);
//	index = 0;
//	for (; pos != m.end(), index < count; pos++, index++)
//	{
//		cout << pos->second.m_name << "  ���ʣ�" << pos->second.m_wage << endl;
//	}
//	cout << "-------------------------" << endl;
//	cout << "�з����ţ�" << endl;
//	pos = m.find(YANFA);
//	count = m.count(YANFA);
//	index = 0;
//	for (; pos != m.end(), index < count; pos++, index++)
//	{
//		cout << pos->second.m_name << "  ���ʣ�" << pos->second.m_wage << endl;
//	}
//	cout << "-------------------------" << endl;
//}
//int main()
//{
//	srand((unsigned int)time(NULL));//�����
//
//	//1������Ա��
//	vector<Worker> vWorker;
//	CreateWorker(vWorker);
//	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
//	//{
//	//	cout << it->m_name<< "    ���ʣ� " << it->m_wage << endl;
//	//}
//
//	//2��Ա������
//	multimap<int, Worker>mWorker;//����multmap����
//	      //first,second
//	GroupWorker(vWorker, mWorker);
//
//	//3��������ʾԱ��
//	DisplayWorker(mWorker);
//}
