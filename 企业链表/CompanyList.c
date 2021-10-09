//#include"LinkList.h"
#include"CompanyList.h"


//��ʼ������
LinkList * Init_LinkList() {
	printf("----------------------------------------------\n");
	printf("���ڳ�ʼ������....\n");
	LinkList* list = (LinkList*)malloc(sizeof(LinkList));
	list->head.next = NULL;
	list->size = 0;
	printf("��ʼ�����!\n");
	return list;
}

//ָ��λ�ò���
void Insert_LinkList(LinkList* list, int pos, LinkNode* data) {
	printf("----------------------------------------------\n");
	printf("���ڲ�������...\n");
	if (list == NULL) {
		printf("����ʧ��,����Ϊ��!\n");
		return;
	}
	if (data == NULL) {
		printf("����ʧ��,����Ϊ��\n");
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size;
	}

	//���Ҳ���λ��
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//�����½ڵ�
	data->next = pCurrent->next;
	pCurrent->next = data;

	list->size++;
	printf("����ɹ�!\n");
}

//ɾ��ָ��λ�õ�ֵ
void Remove_LinkList(LinkList* list, int pos) {
	printf("----------------------------------------------\n");
	printf("����ɾ������...\n");
	if (list == NULL) {
		printf("ɾ��ʧ��,����Ϊ��!\n");
		return;
	}
	if (pos<0 || pos>list->size) {
		pos = list->size;
	}
	//����ָ�����
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}

	//ɾ���ڵ�
	pCurrent->next = pCurrent->next->next;
	list->size--;
	printf("ɾ���ɹ�!\n");
}

//����
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare) {
	printf("----------------------------------------------\n");
	printf("���ڲ�ѯ...\n");
	if (list == NULL) {
		printf("��ѯʧ��,����Ϊ��!\n");
		return -1;
	}
	if (data == NULL) {
		printf("��ѯʧ��,����Ϊ��!\n");
		return -1;
	}
	//����ָ�����
	LinkNode* pCurrent = list->head.next;//ָ������ĵ�һ��Ԫ��
	int index = 1;
	while (pCurrent != NULL) {
		//���ҵ���ͬ����
		if (compare(pCurrent, data) == 0) {
			printf("��ѯ�ɹ�!\n");
			return index;//���ҵ���ͬ����,����Ԫ��λ��(index)
		}
		pCurrent = pCurrent->next;//��ƥ����ָ���������һ���ڵ�
		index++;
	}
	printf("δ�ܲ�ѯ��������!");
	return 0;//δ���ҵ���ͬ����,����0
}

LinkNode * Obtain_Node(LinkList * list, int pos)
{
	printf("----------------------------------------------\n");
	printf("���ڻ�ȡ���...\n");
	//����Ϊ��
	if (list == NULL) {
		printf("��ȡʧ��,����Ϊ��!\n");
		return NULL;
	}
	//�����Ϸ�
	if (pos<0 || pos>list->size) {
		printf("��ȡʧ��,�����Ȳ��Ϸ�!\n");
		return NULL;
	}
	//����Ŀ��λ�õĽ��
	LinkNode* pCurrent = &(list->head);
	for (int i = 0; i < pos; i++) {
		pCurrent = pCurrent->next;
	}
	printf("��ȡ�ɹ�!���ڷ���.\n");
	return pCurrent;
}




//�����С
int Size_LinkList(LinkList * list){
	printf("[ ������Ϊ:%d ]\n",list->size);
		return list->size;
}

	//��ӡ������
void Print_LinkList(LinkList* list, PRINTNODE print) {
	printf("----------------------------------------------\n");
	printf("���ڴ�ӡ����...\n");
	if (list == NULL) {
		return;
	}
	//����ָ�����
	LinkNode* pCurrent = list->head.next;
	while (pCurrent != NULL) {
		print(pCurrent);
		pCurrent = pCurrent->next;
	}
	printf("��ӡ���\n");
}

//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list) {
	printf("----------------------------------------------\n");
	printf("�����ͷ������ڴ�...\n");
	if (list == NULL) {
		return;
	}

	free(list);
	printf("�ͷųɹ�!\n");

}

