#if 1

/*
[语法]:
// 绑定类成员函/变量
auto f = std::bind(类函数 / 成员地址, 类实例对象地址, 绑定的参数 / 占位符);
*/

#include<iostream>
#include<functional>
using namespace std;

class Test
{
public:
	void output(int x, int y)
	{
		cout << "x: " << x << "\ty:" << y << endl;
	}
	int num;
};





void test_01()
{
	cout << "-->指定参数" << endl;
	Test test;
	auto f=bind(&Test::output,&test,300,360);
	f(3,6);

	function<void(int, int)> f2 = f;
	function<void(int, int)> f3 = bind(&Test::output, &test, 300,900);
	f2(3,6);
	f3(3,6);
}

void test_02()
{
	cout << "-->设置占位符" << endl;
	Test test;
	auto f = bind(&Test::output,&test,placeholders::_1,placeholders::_2);
	f(3,6);

	function<void(int, int)> f2 = f;
	function<void(int, int)> f3 = bind(&Test::output, &test, placeholders::_1, placeholders::_2);
	f2(30, 60);
	f3(120, 360);
}

void test_03()
{
	cout << "-->设置指定数量占位符" << endl;
	Test test;
	auto f = bind(&Test::output, &test,12, placeholders::_1);

	/*18被吞*/
	f(3,6);

	function<void(int, int)> f2 = f;
	function<void(int, int)> f3 = bind(&Test::output, &test, 12, placeholders::_1);
	f2(30, 60);
	f3(120, 360);
}

void rwod(int a,int b)
{
	if (a == b)
	{
		cout << "可读可写" << endl;
	}
	else {
		cout << "只读" << endl;

	}
}

void test_04()
{
	cout << "-->类成员变量绑定" << endl;
	Test test;
	test.num = 250;
	auto f = bind(&Test::num,&test);
	f() = 666;
	rwod(test.num,f());

	/* 包装绑定得到的仿函数 */
	function<int&()> f2 = bind(&Test::num, test);/*只读*/
	function<int&(void)> f3 = f;/*可读可写*/
	f2() = 999;
	rwod(test.num, f2());

	f3() = 333;
	rwod(test.num, f3());
}


int main()
{
	cout << "-->绑定[类成员]函数/变量:" << endl;
	test_01();
	test_02();
	test_03();
	test_04();
	return 0;
}

#endif // 1
