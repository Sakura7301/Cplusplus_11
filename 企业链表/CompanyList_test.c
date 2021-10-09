
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include"CompanyList.h"
//链表节点
typedef struct PERSON {
	LinkNode node;
	char name[64];
	int age;
}Person;

void MyPrint(LinkNode* data) {

	Person* p = (Person*)data;
	printf("Name:%s \t Age:%d\n", p->name, p->age);
}

int MyCompare(LinkNode* node1, LinkNode* node2) {

	Person* p1 = (Person*)node1;
	Person* p2 = (Person*)node2;

	if (strcmp(p1->name, p2->name) == 0 && p1->age == p2->age) {
		return 0;
	}
	return -1;
}


int main(void)
{

	//创建链表
	LinkList* list = Init_LinkList();

	//创建数据
	Person p1, p2, p3, p4, p5;
	strcpy(p1.name, "唐僧");
	strcpy(p2.name, "悟空");
	strcpy(p3.name, "八戒");
	strcpy(p4.name, "沙僧");
	strcpy(p5.name, "白龙马");

	p1.age = 100;
	p2.age = 200;
	p3.age = 300;
	p4.age = 400;
	p5.age = 500;

	//将结点插入链表
	Insert_LinkList(list, 0, (LinkNode*)&p1);
	Print_LinkList(list, MyPrint);
	Size_LinkList(list);
	Insert_LinkList(list, 0, (LinkNode*)&p2);
	Print_LinkList(list, MyPrint);
	Size_LinkList(list);
	Insert_LinkList(list, 0, (LinkNode*)&p3);
	Print_LinkList(list, MyPrint);
	Size_LinkList(list);
	Insert_LinkList(list, 0, (LinkNode*)&p4);
	Print_LinkList(list, MyPrint);
	Size_LinkList(list);
	Insert_LinkList(list, 0, (LinkNode*)&p5);
	Print_LinkList(list, MyPrint);
	Size_LinkList(list);
	//打印
	Print_LinkList(list, MyPrint);



	//删除节点
	Remove_LinkList(list, 2);
	Size_LinkList(list);
	//打印
	Print_LinkList(list, MyPrint);

	//查找结点
	Person findP;
	strcpy(findP.name, "唐僧");
	findP.age = 100;
	int pos = Find_LinkList(list, (LinkNode*)&findP, MyCompare);
	printf("%s的位置：%d\n",findP.name, pos);

	//获取这个结点
	Person *op = Obtain_Node(list,1);
	printf("name=%s \t age=%d\n",op->name,op->age);

	//修改结点数据
	op->age = 22;
	strcpy(op->name,"何");
	printf("已修改\n");
	//打印
	Print_LinkList(list, MyPrint);
	Size_LinkList(list);
	//释放链表内存
	FreeSpace_LinkList(list);

	printf("\n");
	system("pause");
	return 0;
}