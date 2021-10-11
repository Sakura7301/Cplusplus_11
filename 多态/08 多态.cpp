#if 0


#include<iostream>
using namespace std;


class A {
public:
	A(){}
	~A() {}
	virtual void speak() = 0;
	void test()
	{
		cout << "A_test" << endl;
	}
};

class B:public A {
public:
	B() {
		speak();
	}
	void speak()//��д�麯��
	{
		cout << "B_speak" << endl;
	}
	void test()//��д���麯����ʵ���Ǹ���
	{
		cout << "B_test" << endl;
	}
	~B() {}
};


class C :public A {
public:
	C() {
		speak();
	}
	void speak()//��д�麯��
	{
		cout << "C_speak" << endl;
	}
	void test()//��д���麯����ʵ���Ǹ���
	{
		cout << "C_test" << endl;
	}
	~C() {}
};

class D :public A {
public:
	D(){}
	~D() {}
};

class Test {
public:
	Test(){}
	~Test(){}
	virtual void speak()
	{
		cout << "virtual of Test" << endl;
	}
};

class Test_son :public Test
{

};

class Test_son2 :public Test
{
public:
	void speak()
	{
		cout << "virtual of Test_son2" << endl;
	}
};

int main()
{
	B b;
	b.test();
	C c;
	c.test();
	//D d;  //����Ϊ������,�޷�ʵ��������
	Test test;	//�ǳ��������ʵ��������
	cout << "test size="<<sizeof Test << endl;//���麯��ʱ���СΪ1  ,���麯��ʱ���СΪ4, ��Ϊ�ڲ����麯��ָ��
	Test_son test_son;
	cout << "test_son size=" << sizeof Test_son << endl;//�̳к����麯���Ļ���, �����СҲ��4
	A* a_ptr;
	a_ptr = &b;
	a_ptr->speak();
	a_ptr = &c;
	a_ptr->speak();
	Test* test_ptr;
	test_ptr = &test_son;
	test_ptr->speak();
	Test_son2 test_son2;
	test_ptr = &test_son2;
	test_ptr->speak();
	test_ptr->~Test();
	return 0;
}
#endif // 0