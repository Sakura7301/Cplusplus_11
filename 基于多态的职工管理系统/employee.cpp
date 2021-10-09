#include "employee.h"
	//构造函数
Employee::Employee(int id, string name, int dId)
{
	//使用this来初始化自身数据
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId= dId;
}
//显示个人信息
void Employee::showInfo()
{
	cout << "编号： " << this->m_Id
		<< " \t姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t职责：完成经理交给的任务" << endl;

}
string Employee::getDeptName()
{
	return string("普通员工");
}
//获取岗位名称