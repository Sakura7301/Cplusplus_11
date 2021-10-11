#if 0

#include<iostream>
#include<functional>

using std::cout;
using std::endl;
using std::function;

/*
����,��Ҫ���,ʲô�ǿɵ��ö���
������:
1> ����ָ��
2> ����operator()��Ա����������󣨷º�����
3> �ɱ�ת��Ϊ����ָ��������
4> ���Ա����ָ��������Աָ��
*/



int add(int a, int b)
{
	cout << a << " + " << b << " = " << a + b << endl;
	return a + b;
}

class T1
{
public:
	static int sub(int a, int b)
	{
		cout << a << " - " << b << " = " << a - b << endl;
		return a - b;
	}
};

class T2
{
public:
	int operator()(int a, int b)
	{
		cout << a << " * " << b << " = " << a * b << endl;
		return a * b;
	}
};

class A
{
public:
	A() {}
	//���캯����һ����װ������
	A(const function<void()>&f):callback(f)
	{
		
	}

	void called()
	{
		callback();
	}

private:
	function<void()> callback;
};

class B
{
public:
	//�ṩ�º���
	void operator()()
	{
		cout << "Helloworld!" << endl;
	}
};



void test01()
{
	// ��һ����ͨ����
	function<int(int, int)> f1 = add;

	// ���Ծ�̬���Ա����(ע��������)
	function<int(int, int)> f2 = T1::sub;

	// ��һ���º���
	T2 t;
	function<int(int, int)> f3 = t;

	// ��������
	f1(9, 3);
	f2(9, 3);
	f3(9, 3);
}


//��Ϊ�ص�����ʹ��
void test02()
{
	B b;
	A a(b);
	a.called();

}


int main(void)
{
	test01();
	test02();
	return 0;
}


/*
����:
std::function ���Խ��ɵ��ö�����а�װ��
�õ�һ��ͳһ�ĸ�ʽ����װ��ɵõ��Ķ����൱��һ������ָ�룬
�ͺ���ָ���ʹ�÷�ʽ��ͬ��ͨ����װ������Ϳ�����ɶ԰�װ�ĺ����ĵ����ˡ�
*/

#endif