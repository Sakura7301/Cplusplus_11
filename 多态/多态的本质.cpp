//#include<iostream>
//#include<memory>
//
//using namespace std;
//class Father;
//typedef void(*callback)(void* arg);
//
//
//
//class Father
//{
//public:
//	Father() {}
//	void first() 
//	{
//		cout << "Father first called." << endl;
//	}
//	virtual callback second() 
//	{
//		return (callback)&first;
//	}
//	void run()
//	{
//		func = second();
//		func(nullptr);
//	}
//	~Father() {}
//public:
//	callback func;
//
//};
//
//class boy :public Father
//{
//public:
//	void first()
//	{
//		cout << "boy first called" << endl;
//	}
//	virtual callback second()
//	{
//		return (callback)&first;
//	}
//};
//
//class girl :public Father
//{
//
//};
//
///*两个基本条件:
//(1) 存在继承关系
//(2) 虚函数在子类重写
//*/
//
//void test_01()
//{
//	cout << "asdasd" << endl;
//}
//
//int main()
//{
//	Father* fptr_1 = new boy();
//	fptr_1->run();
//	fptr_1 = new girl();
//	fptr_1->run();
//	delete fptr_1;
//
//	shared_ptr<int> s1(new int(10));
//	shared_ptr<int> s2 = s1;
//	cout << *s1 << endl;
//	cout << *s2 << endl;
//	
//	cout << s1.use_count() << endl;
//	cout << s2.use_count() << endl;
//	s1 = nullptr;
//	cout << s2.use_count() << endl;
//	s2 = nullptr;
//	cout << s2.use_count() << endl;
//
//
//	system("pause");
//	return 0;
//
//}