///*
//
//[�����б�](�����б�) mutable(��ѡ) �쳣���� -> �������� {
//// ������
//}
//
//*/
//#include <iostream>
//#include <functional>
//using namespace std;
//
///* []�����б� */
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
//	/*������lambda���ʽ����*/
//	auto func1 = [](int a) -> int{return a + 10;};
//	/*���Է���ֵ��lambda���ʽ����*/
//	auto func2 = [](int a){return a + 10;};
//
//	/*��������*/
//	cout << func1(10) << endl;
//	cout << func2(20) << endl;
//
//
//
//	/*��װ�ɵ��ú���*/
//	std::function<int(int)> func3 = [](int a) {return a; };
//	/*�󶨿ɵ��ú���*/
//	std::function<int(int)> func4 = bind([](int a) {return a; }, placeholders::_1);
//
//	/*��������*/
//	cout << func3(100) << endl;
//	cout << func4(200) << endl;
//
//	return 0;
//}