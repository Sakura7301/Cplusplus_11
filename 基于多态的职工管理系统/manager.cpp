#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void Manager::showInfo()
{
	cout << "编号： " << this->m_Id
		<< " \t姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t职责：完成老板交给的任务，给员工下发任务" << endl;
}

string Manager::getDeptName()
{
	return string("经理");
}
