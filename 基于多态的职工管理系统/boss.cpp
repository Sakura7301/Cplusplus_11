#include "boss.h"

BOSS::BOSS(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}
void BOSS::showInfo()
{
	cout << "��ţ� " << this->m_Id
		<< " \t������ " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \tְ�𣺹���˾��������" << endl;

}

string BOSS::getDeptName()
{
	return string("�ϰ�");
}
