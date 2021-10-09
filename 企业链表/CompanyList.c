//#include"LinkList.h"
#include"CompanyList.h"


//初始化链表
LinkList * Init_LinkList() {
	printf("----------------------------------------------\n");
	printf("正在初始化链表....\n");
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	printf("初始化完成!\n");
	return list;
}

//指定位置插入
void Insert_LinkList(LinkList* list, int pos, LinkNode* data) {
	printf("----------------------------------------------\n");
	printf("正在插入链表...\n");
	if (list == NULL) {
		printf("插入失败,链表为空!\n");
		return;
	}
	if (data == NULL) {
		printf("插入失败,数据为空\n");
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size;
	}

	//查找插入位置
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//插入新节点
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
	printf("插入成功!\n");
}

//删除指定位置的值
void Remove_LinkList(LinkList* list, int pos) {
	printf("----------------------------------------------\n");
	printf("正在删除数据...\n");
	if (list == NULL) {
		printf("删除失败,链表为空!\n");
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size;
	}
	//辅助指针变量
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//删除节点
	pCurrent->next = pCurrent->next->next;
	list->size--;
	printf("删除成功!\n");
}

//查找
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare) {
	printf("----------------------------------------------\n");
	printf("正在查询...\n");
	if (list == NULL) {
		printf("查询失败,链表为空!\n");
		return -1;
	}
	if (data == NULL) {
		printf("查询失败,数据为空!\n");
		return -1;
	}
	//辅助指针变量
	LinkNode* pCurrent = list->head.next;//指向链表的第一个元素
	int index = 1;
	while (pCurrent != NULL) {
		//查找到相同数据
		if (compare(pCurrent, data) == 0) {
			printf("查询成功!\n");
			return index;//若找到相同数据,返回元素位置(index)
		}
		pCurrent = pCurrent->next;//不匹配则指向链表的下一个节点
		index++;
	}
	printf("未能查询到该数据!");
	return 0;//未查找到相同数据,返回0
}

LinkNode * Obtain_Node(LinkList * list, int pos)
{
	printf("----------------------------------------------\n");
	printf("正在获取结点...\n");
	//链表为空
	if (list == NULL) {
		printf("获取失败,链表为空!\n");
		return NULL;
	}
	//链表不合法
	if (pos<0 || pos>list->size) {
		printf("获取失败,链表长度不合法!\n");
		return NULL;
	}
	//查找目标位置的结点
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	printf("获取成功!正在返回.\n");
	return pCurrent;
}




//链表大小
int Size_LinkList(LinkList * list){
	printf("[ 链表长度为:%d ]\n",list->size);
		return list->size;
}

	//打印链表结点
void Print_LinkList(LinkList* list, PRINTNODE print) {
	printf("----------------------------------------------\n");
	printf("正在打印链表...\n");
	if (list == NULL) {
		return;
	}
	//辅助指针变量
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL) {
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
	printf("打印完成\n");
}

//释放链表内存
void FreeSpace_LinkList(LinkList* list) {
	printf("----------------------------------------------\n");
	printf("正在释放链表内存...\n");
	if (list == NULL) {
		return;
	}

	free(list);
	printf("释放成功!\n");

}

