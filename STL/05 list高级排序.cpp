#if 0


#include <list>
#include<iostream>
#include <string>
using namespace std;
class Person 
{
public:
	Person(string name, int age, int height,int weight) 
	{
		m_Name = name;
		m_Age = age;
		m_Height = height;
		m_Weight = weight;
	}

public:
	string m_Name;  //����
	int m_Age;      //����
	int m_Height;   //���
	int m_Weight;
};

//ָ���������
bool ComparePerson(Person& p1, Person& p2) 
{
	if (p1.m_Age == p2.m_Age) 
	{
		if (p1.m_Height == p2.m_Height)
		{
			return p1.m_Weight < p2.m_Weight;
		}
		else 
		{
			return p1.m_Height < p2.m_Height;
		}	
	}
	else
	{
		return  p1.m_Age < p2.m_Age;
	}
}

void test01() 
{
	list<Person> L;

	Person p1("����", 35, 175,55);
	Person p2("�ܲ�", 45, 160,70);
	Person p3("��Ȩ", 40, 160,60);
	Person p4("����", 25, 190,72);
	Person p5("�ŷ�", 35, 160,68);
	Person p6("����", 35, 200,80);
	Person p7("����", 55, 174, 65);
	Person p8("��", 35, 190, 70);
	Person p9("κ��", 35, 174, 69);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	L.push_back(p7);
	L.push_back(p8);
	L.push_back(p9);
	cout << "����ǰ��" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) 
	{
				cout << "����:" << it->m_Name << "  ����:" << it->m_Age
			<< "  ���:" << it->m_Height << "  ����:" << it->m_Weight << endl;
	}

	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //����
	cout << "�����" << endl;
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++) 
	{
		cout << "����:" << it->m_Name << "  ����:" << it->m_Age
			<< "  ���:" << it->m_Height << "  ����:" << it->m_Weight << endl;
	}
}

int main() 
{

	test01();

	system("pause");

	return 0;
}
#endif // 0