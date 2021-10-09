#pragma once
#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H

#include<stdio.h>
#include<stdlib.h>

//链表小节点
typedef struct LINKNODE {
	struct LINKNODE* next;
}LinkNode;

//链表节点
typedef struct LINKLIST {
	LinkNode head;
	int size;
}LinkList;

//遍历函数的指针,自定义类型写法
typedef void(*PRINTNODE)(LinkNode*);

//比较函数的指针
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);


//初始化链表
LinkList* Init_LinkList(); 

//指定位置插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

//删除指定位置的值
void Remove_LinkList(LinkList* list, int pos);

//查找
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);

//获取节点
LinkNode* Obtain_Node(LinkList* list, int pos);

//返回链表的大小
int Size_LinkList(LinkList* list);

//打印链表结点
void Print_LinkList(LinkList* list, PRINTNODE print);

//释放链表内存
void FreeSpace_LinkList(LinkList* list);

#endif	//!LINKLIST_H