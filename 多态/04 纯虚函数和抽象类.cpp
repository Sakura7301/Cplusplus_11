//#include<iostream>
//using namespace std;
//#include<string>
////���� AR
//class AR
//{
//public:
//	virtual void more() = 0;//����Ϊ���麯��
//};
////���� reboot
//class reboot :public AR
//{
//public:
//	void more()//���������д����Ĵ��麯���������޷�ʵ����
//	{
//		cout << "ar.more()����" << endl;
//	}
//};
////��̬ʵ�ֵķ���
//void test01() 
//{
//	cout << "test01��ʵ��" << endl;
//	AR *abc;
//	abc = new reboot;
//	abc->more();
//	delete abc;
//}
//void test02(AR *asd)
//{
//	cout << "test02��ʵ��" << endl;
//	asd->more();
//	delete asd;
//}
//void test03(AR &pdf)
//{
//	cout << "test03��ʵ��" << endl;
//	pdf.more();
//}
//
////���ú���
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