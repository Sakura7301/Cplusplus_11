#pragma once
#include<iostream>//���������
using namespace std;//��׼�����ռ�
#include<string>
#include "worker.h"
//�ϰ���
class BOSS :public Worker
{
public:
	BOSS(int id, string name, int dId);
	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡְ����λ����
	virtual string getDeptName();

};