//#include<iostream>
//#include <string>
//using namespace std;
//
///*
//�Ƶ�����:
//		<--------
//		auto=3.14;
//*/
//
////void test_01()
////{
////	/*�������*/
////	auto a = 3.14;
////	auto b = 2;
////	auto c = 'c';
////	//auto d;//����,δ��ʼ��
////	//auto int nb1;//error
////	int temp = 110;
////
////	/*ָ��*/
////	auto* a = &temp;
////	auto b = &temp;
////
////	/*����*/
////	auto& c = temp;
////	/*�򵥸�ֵ*/
////	auto d = temp;
////
////	/*��const����*/
////	int temp2 = 250;
////	//const int ����
////	const auto a1 = temp2;
////	
////	//const a2��������const int����(������const)
////	auto a2 = a1;
////
////	//const int&
////	const auto& a3 = temp2;
////	auto a4 = a3;
////	auto &a5 = a3;
////	auto* a6 = &a3;
////	/*����: ��������ָ�������ʱ�ᱣ��const volatile
////			����ָ������������const volatile
////	*/
////}
//
///*���Ƽ�ʹ��auto�ĳ���:
//1>�������ں�������
////error
//int func(auto a,auto b){
//	return a+b;
//}
//
//2>����������ķǾ�̬��Ա������ʼ��
//class test{
//auto id=0;//error
//static auto id2=0;error
//static const auto id2=0;ok
//}
//
//3>����ʹ��auto��������
//int array[] = {1,2,3,4,5};//��������
//auto t1 = array;// ok��t1���Ƶ�Ϊint*����
//auto t2[] = array;// error��auto�޷���������
//auto t3[] = {1,2,3,4,5};;l // error, auto�޷���������
//
//4>�޷�ʹ��auto�Ƶ�ģ�����
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
///*�Ƽ�ʹ�õĳ���:
//
//1>stl�����ı���
//
//2>���ͱ��
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
////����ģ��
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