#if 0


#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<ctime>
#include <algorithm>
using namespace std;

class Person
{
public:
	Person(string name, int score)
	{
		this->m_name = name;
		this->m_score = score;
	}
	string m_name;
	int m_score;
};
//选手 
void createPerson(vector<Person>&v)
{
		string nameseed = "ABCDE";
		for (int i = 0; i < 5; i++)
		{
			string name="选手";
			name += nameseed[i];//字符串拼接
			int score = 0;
			Person p(name, score);//实例化对象p
			v.push_back(p);//存入vector容器中
		}
}

//打分  排序  去高低分  求平均分  存到m_name
void SetScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int >d;//用于储存分数的deque容器
		for (int i=0;i<10;i++)
		{
			int score = rand() % 41 + 60;//生成随机数（40-60）
			d.push_back(score);//将分数存入deque容器
		}
		sort(d.begin(), d.end());//对分数进行排序
		d.pop_back();//去尾
		d.pop_front();//去首
		int sum = 0;
		for (deque<int >::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);//累加分数
		}
		int avg = sum / d.size();//取平均分
		it->m_score = avg;//将平均分avg赋值给m_score
	}
}
void Printsore(vector<Person>&v)//打印
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "参赛选手：\t" << (*it).m_name << "选手平均分：\t"<<(*it).m_score <<endl;
	}
}
int main()

{
	vector<Person>v;
	createPerson(v);
	SetScore(v);
	Printsore(v);
}
#endif // 0