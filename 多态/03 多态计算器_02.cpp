#if 0


#include<iostream>
using namespace std;
#include<string>

//---------------------->>>��ͨʵ��

class Calculator {
public:
	int getResult(string oper)
	{
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}
		else if (oper == "-") {
			return m_Num1 - m_Num2;
		}
		else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
	}
public:
	int m_Num1;
	int m_Num2;
};

void test01()
{
	//��ͨʵ�ֲ���
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}
//�ɴ˿ɼ�����ͨ�ķ�ʽʹ�ô����ά������չ����鷳����������ᳫʹ�ö�̬

//��̬ʵ��
//�����������
//��̬�ŵ㣺������֯�ṹ�������ɶ���ǿ������ǰ�ںͺ��ڵ���չ�Լ�ά��

//-------------------------->>>��̬ʵ��

class jisuanqi				//��������
{
public:
	virtual int GetResult()//�ڸ���������һ���麯��
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
class jia :public jisuanqi //�ӷ���
{
public:
	int GetResult()
	{
		return m_num1 + m_num2;
	}
};
class jian :public jisuanqi //������
{
public:
	int GetResult()
	{
		return m_num1 - m_num2;
	}
};
class cheng :public jisuanqi //�˷���
{
public:
	int GetResult()
	{
		return m_num1 * m_num2;
	}
};
void test02()
{
	//�����ӷ�������

	jisuanqi *jsq;
	jsq = new jia;			//���ٶ���
			//ʹ��ָ��ָ���������
	jsq->m_num1 = 8;
	jsq->m_num2 = 8;
	cout << jsq->m_num1 << "+" << jsq->m_num2 << "=" << jsq->GetResult() << endl;
	delete jsq;							//ʹ�ý�������Ҫ�ֶ��رն���

	//��������������
	jsq = new jian;			//���ٶ���
			//ʹ��ָ��ָ���������
	jsq->m_num1 = 8;
	jsq->m_num2 = 8;
	cout << jsq->m_num1 << "-" << jsq->m_num2 << "=" << jsq->GetResult() << endl;
	delete jsq;							//ʹ�ý�������Ҫ�ֶ��رն���

	//�����˷�������
	jsq = new cheng;			//���ٶ���
			//ʹ��ָ��ָ���������
	jsq->m_num1 = 8;
	jsq->m_num2 = 8;
	cout << jsq->m_num1 << "x" << jsq->m_num2 << "=" << jsq->GetResult() << endl;
	delete jsq;							//ʹ�ý�������Ҫ�ֶ��رն���

}
int main()
{

	test01();//��ͨʵ��
	test02();//��̬ʵ��
}
#endif // 0