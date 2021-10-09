#pragma once//防止头文件重名
#include<iostream>//输入输出流
using namespace std;//标准命名空间
#include<fstream>//文件流
constexpr auto filename = "emofile.txt";  //宏定义文件名;
#include"worker.h"
#include "employee.h"
#include"boss.h"
#include"manager.h"
class WorkerManager
{
public:
	WorkerManager();//构造	

	~WorkerManager();//析构

	void show_Menu();//菜单函数

	void ExirSystem();//退出函数

	void save();//文件保存函数
	
	bool filehave;//判断文件是否为空的 标志

	void add_Emp();//职工添加函数

	int getm_EmpNum();//获取职工数量的函数

	void initEmp();//初始化职工函数
	
	void Show_Emp();//显示职工函数

	void Del_Emp();//删除职工函数

	void Mod_Emp();//职工信息修改函数

	int IsExit(int id);//判断职工是否存在函数

	int m_EmpNum;//记录文件中的人数个数
	//员工数组的指针
	Worker ** m_EmpArray;//指向(员工)指针数组的指针
	/*
	第一个*是数据类型
	第二个*是指针
	意为：指向指针的指针
	*/
};