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
	void show_Menu();//�˵�
	void exit_System();//�˳�ϵͳ
	void InitSpeech();//��ʼ����Ա����
	void CreateSpeech();//��������ѡ��

	void StartSpeech();//��ʼ�ݽ�
		void DrawSpeech();//-------��ǩ
		void ContestSpeech();//----��ʼ����
		void DisplaySpeech();//----��ʾ����ѡ��
	void SaveSpeech();//�����¼
	bool FileEmpty;   //�ļ��Ƿ�Ϊ�յı�־
	void ReadSpeech();//��ȡ�����¼
	void ShowRead();//��ʾ�����¼
	void ClearSpeech();//��������¼


	vector<int>v1;//��һ�ֱ��
	vector<int>v2;//�ڶ��ֱ��
	vector<int>vVictory;//ʤ���߱��


	map<int, Speaker>m_Speaker;//������в���ѡ�ֵ�����

	map<int, vector<string>>m_LoadSpeech;//��Ŵ��ļ���ȡ��������
	int m_Index;

};