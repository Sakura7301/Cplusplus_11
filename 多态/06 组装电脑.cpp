//#include<iostream>
//using namespace std;
//#include<string>
////CPU��
//class CPU
//{
//public:
//
//	virtual void ALU() = 0;
//};
////�Կ���
//class SeeCard
//{
//public:
//
//	virtual void SEE() = 0;
//};
//
////�ڴ���
//class Memory
//{
//public:
//	virtual void RAM() = 0;
//};
//
////������
//class Computer
//{
//public:
//	Computer(Memory *a,SeeCard *b,CPU *c)//�������������ָ��
//	{
//		m_cpu = c;
//		m_memory = a;
//		m_seecard = b;
//	}
//		//��������
//	void work()
//	{
//		m_cpu->ALU();
//		m_memory->RAM();
//		m_seecard->SEE();
//	}
//	//������
//	~Computer()
//	{
//		if (m_memory != NULL)
//		{
//			delete m_memory;
//			m_memory = NULL;
//			//cout << "memory���ͷ�" << endl;
//		}
//		if (m_seecard != NULL)
//		{
//			delete m_seecard;
//			m_seecard = NULL;
//			//cout << "seecard���ͷ�" << endl;
//
//		}
//		if (m_cpu != NULL)
//		{
//			delete m_cpu;
//			m_cpu = NULL;
//			//cout << "cpu���ͷ�" << endl;
//
//		}
//	}
//private:
//	//�������ָ��
//	CPU *m_cpu;
//	Memory *m_memory;
//	SeeCard *m_seecard;
//};
////intel����
//class intelCPU :public CPU
//{
//public:
//	virtual void ALU()
//	{
//		cout<<"intelCPU��ʼ�����ˣ�" << endl;
//	}
//};
//class intelMemory :public Memory
//{
//	virtual void RAM()
//	{
//		cout << "intel�ڴ濪ʼ�洢�ˣ�" << endl;
//	}
//};
//class intelSeeCard:public SeeCard
//{
//	virtual void SEE()
//	{
//		cout << "intel�Կ���ʼ��ʾ�ˣ�" << endl;
//	}
//
//};
////AMD����
//class AMDCPU :public CPU
//{
//public:
//	virtual void ALU()
//	{
//		cout << "AMDCPU��ʼ�����ˣ�" << endl;
//	}
//};
//class AMDMemory :public Memory
//{
//	virtual void RAM()
//	{
//		cout << "AMD�ڴ濪ʼ�洢�ˣ�" << endl;
//	}
//};
//class AMDSeeCard :public SeeCard
//{
//	virtual void SEE()
//	{
//		cout << "AMD�Կ���ʼ��ʾ�ˣ�" << endl;
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
//	//���������ָ��
//	cout << "<--��ʼ��װ��һ̨����-->" << endl;
//	Computer *computer1 = new Computer(new intelMemory,new intelSeeCard,new intelCPU);
//	computer1->work();
//	cout << "<--��һ̨������װ���-->" << endl;
//	delete computer1;
//	cout << endl;
//
//	cout << "<--��ʼ��װ�ڶ�̨����-->" << endl;
//	Computer *computer2 = new Computer(new AMDMemory, new AMDSeeCard, new AMDCPU);
//	computer2->work();
//	cout << "<--�ڶ�̨������װ���-->" << endl;
//	delete computer2;
//	cout << endl;
//
//	cout << "<--��ʼ��װ����̨����-->" << endl;
//	Computer *computer3 = new Computer(new intelMemory,new AMDSeeCard, new intelCPU);
//	computer3->work();
//	cout << "<--����̨������װ���-->" << endl;
//	delete computer3;
//	cout << endl;
//}
//int main()
//{
//	test01();
//	system("pause");
//	return 0;
//}