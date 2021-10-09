#include<iostream>//输入输出流头文件
using namespace std;//使用标准命名空间
#include<string>
#include  "workerManager.h"
#include"worker.h"
#include"employee.h"
#include "boss.h"
#include"manager.h"
int main()
{
	////测试职工多态：普通员工
	//Worker *worker = NULL;
	//worker=new Employee(1, "张三", 520);
	//worker->showInfo();
	//delete worker;
	////经理
	//worker = new Manager(8, "刘能", 1);
	//worker->showInfo();
	//delete worker;
	////老板
	//worker = new BOSS(0, "赵本山", 0);
	//worker->showInfo();
	//delete worker;


	//实例化一个管理对象
	WorkerManager wm;
	int choice;//记录用户选择
	while (true)
	{
		wm.show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
			case 1://增加职工
				wm.add_Emp();
				break;
			case 2://显示职工
				wm.Show_Emp();
				break;
			case 3://删除职工
				wm.Del_Emp();
				break;
			case 4://修改职工
				wm.Mod_Emp();
				break;
			case 5://查找职工
				break;
			case 6://排序职工
				break;
			case 7://清空文档
				break;
			case 0://退出系统
				wm.ExirSystem();
				break;
			default:
				system("cls");//清屏
				break;
		}
	}
	system("pause");
	return 0;
}