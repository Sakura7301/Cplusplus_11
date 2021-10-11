#if 0

#include<iostream>
#include<functional>

using std::cout;
using std::endl;
using std::function;

/*
首先,需要理解,什么是可调用对象
可以是:
1> 函数指针
2> 具有operator()成员函数的类对象（仿函数）
3> 可被转换为函数指针的类对象
4> 类成员函数指针或者类成员指针
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
	//构造函数是一个包装器对象
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
	//提供仿函数
	void operator()()
	{
		cout << "Helloworld!" << endl;
	}
};



void test01()
{
	// 绑定一个普通函数
	function<int(int, int)> f1 = add;

	// 绑定以静态类成员函数(注意作用域)
	function<int(int, int)> f2 = T1::sub;

	// 绑定一个仿函数
	T2 t;
	function<int(int, int)> f3 = t;

	// 函数调用
	f1(9, 3);
	f2(9, 3);
	f3(9, 3);
}


//作为回调函数使用
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
结论:
std::function 可以将可调用对象进行包装，
得到一个统一的格式，包装完成得到的对象相当于一个函数指针，
和函数指针的使用方式相同，通过包装器对象就可以完成对包装的函数的调用了。
*/

#endif