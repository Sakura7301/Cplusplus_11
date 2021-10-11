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
	Person p1("张三", 18);
	Person p2("李四", 28);
	Person p3("王五", 13);
	Person p4("赵六", 8);
	Person p5("马七", 14);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//v.pop_back();
	cout << "第一种查找：" << endl;
	vector<Person>::iterator it = find(v.begin(), v.end(), p2);//第一种查询的方式
										//查找容器内部的元素（预先重载了==运算符）
	if (it == v.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "查找成功！" << endl;
		cout << it->m_Name<<"  "<<it->m_Age<< endl;
	}
	cout << "-------------------------------" << endl;
	cout << "第二种查找：" << endl;

	Person pp("王五", 18);
	vector<Person>::iterator it2 = find(v.begin(), v.end(), pp);//第二种查找方式
							//查询与生成对象属性相同的容器元素pp
	
	if (it2 == v.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "查找成功！" << endl;
		cout << it->m_Name << "  " << it->m_Age << endl;
	}
}
#endif // 0