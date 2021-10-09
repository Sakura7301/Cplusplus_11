#include  "workerManager.h"
#include<iostream>//输入输出流头文件
using namespace std;//使用标准命名空间

WorkerManager::WorkerManager()//构造函数实现
{
	//---1   文件不存在
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (ifs.is_open() == 0)//判断文件是否打开成功，成功则返回true
	{
		cout << "文件不存在" << endl;
		//初始化数据
		this->m_EmpNum = 0;//初始文件中的人数为0
		this->m_EmpArray = NULL;//初始数组指针指向空
		this->filehave = true;//将标志置为true
		ifs.close();//关闭文件
		return;//返回
	}

	//---2   文件存在 数据为空
	char ch;
	ifs >> ch;//使用>>读取一个字符
	if (ifs.eof() == 1)//判断读取到的字符是否为结束标志
	{
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;//初始文件中的人数为0
		this->m_EmpArray = NULL;//初始数组指针指向空
		this->filehave = true;//将标志置为true
		ifs.close();//关闭文件
		return;//返回
	}

	//---3   文件存在 且已记录数据
	int num = this->getm_EmpNum();//调用职工人数获取函数
	//cout << "职工人数为:" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker *[this->m_EmpNum];
	this->initEmp();
	//测试代码
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "职工编号：" << this->m_EmpArray[i]->m_Id << endl;
		cout << "职工姓名：" << this->m_EmpArray[i]->m_Name << endl;
		cout << "职工部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
	}*/

}

WorkerManager::~WorkerManager()//析构函数实现
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete[] this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

void WorkerManager::add_Emp()//添加职工函数
{
	cout << "请输入需要添加到的职工数量：" << endl;
	int addnum;
	cin >> addnum;
	if (addnum > 0)
	{
		//计算需要添加的数据空间大小
		int newsize = this->m_EmpNum + addnum;
		//新增空间=原记录人数+新增人数
		Worker **newspace;
		newspace = new Worker*[newsize];//new返回值是指针的地址

		//注解：new创建出来的堆区数组需要用一个指针来接收
		//而数组的成员又是指针，因此需要用一个二级指针去接收

		//如若原来的空间下已有数据，则需要把原来的数据
		//拷贝至新空间下

		if (this->m_EmpArray != NULL)//拷贝原有数据
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newspace[i] = this->m_EmpArray[i];//拷贝操作
			}
		}
		for (int i = 0; i < addnum; i++)//批量添加
		{
			int id;
			string name;
			int did;
			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工的姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位:" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> did;
			//使用多态处理不同的员工类型
			Worker *worker = NULL;
			switch (did)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new BOSS(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的职工指针，需要保存到指针数组中
			newspace[this->m_EmpNum + i] = worker;
		}
		//添加完成之后需要删除原有的内存空间		
		delete[] this->m_EmpArray;//释放数组空间需要+[]

		//更改新空间的指向
		this->m_EmpArray = newspace;

		//更新新的职工人数
		this->m_EmpNum = newsize;

		this->save();//调用save函数
		this->filehave = false;//将文件存在标志位置为false(不为空)

		cout << "成功添加" << addnum << "名新职工！" << endl;


	}
	else
	{
		cout << "您的输入有误！" << endl;
	}
	system("pause");
	system("cls");
}

int WorkerManager::getm_EmpNum()//获取职工人数函数
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}



void WorkerManager::initEmp()//初始化职工函数
{
	ifstream ifs;
	ifs.open(filename, ios::in);
	int id;
	string name;
	int did;
	int index = 0;//用于计数的变量index
	while (ifs >> id, ifs >> name, ifs >> did)
	{
		Worker *worker = NULL;
		//利用多态根据不同的部门Id指向不同的对象
		if (did == 1)//普通员工
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)//经理
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)//老板
		{
			worker = new BOSS(id, name, did);
		}
		this->m_EmpArray[index] = worker;//将读取到的数据递交给m_EmpArray数组
		index++;
	}
	ifs.close();
}

void WorkerManager::Show_Emp()//显示职工函数
{
	if (this->filehave==1)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp()//删除职工函数
{
	if (this->filehave == 1)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号：" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)
		{
			cout << "已找到该职工，是否删除？" << endl;
			cout << "输入 1 删除。" << endl;
			cout << "输入其他值取消操作。" << endl;
			int ch;
			cin >> ch;
			if (ch == 1)
			{
				for (int i = index; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				this->m_EmpNum--;//数组长度-1 
				//将修改后的数据同步至文件中
				
				this->save();
				cout << "删除完毕。" <<endl;
			}
			else
			{
				system("cls");
				return;
			}
		}
		else
		{
			cout << "不存在该职工！" << endl;
			return;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Mod_Emp()//职工信息修改函数
{
	if(this->filehave == 1)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)
		{
			cout << "已找到该职工，是否修改？" << endl;
			cout << "输入 1 修改。" << endl;
			cout << "输入其他值取消操作。" << endl;
			int ch;
			cin >> ch;
			if (ch == 1)
			{
				delete this->m_EmpArray[index];
				int newid;
				string newname;
				int newdid;
				cout << "请输入职工编号：" << endl;
				cin >> newid;
				cout << "请输入职工的姓名：" << endl;
				cin >> newname;
				cout << "请选择该职工的岗位:" << endl;
				cout << "1.普通员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
				cin >> newdid;
				//使用多态处理不同的员工类型
				Worker *worker = NULL;
				switch (newdid)
				{
				case 1:
					worker = new Employee(id, newname, 1);
					break;
				case 2:
					worker = new Manager(id, newname, 2);
					break;
				case 3:
					worker = new BOSS(id, newname, 3);
					break;
				default:
					break;
				}
				//将创建的职工指针，需要保存到指针数组中
				this->m_EmpArray[index]=worker;
			}
			else
			{
				system("pause");
				return;
			}
			//将修改后的数据同步至文件中
			this->save();
			cout << "修改完毕。" << endl;
		}
		else
		{
			cout << "不存在该职工！" << endl;
			return;
		}	
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExit(int id)//判断职工是否存在函数
								//不存在返回-1
{
	int index=-1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}



void WorkerManager::save()//数据保存到文件函数
{
	ofstream ofs;//创建输出流对象
	ofs.open(filename, ios::out);//使用输出的方式打开文件
	for (int i = 0; i < this->m_EmpNum; i++)//写入文件
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();//关闭文件

}
void WorkerManager::show_Menu()//菜单函数
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void WorkerManager::ExirSystem()//系统退出函数
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
