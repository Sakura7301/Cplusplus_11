#if 0

#include<iostream>
#include<functional>
using namespace std;

/*
[����]:
	1.���ɵ��ö����������һ����а󶨳�һ���º���
	2.����Ԫ(��������>1)�Ŀɵ��ö���ת��Ϊ����ŭ�߲���

[�﷨]:
	// �󶨷����Ա����/����
	auto f = std::bind(�ɵ��ö����ַ, �󶨵Ĳ��� / ռλ��);
*/


void func(int x,int y, const function<void(int,int)>& f)
{
	if (x % 2 == 0 && y%3==0)
	{
		/* ���ÿɵ��ö���*/
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
	cout << "-->ָ������" << endl;
	for (int i = 0; i < 10; ++i)
	{
		/*ʹ�ð����󶨿ɵ��ö���ָ������*/
		auto f1 = bind(output_add, i + 100, i + 200);

		/*��Ϊ�Ѿ�ָ������,���Ի��Զ����Դ����ʵ��*/
		func(i, i, f1);
	}
}


void test_02()
{
	cout << "-->����ռλ��" << endl;
	for (int i = 0; i < 10; i++)
	{
		/*ʹ�ð����󶨿ɵ��ö�������ռλ��*/
		auto f2 = bind(output_add, placeholders::_1, placeholders::_2);

		func(i, i, f2);
	}
}


int main(void)
{
	/*�󶨷����Ա����/����*/
	cout << "-->��[�����Ա]����/����:" << endl;
	test_01();
	test_02();
	return 0;
}




#endif
