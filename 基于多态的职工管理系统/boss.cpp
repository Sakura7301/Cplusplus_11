#include "boss.h"

BOSS::BOSS(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void BOSS::showInfo()
{
	cout << "编号： " << this->m_Id
		<< " \t姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t职责：管理公司所有事务" << endl;

}

string BOSS::getDeptName()
{
	return string("老板");
}
