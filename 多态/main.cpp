#include"Base.h"
#include"class_info.h"
#include"Derived.h"
#include<string>
using namespace std;

void test_single_inherit_norewrite()
{
	Derived d(9999);

	cout << "����d����ʼ�ڴ��ַ��" << &d << endl;

	//��ȡ������Ϣ
	cout << "type_info��Ϣ�ĵ�ַ:" << ((int*)*(int*)(&d) - 1) << endl; //cout�õ�һ����ַ������������ַ���ŵ�����
	RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&d) - 1));
	string classname(str.pTypeDescriptor->name);
	cout <<"classname"<<classname << endl;

	//��ȡ�麯����Ϣ

	cout << "�麯�����ַ��" << (int*)(&d) << endl;
	cout << "�麯�����е�1������ռλ���ĵ�ַ��" << (int*)*(int*)(&d) << "�������������麯������ռλ���ĵ�ַ" << endl;
	cout << "�麯�����е�2������ռλ���ĵ�ַ��" << ((int*)*(int*)(&d) + 1) << endl;
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*((int*)*(int*)(&d) + 1);
	pFun();
	d.print();
	cout << endl;

	cout << "�麯�����е�3������ռλ���ĵ�ַ��" << ((int*)*(int*)(&d) + 2) << endl;
	pFun = (Fun)*((int*)*(int*)(&d) + 2);
	pFun();
	d.derived_print();
	cout << endl;

	//��ȡ��Ա��������Ϣ
	cout << "�Ʋ��Ա����iBase�ĵ�ַ��" << (int*)(&d) + 1 << endl;
	cout << "ͨ����ַȡ�õ�iBase��ֵ��" << *((int*)(&d) + 1) << endl;

	cout << "�Ʋ��Ա����iDerived��ַ��" << (int*)(&d) + 2 << endl;
	cout << "ͨ����ַȡ�õ�iDerived��ֵ��" << *((int*)(&d) + 2) << endl;

}

int main()
{
	test_single_inherit_norewrite();
	system("pause");
	return 0;
}