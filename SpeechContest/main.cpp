#include<iostream>
#include"SpeechManager.h"
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	SpeechManager sm;
	int choice=0;
	while (1)
	{
		sm.show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://开始比赛
			sm.StartSpeech();
			break;
		case 2://查看往届记录
			sm.ShowRead();
			break;
		case 3://清空往届记录
			sm.ClearSpeech();
			break;
		case 0://退出系统
			sm.exit_System();
			break;
		default:
			break;
		}
	}

	system("Sakura");
	return 0;
}