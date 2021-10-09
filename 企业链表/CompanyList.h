#pragma once
#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>

//����С�ڵ�
typedef struct LINKNODE {
	struct LINKNODE* next;
}LinkNode;

//����ڵ�
typedef struct LINKLIST {
	LinkNode head;
	int size;
}LinkList;

//����������ָ��,�Զ�������д��
typedef void(*PRINTNODE)(LinkNode*);

//�ȽϺ�����ָ��
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);


//��ʼ������
LinkList* Init_LinkList(); 

//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

//ɾ��ָ��λ�õ�ֵ
void Remove_LinkList(LinkList* list, int pos);

//����
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);

//��ȡ�ڵ�
LinkNode* Obtain_Node(LinkList* list, int pos);

//��������Ĵ�С
int Size_LinkList(LinkList* list);

//��ӡ������
void Print_LinkList(LinkList* list, PRINTNODE print);

//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list);

#endif	//!LINKLIST_H