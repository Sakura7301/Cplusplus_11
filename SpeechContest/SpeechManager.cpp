#include<iostream>
#include"SpeechManager.h"
using namespace std;

SpeechManager::SpeechManager()
{
	this->InitSpeech();//初始化成员属性、
	this->CreateSpeech();//创建选手
	//this->ReadSpeech();//读取往届记录
}
SpeechManager::~SpeechManager()
{

}

void SpeechManager::show_Menu()//菜单
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::exit_System()//退出
{
	cout << "感谢您的使用！" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::InitSpeech()//初始化
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_LoadSpeech.clear();//读取文件的容器也需要清空
	//清空容器
	this->m_Index = 1;
	//初始化比赛轮数
}

void SpeechManager::CreateSpeech()//创建选手
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];
		Speaker sp;
		sp.m_Name = name;//初始化姓名
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;//初始化两轮比赛的成绩均为0
		}

		//存放编号和对应的选手
		this->m_Speaker.insert(make_pair(i + 10001, sp));
		
		//将选手编号也存入 v1 中
		this->v1.push_back(i + 10001);
	}
}

void SpeechManager::DrawSpeech()//抽签
{
	cout << "第" << this->m_Index << "轮抽签开始" << endl;
	cout << "-------------------------------------" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
	}
	else if (this->m_Index == 2)
	{
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------" << endl;
	system("pause");
}
//*****重点内容******
void SpeechManager::ContestSpeech()//比赛开始
{
	cout << "------------- 第" << this->m_Index << "轮正式比赛开始：------------- " << endl;

	multimap<double,   int,   greater<int>> groupScore; //临时容器，保存key分数 value 选手编号
	       //first   second   排序方式
		   //分数    编号     降序

	vector<int>temp;//创建一个临时的比赛容器
	int num = 0;//用于分组计数的变量num
	if (this->m_Index == 1)
	{
		temp = v1;
	}
	else
	{
		temp = v2;
	}
	//遍历容器
	for (vector<int>::iterator it = temp.begin(); it!=temp.end(); it++)
	{
		num++;
		deque<double>d;//使用deque容器记录分数
		//方便去掉高低分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>());//降序排序

		d.pop_front();
		d.pop_back();//去掉高低分

		double sum = accumulate(d.begin(), d.end(),0.0f);//获取总分	
		double avg = sum /((double)d.size());//获取平均分	

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;//将数据记录在m_Speaker容器中
		                             //this->m_Index-1的值即为第n轮的分数

		//使用临时容器来保存分组的结果
		//6个人一组，用临时容器保存
		groupScore.insert(make_pair(avg, *it));//存放第编号为*it的选手的分数
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<int> >::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << "  姓名：" << this->m_Speaker[it->second].m_Name
					<< "  成绩:" << this->m_Speaker[it->second].m_Score[this->m_Index-1] << endl;
			}

			//取前三名
			int count = 0;
			for (multimap<double, int, greater<int> >::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++,count++)
												//因为已经降序排序，因此，前三个就是前三名，所以，取出 count<3 的元素即可
			{
				if (this->m_Index == 1)//如果是第一轮比赛，则将该选手的编号存入v2中
				{
					v2.push_back((*it).second);
				}
				else//如果是第二轮比赛，则将该选手的编号存入vVictory中
				{
					vVictory.push_back((*it).second);
				}
			}
			//每次操作完，需要将临时容器的元素清空，方便下一次使用
			groupScore.clear();
			cout << endl;
		}

	}
	cout << "------------- 第" << this->m_Index << "轮正式比赛结束！------------- " << endl;
	cout << endl;
	system("pause");
}




void SpeechManager::DisplaySpeech()//显示晋级选手
{
	cout << "---------- 第" << this->m_Index << "轮晋级选手信息如下-----------" << endl;
	vector<int>v;//创建一个临时的比赛容器
	if (this->m_Index == 1)
	{
		v  = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << "  姓名" << this->m_Speaker[*it].m_Name
			<< "  成绩：" << this->m_Speaker[*it].m_Score[this->m_Index-1]<< endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

void SpeechManager::SaveSpeech()//保存记录
{
	ofstream ofs;
	ofs.open("Speech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << ","<<this->m_Speaker[*it].m_Name<<"," << this->m_Speaker[*it].m_Score[this->m_Index - 1] << ",";
	}
	ofs << endl;
	ofs.close();
	this->FileEmpty = false;
	cout << "本次记录已经保存！" << endl;
}

void SpeechManager::ReadSpeech()
{
	ifstream ifs;
	ifs.open("Speech.csv", ios::in);
	if (!ifs.is_open())
	{
		this->FileEmpty = true;//文件为空
		cout << "文件为空或不存在！" << endl;
		ifs.close();//关闭
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())//如果读取到的数据为结束符号
	{
		cout << "文件为空或不存在!" << endl;
		this->FileEmpty = true;
		ifs.close();
		return;
	}

	//以上两种状况均不成立，则文件一定不为空
	this->FileEmpty = false;
	ifs.putback(ch); //读取的单个字符放回去,否则文件中会少一个字符
	string data;
	int index = 0;
	while (ifs>>data)
	{
		vector<string>v;
		int pos = -1;//标记是否找到字符的变量
		int start = 0;
		while (1)
		{
			pos = data.find(",",start);//从start位置处查找" , "
			if (pos == -1)
			{
				break;//没找到，返回
			}
			string temp;//用于存储分割后的字符串
			temp=data.substr(start,pos-start );//截取 [start,pos-start] 区间内的字符串
			v.push_back(temp);
			start = pos + 1;//每一次截取之后，起始位置为逗号后的字符
		}
		this->m_LoadSpeech.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void SpeechManager::ShowRead()
{
	this->ReadSpeech();
	for (int i = 0; i < m_LoadSpeech.size(); i++)
	{
		cout << "第" << i + 1 << "届比赛结果： " << endl;
		cout << "冠军编号：" << this->m_LoadSpeech[i][0] << "  姓名：" << this->m_LoadSpeech[i][1] << "  成绩：" << this->m_LoadSpeech[i][2] << endl;
		cout<< "亚军编号："  << this->m_LoadSpeech[i][3] << "  姓名：" << this->m_LoadSpeech[i][4] << "  成绩：" << this->m_LoadSpeech[i][5] << endl;
		cout<< "季军编号："  << this->m_LoadSpeech[i][6] << "  姓名：" << this->m_LoadSpeech[i][7] << "  成绩：" << this->m_LoadSpeech[i][8] << endl;
	}
	system("pause");
	system("cls");
}

void SpeechManager::ClearSpeech()
{
	int select;
	cout << "您是否真的要清空？" << endl;
	cout << "输入1确认。" << endl;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs("Speech.csv", ios::trunc);
		ofs.close();
		cout << "清空成功！" << endl;
	}
	this->m_LoadSpeech.clear();
	system("pause");
	system("cls");

}


void SpeechManager::StartSpeech()//演讲开始
{
	
	//第一轮比赛
	//默认  this->m_Index=1
	//1、抽签
	this->DrawSpeech();
	//2、比赛
	this->ContestSpeech();
	//3、显示晋级结果
	this->DisplaySpeech();

	//第二轮比赛
	this->m_Index++;
	//1、抽签
	this->DrawSpeech();
	////2、比赛
	this->ContestSpeech();
	////3、显示最终结果
	this->DisplaySpeech();
	////4、保存分数
	this->SaveSpeech();
	cout << "本届比赛结束！！" << endl;
	//比赛结束后需要重置记录
	this->InitSpeech();//清空容器
	this->CreateSpeech();//创建十二个选手

}
