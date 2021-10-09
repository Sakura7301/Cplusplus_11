///*
//
//[捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {
//// 函数体
//}
//
//*/
//#include <iostream>
//#include <functional>
//using namespace std;
//
///* []捕获列表 */
//class Test
//{
//public:
//	void output(int x, int y)
//	{
//		/* auto x1 = [] {return m_number; }; */                     // error
//		auto x2 = [=] {return m_number + x + y; };             // ok
//		auto x3 = [&] {return m_number + x + y; };             // ok
//		auto x4 = [this] {return m_number; };                  // ok
//		/* auto x5 = [this] {return m_number + x + y; }; */          // error
//		auto x6 = [this, x, y] {return m_number + x + y; };    // ok
//		auto x7 = [this] {return m_number++; };                // ok
//	}
//	int m_number = 100;
//};
//
//
//int main()
//{
//	/*完整的lambda表达式定义*/
//	auto func1 = [](int a) -> int{return a + 10;};
//	/*忽略返回值的lambda表达式定义*/
//	auto func2 = [](int a){return a + 10;};
//
//	/*函数调用*/
//	cout << func1(10) << endl;
//	cout << func2(20) << endl;
//
//
//
//	/*包装可调用函数*/
//	std::function<int(int)> func3 = [](int a) {return a; };
//	/*绑定可调用函数*/
//	std::function<int(int)> func4 = bind([](int a) {return a; }, placeholders::_1);
//
//	/*函数调用*/
//	cout << func3(100) << endl;
//	cout << func4(200) << endl;
//
//	return 0;
//}