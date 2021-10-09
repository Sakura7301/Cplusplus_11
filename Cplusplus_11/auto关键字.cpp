//#include<iostream>
//#include <string>
//using namespace std;
//
///*
//推导方向:
//		<--------
//		auto=3.14;
//*/
//
////void test_01()
////{
////	/*定义变量*/
////	auto a = 3.14;
////	auto b = 2;
////	auto c = 'c';
////	//auto d;//错误,未初始化
////	//auto int nb1;//error
////	int temp = 110;
////
////	/*指针*/
////	auto* a = &temp;
////	auto b = &temp;
////
////	/*引用*/
////	auto& c = temp;
////	/*简单赋值*/
////	auto d = temp;
////
////	/*有const修饰*/
////	int temp2 = 250;
////	//const int 类型
////	const auto a1 = temp2;
////	
////	//const a2并不是是const int类型(忽略了const)
////	auto a2 = a1;
////
////	//const int&
////	const auto& a3 = temp2;
////	auto a4 = a3;
////	auto &a5 = a3;
////	auto* a6 = &a3;
////	/*规则: 当变量是指针或引用时会保留const volatile
////			不是指针或引用则忽略const volatile
////	*/
////}
//
///*不推荐使用auto的场景:
//1>不能用于函数参数
////error
//int func(auto a,auto b){
//	return a+b;
//}
//
//2>不能用于类的非静态成员变量初始化
//class test{
//auto id=0;//error
//static auto id2=0;error
//static const auto id2=0;ok
//}
//
//3>不能使用auto定义数组
//int array[] = {1,2,3,4,5};//定义数组
//auto t1 = array;// ok，t1被推导为int*类型
//auto t2[] = array;// error，auto无法定义数组
//auto t3[] = {1,2,3,4,5};;l // error, auto无法定义数组
//
//4>无法使用auto推导模板参数
//template <typname t>
//struct test{}
//int func(){
//test<double> t;
//test<auto> t1=t;//error
//}
//
//*/
//
//
///*推荐使用的场景:
//
//1>stl容器的遍历
//
//2>泛型编程
//
//*/
//
//class a {
//public:
//	static int get()
//	{
//		return 250;
//	}
//};
//
//class b {
//public:
//	static string get()
//	{
//		return "helloworld";
//	}
//};
//
////函数模板
//template <class t>
//void func(void)
//{
//	auto ret = t::get();
//	cout << "ret:" << ret << endl;
//	return;
//}
//
//
//int main()
//{
//	//test_01();
//
//	func<a>();
//	func<b>();
//
//	return 0;
//}