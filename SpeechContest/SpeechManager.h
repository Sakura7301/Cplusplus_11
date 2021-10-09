#pragma once
#include<iostream>
#include<vector>
#include<map>
#include"Speaker.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<fstream>
#include<ctime>
using namespace std;

class SpeechManager
{
public:
	SpeechManager();
	~SpeechManager();
	void show_Menu();//菜单
	void exit_System();//退出系统
	void InitSpeech();//初始化成员属性
	void CreateSpeech();//创建比赛选手

	void StartSpeech();//开始演讲
		void DrawSpeech();//-------抽签
		void ContestSpeech();//----开始比赛
		void DisplaySpeech();//----显示晋级选手
	void SaveSpeech();//保存记录
	bool FileEmpty;   //文件是否为空的标志
	void ReadSpeech();//读取往届记录
	void ShowRead();//显示往届记录
	void ClearSpeech();//清空往届记录


	vector<int>v1;//第一轮编号
	vector<int>v2;//第二轮编号
	vector<int>vVictory;//胜利者编号


	map<int, Speaker>m_Speaker;//存放所有参赛选手的数据

	map<int, vector<string>>m_LoadSpeech;//存放从文件读取到的数据
	int m_Index;

};