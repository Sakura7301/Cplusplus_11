#pragma once//��ֹͷ�ļ�����
#include<iostream>//���������
using namespace std;//��׼�����ռ�
#include<fstream>//�ļ���
constexpr auto filename = "emofile.txt";  //�궨���ļ���;
#include"worker.h"
#include "employee.h"
#include"boss.h"
#include"manager.h"
class WorkerManager
{
public:
	WorkerManager();//����	

	~WorkerManager();//����

	void show_Menu();//�˵�����

	void ExirSystem();//�˳�����

	void save();//�ļ����溯��
	
	bool filehave;//�ж��ļ��Ƿ�Ϊ�յ� ��־

	void add_Emp();//ְ����Ӻ���

	int getm_EmpNum();//��ȡְ�������ĺ���

	void initEmp();//��ʼ��ְ������
	
	void Show_Emp();//��ʾְ������

	void Del_Emp();//ɾ��ְ������

	void Mod_Emp();//ְ����Ϣ�޸ĺ���

	int IsExit(int id);//�ж�ְ���Ƿ���ں���

	int m_EmpNum;//��¼�ļ��е���������
	//Ա�������ָ��
	Worker ** m_EmpArray;//ָ��(Ա��)ָ�������ָ��
	/*
	��һ��*����������
	�ڶ���*��ָ��
	��Ϊ��ָ��ָ���ָ��
	*/
};