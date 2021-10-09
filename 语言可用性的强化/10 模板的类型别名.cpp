//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//template<typename T, typename U>
//class Test {
//public:
//	T t;
//	U u;
//};
//
///*不合法,因为模板不是类型
//template<typename T>
//typedef Test<vector<T>,U> test_01;
//*/
//
///*合法*/
//template<typename T, typename U>
//using test_01 = Test<vector<T>, U>;
//
//
//int main()
//{
//
//	test_01<int,string> a;
//
//	return 0;
//}