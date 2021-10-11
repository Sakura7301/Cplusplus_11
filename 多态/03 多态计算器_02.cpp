#if 0


#include<iostream>
using namespace std;
#include<string>

//---------------------->>>普通实现

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
		//如果要提供新的运算，需要修改源码
	}
public:
	int m_Num1;
	int m_Num2;
};

void test01()
{
	//普通实现测试
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << " + " << c.m_Num2 << " = " << c.getResult("+") << endl;

	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;

	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}
//由此可见，普通的方式使得代码的维护和扩展变得麻烦，因此我们提倡使用多态

//多态实现
//抽象计算器类
//多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护

//-------------------------->>>多态实现

class jisuanqi				//计算器类
{
public:
	virtual int GetResult()//在父类中声明一个虚函数
	{
		return 0;
	}
	int m_num1;
	int m_num2;
};
class jia :public jisuanqi //加法类
{
public:
	int GetResult()
	{
		return m_num1 + m_num2;
	}
};
class jian :public jisuanqi //减法类
{
public:
	int GetResult()
	{
		return m_num1 - m_num2;
	}
};
class cheng :public jisuanqi //乘法类
{
public:
	int GetResult()
	{
		return m_num1 * m_num2;
	}
};
void test02()
{
	//创建加法计算器

	jisuanqi *jsq;
	jsq = new jia;			//开辟堆区
			//使用指针指向子类对象
	jsq->m_num1 = 8;
	jsq->m_num2 = 8;
	cout << jsq->m_num1 << "+" << jsq->m_num2 << "=" << jsq->GetResult() << endl;
	delete jsq;							//使用结束后需要手动关闭堆区

	//创建减法计算器
	jsq = new jian;			//开辟堆区
			//使用指针指向子类对象
	jsq->m_num1 = 8;
	jsq->m_num2 = 8;
	cout << jsq->m_num1 << "-" << jsq->m_num2 << "=" << jsq->GetResult() << endl;
	delete jsq;							//使用结束后需要手动关闭堆区

	//创建乘法计算器
	jsq = new cheng;			//开辟堆区
			//使用指针指向子类对象
	jsq->m_num1 = 8;
	jsq->m_num2 = 8;
	cout << jsq->m_num1 << "x" << jsq->m_num2 << "=" << jsq->GetResult() << endl;
	delete jsq;							//使用结束后需要手动关闭堆区

}
int main()
{

	test01();//普通实现
	test02();//多态实现
}
#endif // 0