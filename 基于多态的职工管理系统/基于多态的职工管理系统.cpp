#include<iostream>//���������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include<string>
#include  "workerManager.h"
#include"worker.h"
#include"employee.h"
#include "boss.h"
#include"manager.h"
int main()
{
	////����ְ����̬����ͨԱ��
	//Worker *worker = NULL;
	//worker=new Employee(1, "����", 520);
	//worker->showInfo();
	//delete worker;
	////����
	//worker = new Manager(8, "����", 1);
	//worker->showInfo();
	//delete worker;
	////�ϰ�
	//worker = new BOSS(0, "�Ա�ɽ", 0);
	//worker->showInfo();
	//delete worker;


	//ʵ����һ���������
	WorkerManager wm;
	int choice;//��¼�û�ѡ��
	while (true)
	{
		wm.show_Menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1://����ְ��
				wm.add_Emp();
				break;
			case 2://��ʾְ��
				wm.Show_Emp();
				break;
			case 3://ɾ��ְ��
				wm.Del_Emp();
				break;
			case 4://�޸�ְ��
				wm.Mod_Emp();
				break;
			case 5://����ְ��
				break;
			case 6://����ְ��
				break;
			case 7://����ĵ�
				break;
			case 0://�˳�ϵͳ
				wm.ExirSystem();
				break;
			default:
				system("cls");//����
				break;
		}
	}
	system("pause");
	return 0;
}