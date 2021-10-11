#if 0


#include<iostream>
#include<string>

using namespace std;

int main()
{
	/*右值引用*/
	int&& a = 250;
	/*
	250是一个右值(无法取地址)
	a是一个右值引用
	*/


	/*左值引用*/
	int b = 100;
	int&c = b;
	/*
	b是一个左值(可以取地址)
	c是一个左值引用
	*/


	/*常量左值引用*/
	const int& d = b;
	/*
	b是一个左值(可以取地址)
	引用本身是指针常量(即被const修饰指向的指针)
	而使用const再去修饰引用,则它指向的值也不可以修改;
	d是一个常量左值引用, 既不可以修改指向, 也不可以修改所指向的值
	*/

	/*常量右值引用*/
	const int&& f = 250;
	/*
	无论const是否限定,右值引用都必须使用右值初始化
	*/
	int *s = new int(100);
	int&& g = move(*s);//将s中的资源转移到g
	cout << "g address:" <<&g<< endl;
	cout << "s-> address:" <<s<< endl;
	cout << g << endl;
	delete s;
	cout << "g address:" << &g << endl;
	cout << "s-> address:" << s << endl;
	cout << g << endl;

	int *x = new int(250);
	int *y = move(s);
	cout << *x << endl;
	cout << y << endl;
	cout << "x-> address:" << x << endl;
	cout << "y-> address:" << y << endl;
	system("pause");
	return 0;
	

}
#endif // 0