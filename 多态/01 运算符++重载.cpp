//#include<iostream>
//using namespace std;
//#include<string>
//class MyInt
//{
//	friend ostream& operator<<(ostream &cout, MyInt p);//友元声明
//public:
//	MyInt()
//	{
//		m_num = 0;
//	}
//	//前置++
//	MyInt& operator++()
//	{
//		m_num++;
//		return *this;//返回自身（this指向自身）
//	}
//	//后置++
//	MyInt operator++(int)
//	{
//		MyInt temp = *this;
//		m_num++;
//		return temp;//因为返回的是temp,因此，返回值类型为”值“，而非引用
//	}
//	//前置--
//	MyInt& operator--()
//	{
//		m_num--;
//		return *this;//返回自身（this指向自身）
//	}
//	//后置--
//	MyInt operator--(int)
//	{
//		MyInt temp = *this;
//		m_num--;
//		return temp;//因为返回的是temp,因此，返回值类型为”值“，而非引用
//	}
//private:
//	int m_num;
//};
//ostream& operator<<(ostream& cout, MyInt p)
//{
//	cout <<p.m_num;
//	return cout;//返回自身，而cout是输出流（ostream）的一个对象，因此返回值类型为ostream的引用
//}
////打印++
//void test01()
//{
//	MyInt a;
//	cout << "a的值为：\t" << a << endl;
//	cout << "a++的值为：\t" << a++ << endl;
//	cout << "a的值为：\t" << a << endl;
//	cout << "++a的值为：\t" << ++a << endl;
//	cout << "a的值为：\t" << a << endl;
//}
////打印--
//void test02()
//{
//	MyInt b;
//	cout << "b的值为：\t" << b << endl;
//	cout << "b--的值为：\t" << b-- << endl;
//	cout << "b的值为：\t" << b << endl;
//	cout << "--b的值为：\t" << --b << endl;
//	cout << "b的值为：\t" << b << endl;
//}
//
//int main()
//{
//	test01();
//	cout << endl;
//	test02();
//	system("pause");
//	return 0;
//}