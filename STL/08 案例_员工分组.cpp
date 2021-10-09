//#include<iostream>
//#include<string>
//using namespace std;
//#include <vector>	//容器包含的头文件
//#include<map>
//#include<ctime>
//#define MEISHU 1
//#define CEHUA 2
//#define YANFA 3
//
//class Worker//员工类
//{
//public:
//	string m_name;
//	int m_wage;
//};
//
//void CreateWorker(vector<Worker>&v)//创建员工
//{
//	string nameSeed = "ABCDEFGHIJKLMNO";
//	for (int i = 0; i < 15; i++)
//	{
//		Worker worker;
//		worker.m_name = "  员工";
//		worker.m_name += nameSeed[i];
//		worker.m_wage = rand() % 1000 + 1000;
//		v.push_back(worker);
//	}
//
//}
//
//void GroupWorker(vector<Worker>&v, multimap<int, Worker>&m)//员工分组
//{
//	//1  策划
//	//2  美术
//	//3  研发
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
//	cout << "策划部门：" << endl;
//	multimap<int, Worker>::iterator pos = m.find(CEHUA);//查找第一个策划部门的员工
//	int count = m.count(CEHUA);//统计人数
//	int index = 0;
//	for (; pos != m.end(),index<count ; pos++, index++)
//	{
//		cout << pos->second.m_name << "  工资：" << pos->second.m_wage << endl;
//	}
//	cout << "-------------------------" << endl;
//	cout << "美术部门：" << endl;
//	pos = m.find(MEISHU);
//	count = m.count(MEISHU);
//	index = 0;
//	for (; pos != m.end(), index < count; pos++, index++)
//	{
//		cout << pos->second.m_name << "  工资：" << pos->second.m_wage << endl;
//	}
//	cout << "-------------------------" << endl;
//	cout << "研发部门：" << endl;
//	pos = m.find(YANFA);
//	count = m.count(YANFA);
//	index = 0;
//	for (; pos != m.end(), index < count; pos++, index++)
//	{
//		cout << pos->second.m_name << "  工资：" << pos->second.m_wage << endl;
//	}
//	cout << "-------------------------" << endl;
//}
//int main()
//{
//	srand((unsigned int)time(NULL));//随机数
//
//	//1、创建员工
//	vector<Worker> vWorker;
//	CreateWorker(vWorker);
//	//for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
//	//{
//	//	cout << it->m_name<< "    工资： " << it->m_wage << endl;
//	//}
//
//	//2、员工分组
//	multimap<int, Worker>mWorker;//创建multmap容器
//	      //first,second
//	GroupWorker(vWorker, mWorker);
//
//	//3、分组显示员工
//	DisplayWorker(mWorker);
//}
