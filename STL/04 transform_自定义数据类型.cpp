#if 0


#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person &p)
	{
		if (this->m_Name == p.m_Name&&this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	string  m_Name;
	int m_Age;
};
int main()
{
	vector<Person>v;
	Person p1("����", 18);
	Person p2("����", 28);
	Person p3("����", 13);
	Person p4("����", 8);
	Person p5("����", 14);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//v.pop_back();
	cout << "��һ�ֲ��ң�" << endl;
	vector<Person>::iterator it = find(v.begin(), v.end(), p2);//��һ�ֲ�ѯ�ķ�ʽ
										//���������ڲ���Ԫ�أ�Ԥ��������==�������
	if (it == v.end())
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "���ҳɹ���" << endl;
		cout << it->m_Name<<"  "<<it->m_Age<< endl;
	}
	cout << "-------------------------------" << endl;
	cout << "�ڶ��ֲ��ң�" << endl;

	Person pp("����", 18);
	vector<Person>::iterator it2 = find(v.begin(), v.end(), pp);//�ڶ��ֲ��ҷ�ʽ
							//��ѯ�����ɶ���������ͬ������Ԫ��pp
	
	if (it2 == v.end())
	{
		cout << "û���ҵ���" << endl;
	}
	else
	{
		cout << "���ҳɹ���" << endl;
		cout << it->m_Name << "  " << it->m_Age << endl;
	}
}
#endif // 0