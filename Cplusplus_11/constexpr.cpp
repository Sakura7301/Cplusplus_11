//
///*C++ �����Ѿ��߱��˳������ʽ�ĸ��
//���� 1+2, 3*4 ���ֱ��ʽ���ǻ������ͬ�Ľ����
//��û���κθ����á�����������ܹ��ڱ���ʱ�Ͱ���
//Щ���ʽֱ���Ż���ֲ�뵽��������ʱ���������ӳ�
//������ܡ�һ���ǳ����Ե����Ӿ���������Ķ���׶Σ�*/
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
//��������������Ч��
//����Ӧ�ý�constexpr����ʵ��������ʱ
//eg:  constexpr Test test();//�Ϸ�
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
////constexpr�������κ���
//constexpr int len_foo_constexpr() {
//	return 5;
//}
//
////constexpr�������εݹ麯��
//constexpr int fibonacci(const int n) {
//	return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
//}
//
//int main() {
//	char arr_1[10];                      // �Ϸ�
//	char arr_2[LEN];                     // �Ϸ�
//
//	int len = 10;
//	// char arr_3[len];                  // �Ƿ�
//
//	const int len_2 = len + 1;
//
//	//constexpr���κ�,len_2_constexpr����Ϊһ������
//	constexpr int len_2_constexpr = 1 + 2 + 3;
//	// char arr_4[len_2];                // �Ƿ�
//	/*�Ƿ�����ΪC++11������ĳ��ȱ����ǳ������ʽ*/
//	char arr_4[len_2_constexpr];         // �Ϸ�
//
//	// char arr_5[len_foo()+5];          // �Ƿ�
//	char arr_6[len_foo_constexpr() + 1]; // �Ϸ�
//	/*�Ƽ�ʹ�����ַ�ʽ���ڽ�������ڱ����ڼ�*/
//
//	cout << fibonacci(20) << endl;
//	// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
//	cout << fibonacci(10) << endl;
//
//	constexpr Test test_01();//�Ϸ�
//
//
//	return 0;
//}