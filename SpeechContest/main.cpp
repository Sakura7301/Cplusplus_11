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
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://��ʼ����
			sm.StartSpeech();
			break;
		case 2://�鿴�����¼
			sm.ShowRead();
			break;
		case 3://��������¼
			sm.ClearSpeech();
			break;
		case 0://�˳�ϵͳ
			sm.exit_System();
			break;
		default:
			break;
		}
	}

	system("Sakura");
	return 0;
}