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
//ѡ�� 
void createPerson(vector<Person>&v)
{
		string nameseed = "ABCDE";
		for (int i = 0; i < 5; i++)
		{
			string name="ѡ��";
			name += nameseed[i];//�ַ���ƴ��
			int score = 0;
			Person p(name, score);//ʵ��������p
			v.push_back(p);//����vector������
		}
}

//���  ����  ȥ�ߵͷ�  ��ƽ����  �浽m_name
void SetScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int >d;//���ڴ��������deque����
		for (int i=0;i<10;i++)
		{
			int score = rand() % 41 + 60;//�����������40-60��
			d.push_back(score);//����������deque����
		}
		sort(d.begin(), d.end());//�Է�����������
		d.pop_back();//ȥβ
		d.pop_front();//ȥ��
		int sum = 0;
		for (deque<int >::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);//�ۼӷ���
		}
		int avg = sum / d.size();//ȡƽ����
		it->m_score = avg;//��ƽ����avg��ֵ��m_score
	}
}
void Printsore(vector<Person>&v)//��ӡ
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "����ѡ�֣�\t" << (*it).m_name << "ѡ��ƽ���֣�\t"<<(*it).m_score <<endl;
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