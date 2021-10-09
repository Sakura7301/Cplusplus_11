//#include<iostream>
//#include<string>
//using namespace std;
////普通函数
//int  myadd(int a, int b)
//{
//	return a + b;
//}
//
//
//
////模板函数
//template<typename T> int mysub(T a, T b)
//{
//	return a + b;
//}
//void test01()
//{
//	int a = 10;
//	int b = 5;
//	char c = 'a';
//	//普通函数：可以发生隐式转换
//	cout << myadd(a ,c) << endl;
//
//	//模板函数----1----自动推导
//	//cout << mysub(a, c) << endl;
//	//无法发生隐式转换
//
//	//模板函数----2----显示指定
//	cout << mysub<int>(a, c) << endl;
//}
//int main()
//{
//	test01();
//}