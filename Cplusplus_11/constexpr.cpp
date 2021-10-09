//
///*C++ 本身已经具备了常量表达式的概念，
//比如 1+2, 3*4 这种表达式总是会产生相同的结果并
//且没有任何副作用。如果编译器能够在编译时就把这
//些表达式直接优化并植入到程序运行时，将能增加程
//序的性能。一个非常明显的例子就是在数组的定义阶段：*/
//
//#include <iostream>
//#include<string>
//#define LEN 10
//using namespace std;
//
///*
//constexpr class Test {
//public:
//	int id;
//	string name;
//};
//这样的声明是无效的
//我们应该将constexpr用在实例化对象时
//eg:  constexpr Test test();//合法
//*/
//
//class Test {
//public:
//	Test()
//	{
//		this->id = 0;
//		this->name = nullptr;
//	}
//	 Test(int id,char* name)
//	{
//		this->id = id;
//		this->name = name;
//	}
//	int id;
//	char* name;
//};
//
//
//
//int len_foo() {
//	int i = 2;
//	return i;
//}
//
////constexpr可以修饰函数
//constexpr int len_foo_constexpr() {
//	return 5;
//}
//
////constexpr可以修饰递归函数
//constexpr int fibonacci(const int n) {
//	return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
//}
//
//int main() {
//	char arr_1[10];                      // 合法
//	char arr_2[LEN];                     // 合法
//
//	int len = 10;
//	// char arr_3[len];                  // 非法
//
//	const int len_2 = len + 1;
//
//	//constexpr修饰后,len_2_constexpr被视为一个常量
//	constexpr int len_2_constexpr = 1 + 2 + 3;
//	// char arr_4[len_2];                // 非法
//	/*非法是因为C++11中数组的长度必须是常量表达式*/
//	char arr_4[len_2_constexpr];         // 合法
//
//	// char arr_5[len_foo()+5];          // 非法
//	char arr_6[len_foo_constexpr() + 1]; // 合法
//	/*推荐使用这种方式来在将计算放在编译期间*/
//
//	cout << fibonacci(20) << endl;
//	// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
//	cout << fibonacci(10) << endl;
//
//	constexpr Test test_01();//合法
//
//
//	return 0;
//}