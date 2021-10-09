//#include<iostream>
//using namespace std;
//#include<string>
////CPU类
//class CPU
//{
//public:
//
//	virtual void ALU() = 0;
//};
////显卡类
//class SeeCard
//{
//public:
//
//	virtual void SEE() = 0;
//};
//
////内存类
//class Memory
//{
//public:
//	virtual void RAM() = 0;
//};
//
////电脑类
//class Computer
//{
//public:
//	Computer(Memory *a,SeeCard *b,CPU *c)//传入三种零件的指针
//	{
//		m_cpu = c;
//		m_memory = a;
//		m_seecard = b;
//	}
//		//工作函数
//	void work()
//	{
//		m_cpu->ALU();
//		m_memory->RAM();
//		m_seecard->SEE();
//	}
//	//虚析构
//	~Computer()
//	{
//		if (m_memory != NULL)
//		{
//			delete m_memory;
//			m_memory = NULL;
//			//cout << "memory已释放" << endl;
//		}
//		if (m_seecard != NULL)
//		{
//			delete m_seecard;
//			m_seecard = NULL;
//			//cout << "seecard已释放" << endl;
//
//		}
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//			//cout << "cpu已释放" << endl;
//
//		}
//	}
//private:
//	//定义零件指针
//	CPU *m_cpu;
//	Memory *m_memory;
//	SeeCard *m_seecard;
//};
////intel厂商
//class intelCPU :public CPU
//{
//public:
//	virtual void ALU()
//	{
//		cout<<"intelCPU开始计算了！" << endl;
//	}
//};
//class intelMemory :public Memory
//{
//	virtual void RAM()
//	{
//		cout << "intel内存开始存储了！" << endl;
//	}
//};
//class intelSeeCard:public SeeCard
//{
//	virtual void SEE()
//	{
//		cout << "intel显卡开始显示了！" << endl;
//	}
//
//};
////AMD厂商
//class AMDCPU :public CPU
//{
//public:
//	virtual void ALU()
//	{
//		cout << "AMDCPU开始计算了！" << endl;
//	}
//};
//class AMDMemory :public Memory
//{
//	virtual void RAM()
//	{
//		cout << "AMD内存开始存储了！" << endl;
//	}
//};
//class AMDSeeCard :public SeeCard
//{
//	virtual void SEE()
//	{
//		cout << "AMD显卡开始显示了！" << endl;
//	}
//
//};
//void test01()
//{
//	
//	//CPU *intelcpu = new intelCPU;
//	//SeeCard *intelseecard = new intelSeeCard;
//	//Memory *intelmemory = new intelMemory;
//
//	//定义电脑类指针
//	cout << "<--开始组装第一台电脑-->" << endl;
//	Computer *computer1 = new Computer(new intelMemory,new intelSeeCard,new intelCPU);
//	computer1->work();
//	cout << "<--第一台电脑组装完成-->" << endl;
//	delete computer1;
//	cout << endl;
//
//	cout << "<--开始组装第二台电脑-->" << endl;
//	Computer *computer2 = new Computer(new AMDMemory, new AMDSeeCard, new AMDCPU);
//	computer2->work();
//	cout << "<--第二台电脑组装完成-->" << endl;
//	delete computer2;
//	cout << endl;
//
//	cout << "<--开始组装第三台电脑-->" << endl;
//	Computer *computer3 = new Computer(new intelMemory,new AMDSeeCard, new intelCPU);
//	computer3->work();
//	cout << "<--第三台电脑组装完成-->" << endl;
//	delete computer3;
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}