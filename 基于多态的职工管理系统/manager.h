#pragma once
#include<iostream>//���������
using namespace std;//��׼�����ռ�
#include<string>
#include "worker.h"
//������
class Manager :public Worker
{
public:

	Manager(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDeptName();
};