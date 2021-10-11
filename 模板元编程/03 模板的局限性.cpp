#if 0


#include<iostream>
#include<string>
using namespace std;
class Person
{

public:
	int age;
};

template<typename T> bool duibi(T&a, T&b)
{
	if (a==b)
	{
		cout << "调用普通函数。" << endl;
		return true;
	}
	else
	{
		cout << "调用普通函数。" << endl;
		return false;
	}
}

template<> bool duibi(Person &p1, Person &p2)//函数具体化
{
	if (p1.age == p2.age)
	{
		cout << "调用具体化的函数模板。" << endl;
		return true;
	}
	else
	{
		cout << "调用具体化的函数模板。" << endl;
		return false;
	}
}

void test01()
{
	Person p1;
	p1.age = 18;
	Person p2;
	p2.age = 18;
	//cout << "结果为：" << duibi<Person>(p1, p2) << endl;
	duibi(p1, p2);
}


//使用此种方法也可以接收对象
int main()
{
	test01();
}

#endif // 0
