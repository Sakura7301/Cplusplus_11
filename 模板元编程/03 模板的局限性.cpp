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
		cout << "������ͨ������" << endl;
		return true;
	}
	else
	{
		cout << "������ͨ������" << endl;
		return false;
	}
}

template<> bool duibi(Person &p1, Person &p2)//�������廯
{
	if (p1.age == p2.age)
	{
		cout << "���þ��廯�ĺ���ģ�塣" << endl;
		return true;
	}
	else
	{
		cout << "���þ��廯�ĺ���ģ�塣" << endl;
		return false;
	}
}

void test01()
{
	Person p1;
	p1.age = 18;
	Person p2;
	p2.age = 18;
	//cout << "���Ϊ��" << duibi<Person>(p1, p2) << endl;
	duibi(p1, p2);
}


//ʹ�ô��ַ���Ҳ���Խ��ն���
int main()
{
	test01();
}

#endif // 0
