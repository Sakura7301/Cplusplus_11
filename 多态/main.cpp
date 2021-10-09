#include"Base.h"
#include"class_info.h"
#include"Derived.h"
#include<string>
using namespace std;

void test_single_inherit_norewrite()
{
	Derived d(9999);

	cout << "对象d的起始内存地址：" << &d << endl;

	//获取类型信息
	cout << "type_info信息的地址:" << ((int*)*(int*)(&d) - 1) << endl; //cout得到一个地址，就输出这个地址里存放的内容
	RTTICompleteObjectLocator str = *((RTTICompleteObjectLocator*)*((int*)*(int*)(&d) - 1));
	string classname(str.pTypeDescriptor->name);
	cout <<"classname"<<classname << endl;

	//获取虚函数信息

	cout << "虚函数表地址：" << (int*)(&d) << endl;
	cout << "虚函数表中第1个函数占位符的地址：" << (int*)*(int*)(&d) << "即析构函数在虚函数表中占位符的地址" << endl;
	cout << "虚函数表中第2个函数占位符的地址：" << ((int*)*(int*)(&d) + 1) << endl;
	typedef void(*Fun)(void);
	Fun pFun = (Fun)*((int*)*(int*)(&d) + 1);
	pFun();
	d.print();
	cout << endl;

	cout << "虚函数表中第3个函数占位符的地址：" << ((int*)*(int*)(&d) + 2) << endl;
	pFun = (Fun)*((int*)*(int*)(&d) + 2);
	pFun();
	d.derived_print();
	cout << endl;

	//获取成员变量的信息
	cout << "推测成员变量iBase的地址：" << (int*)(&d) + 1 << endl;
	cout << "通过地址取得的iBase的值：" << *((int*)(&d) + 1) << endl;

	cout << "推测成员变量iDerived地址：" << (int*)(&d) + 2 << endl;
	cout << "通过地址取得的iDerived的值：" << *((int*)(&d) + 2) << endl;

}

int main()
{
	test_single_inherit_norewrite();
	system("pause");
	return 0;
}