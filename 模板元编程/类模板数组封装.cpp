#include"��ģ�������װ.hpp"
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
//����������������
void test01()
{
	Array<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1��ӡ�����" << endl;
	PrintArray(array1);
	cout << "array1��������" << array1.getCapacity()<<endl;
	cout << "array1�Ĵ�С��" << array1.getSize() <<endl;
	Array<int> array2(array1);//���Կ���
	array2.Pop_back();
	cout << "array1��ӡ�����" << endl;
	PrintArray(array2);
	cout << "array1��������" << array2.getCapacity() << endl;
	cout << "array1�Ĵ�С��" << array2.getSize() << endl;
}
//�����Զ�����������
class Person
{
public:

	Person() {}//Ĭ�Ϲ���
	friend void PrintPersonarr(Array<Person> &parr);
	Person(string name, int age)//Ĭ���вι���
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
		cout << "������ " <<parr[i].m_name<<
			"���䣺 "<<parr[i].m_age<<endl;
	}
}
void test02()
{
	//��������
	Array<Person> parray1(7);
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);
	//��������
	parray1.Push_back(p1);
	parray1.Push_back(p2);
	parray1.Push_back(p3);
	parray1.Push_back(p4);
	parray1.Push_back(p1);
	parray1.Push_back(p5);
	cout << "parray1��ӡ�����" << endl;
	PrintPersonarr(parray1);
	cout << "parray1��������" << parray1.getCapacity() << endl;
	cout << "parray1�Ĵ�С��" << parray1.getSize() << endl;
	cout << "parray1��ӡ�����" << endl;
	Array<Person> parray2(parray1);
	parray2.Pop_back();
	parray2.Pop_back();
	PrintPersonarr(parray2);
	cout << "parray1��������" << parray2.getCapacity() << endl;
	cout << "parray1�Ĵ�С��" << parray2.getSize() << endl;

}
int main()
{
	//test01();
	test02();
}