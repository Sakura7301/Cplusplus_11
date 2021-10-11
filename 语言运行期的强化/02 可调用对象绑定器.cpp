#if 0

#include<iostream>
#include<functional>
using namespace std;

/*
[作用]:
	1.将可调用对象与其参数一起进行绑定成一个仿函数
	2.将多元(参数个数>1)的可调用对象转换为仅绑定怒愤参数

[语法]:
	// 绑定非类成员函数/变量
	auto f = std::bind(可调用对象地址, 绑定的参数 / 占位符);
*/


void func(int x,int y, const function<void(int,int)>& f)
{
	if (x % 2 == 0 && y%3==0)
	{
		/* 调用可调用对象*/
		f(x,y);
	}
}


void output_add(int x,int y)
{
	cout << "x:" << x << "\ty:"
		<< y << "\tx+y:" << x + y << endl;;
}


void test_01()
{
	cout << "-->指定参数" << endl;
	for (int i = 0; i < 10; ++i)
	{
		/*使用绑定器绑定可调用对象并指定参数*/
		auto f1 = bind(output_add, i + 100, i + 200);

		/*因为已经指定参数,所以会自动忽略传入的实参*/
		func(i, i, f1);
	}
}


void test_02()
{
	cout << "-->设置占位符" << endl;
	for (int i = 0; i < 10; i++)
	{
		/*使用绑定器绑定可调用对象并设置占位符*/
		auto f2 = bind(output_add, placeholders::_1, placeholders::_2);

		func(i, i, f2);
	}
}


int main(void)
{
	/*绑定非类成员函数/变量*/
	cout << "-->绑定[非类成员]函数/变量:" << endl;
	test_01();
	test_02();
	return 0;
}




#endif
