#pragma once
#include<iostream>//输入输出流
using namespace std;//标准命名空间
#include<string>
#include "worker.h"
//老板类
class BOSS :public Worker
{
public:
	BOSS(int id, string name, int dId);
	//显示个人信息
	virtual void showInfo();

	//获取职工岗位名称
	virtual string getDeptName();

};