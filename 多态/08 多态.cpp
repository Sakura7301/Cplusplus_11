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
	void speak()//重写虚函数
	{
		cout << "B_speak" << endl;
	}
	void test()//重写非虚函数其实就是覆盖
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
	void speak()//重写虚函数
	{
		cout << "C_speak" << endl;
	}
	void test()//重写非虚函数其实就是覆盖
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
	//D d;  //被视为抽象类,无法实例化对象
	Test test;	//非抽象类可以实例化对象
	cout << "test size="<<sizeof Test << endl;//无虚函数时类大小为1  ,有虚函数时类大小为4, 因为内部有虚函数指针
	Test_son test_son;
	cout << "test_son size=" << sizeof Test_son << endl;//继承含有虚函数的基类, 空类大小也是4
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