#include"类模板数组封装.hpp"
#include <string>
#include <iostream>
using namespace std;
void PrintArray(Array<int>& arr)
{
	for (int i = 0; i <arr.getSize(); i++)
	{
		cout << arr[i] <<"  " ;
	}
	cout << endl;
}
//测试内置数据类型
void test01()
{
	Array<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1打印输出：" << endl;
	PrintArray(array1);
	cout << "array1的容量：" << array1.getCapacity()<<endl;
	cout << "array1的大小：" << array1.getSize() <<endl;
	Array<int> array2(array1);//测试拷贝
	array2.Pop_back();
	cout << "array1打印输出：" << endl;
	PrintArray(array2);
	cout << "array1的容量：" << array2.getCapacity() << endl;
	cout << "array1的大小：" << array2.getSize() << endl;
}
//测试自定义数据类型
class Person
{
public:

	Person() {}//默认构造
	friend void PrintPersonarr(Array<Person> &parr);
	Person(string name, int age)//默认有参构造
	{
		this->m_name = name;
		this->m_age = age;
	}
private:
	string m_name;
	int m_age;

};
void PrintPersonarr(Array<Person> &parr)
{
	for (int i = 0; i < parr.getSize(); i++)
	{
		cout << "姓名： " <<parr[i].m_name<<
			"年龄： "<<parr[i].m_age<<endl;
	}
}
void test02()
{
	//创建数据
	Array<Person> parray1(7);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);
	//插入数组
	parray1.Push_back(p1);
	parray1.Push_back(p2);
	parray1.Push_back(p3);
	parray1.Push_back(p4);
	parray1.Push_back(p1);
	parray1.Push_back(p5);
	cout << "parray1打印输出：" << endl;
	PrintPersonarr(parray1);
	cout << "parray1的容量：" << parray1.getCapacity() << endl;
	cout << "parray1的大小：" << parray1.getSize() << endl;
	cout << "parray1打印输出：" << endl;
	Array<Person> parray2(parray1);
	parray2.Pop_back();
	parray2.Pop_back();
	PrintPersonarr(parray2);
	cout << "parray1的容量：" << parray2.getCapacity() << endl;
	cout << "parray1的大小：" << parray2.getSize() << endl;

}
int main()
{
	//test01();
	test02();
}