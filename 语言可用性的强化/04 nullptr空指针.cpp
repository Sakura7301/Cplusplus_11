//#include<iostream>
//using namespace std;
//void foo(char*a) {
//	cout<<"foo(char*a) is called"<<endl;
//	return;
//}
//void foo(int a) {
//	cout << "foo(int a) is called" << endl;
//	return;
//}
//int main()
//{
//	//char* ch = NULL;
//	//cout <<"ch="<< ch << endl;//运行时报错
//	//void* ch2 = NULL;
//	//cout << "ch2="<<ch2 << endl;
//
//
//	/*对于指针类型,我们应当初始化为nullptr*/
//	/*
//	本质上NULL宏定义为0,而C++是强类型的语言
//	NULL几乎可以给任意变量赋值,这破坏了重载的特性
//	如下:
//	*/
//	foo(NULL);//这个语句将会去调用 foo(int a)，从而导致代码违反直觉。
//	foo(nullptr);//符合直觉,调用了foo(char* a)
//	system("pause");
//	return 0;
//}