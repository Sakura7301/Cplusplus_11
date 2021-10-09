//#include<iostream>
//using namespace std;
//#include<string>
////父类 AR
//class AR
//{
//public:
//	virtual void more() = 0;//定义为纯虚函数
//};
////子类 reboot
//class reboot :public AR
//{
//public:
//	void more()//子类必须重写父类的纯虚函数，否则无法实例化
//	{
//		cout << "ar.more()调用" << endl;
//	}
//};
////多态实现的方法
//void test01() 
//{
//	cout << "test01的实现" << endl;
//	AR *abc;
//	abc = new reboot;
//	abc->more();
//	delete abc;
//}
//void test02(AR *asd)
//{
//	cout << "test02的实现" << endl;
//	asd->more();
//	delete asd;
//}
//void test03(AR &pdf)
//{
//	cout << "test03的实现" << endl;
//	pdf.more();
//}
//
////调用函数
//void shixian()
//{
//	test01();
//	test02(new reboot);
//	reboot pdf;
//	test03(pdf);
//}
//int main()
//{
//	shixian();
//}