//#include<iostream>
//using namespace std;
//#include<string>
//class MyInt
//{
//	friend ostream& operator<<(ostream &cout, MyInt p);//��Ԫ����
//public:
//	MyInt()
//	{
//		m_num = 0;
//	}
//	//ǰ��++
//	MyInt& operator++()
//	{
//		m_num++;
//		return *this;//��������thisָ������
//	}
//	//����++
//	MyInt operator++(int)
//	{
//		MyInt temp = *this;
//		m_num++;
//		return temp;//��Ϊ���ص���temp,��ˣ�����ֵ����Ϊ��ֵ������������
//	}
//	//ǰ��--
//	MyInt& operator--()
//	{
//		m_num--;
//		return *this;//��������thisָ������
//	}
//	//����--
//	MyInt operator--(int)
//	{
//		MyInt temp = *this;
//		m_num--;
//		return temp;//��Ϊ���ص���temp,��ˣ�����ֵ����Ϊ��ֵ������������
//	}
//private:
//	int m_num;
//};
//ostream& operator<<(ostream& cout, MyInt p)
//{
//	cout <<p.m_num;
//	return cout;//����������cout���������ostream����һ��������˷���ֵ����Ϊostream������
//}
////��ӡ++
//void test01()
//{
//	MyInt a;
//	cout << "a��ֵΪ��\t" << a << endl;
//	cout << "a++��ֵΪ��\t" << a++ << endl;
//	cout << "a��ֵΪ��\t" << a << endl;
//	cout << "++a��ֵΪ��\t" << ++a << endl;
//	cout << "a��ֵΪ��\t" << a << endl;
//}
////��ӡ--
//void test02()
//{
//	MyInt b;
//	cout << "b��ֵΪ��\t" << b << endl;
//	cout << "b--��ֵΪ��\t" << b-- << endl;
//	cout << "b��ֵΪ��\t" << b << endl;
//	cout << "--b��ֵΪ��\t" << --b << endl;
//	cout << "b��ֵΪ��\t" << b << endl;
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