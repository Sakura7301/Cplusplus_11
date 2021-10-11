#if 1

/*
[�﷨]:
// �����Ա��/����
auto f = std::bind(�ຯ�� / ��Ա��ַ, ��ʵ�������ַ, �󶨵Ĳ��� / ռλ��);
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
	cout << "-->ָ������" << endl;
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
	cout << "-->����ռλ��" << endl;
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
	cout << "-->����ָ������ռλ��" << endl;
	Test test;
	auto f = bind(&Test::output, &test,12, placeholders::_1);

	/*18����*/
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
		cout << "�ɶ���д" << endl;
	}
	else {
		cout << "ֻ��" << endl;

	}
}

void test_04()
{
	cout << "-->���Ա������" << endl;
	Test test;
	test.num = 250;
	auto f = bind(&Test::num,&test);
	f() = 666;
	rwod(test.num,f());

	/* ��װ�󶨵õ��ķº��� */
	function<int&()> f2 = bind(&Test::num, test);/*ֻ��*/
	function<int&(void)> f3 = f;/*�ɶ���д*/
	f2() = 999;
	rwod(test.num, f2());

	f3() = 333;
	rwod(test.num, f3());
}


int main()
{
	cout << "-->��[���Ա]����/����:" << endl;
	test_01();
	test_02();
	test_03();
	test_04();
	return 0;
}

#endif // 1
