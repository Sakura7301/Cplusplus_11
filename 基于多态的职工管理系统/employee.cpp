#include "employee.h"
	//���캯��
Employee::Employee(int id, string name, int dId)
{
	//ʹ��this����ʼ����������
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId= dId;
}
//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "��ţ� " << this->m_Id
		<< " \t������ " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \tְ����ɾ�����������" << endl;

}
string Employee::getDeptName()
{
	return string("��ͨԱ��");
}
//��ȡ��λ����