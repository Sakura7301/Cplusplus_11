#pragma once
#include<iostream>//输入输出流
using namespace std;//标准命名空间
#include<string>
#include "worker.h"
//经理类
class Manager :public Worker
{
public:

	Manager(int id, string name, int dId);
	//显示个人信息
	virtual void showInfo();

	//获取职工岗位名称
	virtual string getDeptName();
};