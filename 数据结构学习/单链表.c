//#include<stdio.h>
//#include<stdlib.h>
//
//
//typedef int Elemtype;
//
//typedef struct LNode{
//	Elemtype data;
//	struct LNode* next;
//}LNode,*Linklist;
//
//Linklist initiate(Linklist L) {
//	//int state= isNull(L);
//	//if (state) {
//	//	return NULL;
//	//}���ǲ���ͷ����д��
//	L = (LNode*)malloc(sizeof(LNode));//����ͷ����д����Ҫ�Ը�������ж�̬����
//	if (L == NULL) {
//		perror("��̬����ʧ��!");
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		L->next = NULL;
//		printf("��̬����ɹ�!");
//		return L;
//	}
//	
//}
//
//void append(Linklist L,int value) {//β�巨
//	LNode* Node = (LNode*)malloc(sizeof(LNode));//�Խ����г�ʼ��
//	if (!Node) {
//		perror("malloc failed");
//		exit(EXIT_FAILURE);
//	}
//	else {
//		Node->data = value;
//		Node->next = NULL;
//	}
//	LNode* cur = L;
//	while (cur->next!=NULL) {
//		cur = cur->next;
//	}
//	cur->next= Node;
//}
//
//int isNull(Linklist L) {
//	if (L==NULL)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int Linkinsert(Linklist L,int index,Elemtype value) {//��λ�����
//	if (index<1) {
//		return 0;
//	}
//	int count = 0;
//	LNode* p = L;
//	while (p!=NULL && count<index-1) {
//		p = p->next;
//		count++;
//	}
//	if (p==NULL)
//	{
//		return 0;
//	}
//	LNode* s = (Linklist)malloc(sizeof(LNode));
//	if (s == NULL)
//	{
//		return 0;
//	}
//	s->data = value;
//	s->next = p->next;
//	p->next = s;
//	return 1;
//	//��ĳ�����ǰ���������µĽ��������ͬ����巨�߼���Ϊ��
//	//ǰ�巨�����ں�巨�Ļ����϶����������ת��
//}
//
//int length(Linklist L) {
//	int count = 0;
//	LNode* p = L->next;
//	while (p!=NULL) {
//		p = p->next;
//		count++;
//	}
//	return count;
//}
//
//LNode* GetElem(Linklist L,int index) {
//	LNode* p = L->next;
//	int count = 0;
//	while (p!=NULL && count<index)
//	{
//		p = p->next;
//		count++;
//	}
//	return p;
//}
//
//
//int Linkdelete(Linklist L, int index) {//��λ��ɾ��
//	if (index < 1) {
//		return 0;
//	}
//	int count = 0;
//	LNode* p = L;
//	while (p->next!= NULL && count < index - 1) {
//		p = p->next;
//		count++;
//	}
//	if (p == NULL)
//	{
//		return 0;
//	}
//	LNode* s = p->next;
//	if (s==NULL)
//	{
//		return 0;
//	}
//	p->next = s->next;
//	free(s);
//	return 1;
//}
//
//LNode* LocateElem(Linklist L,int e) {
//	LNode* p = L->next;
//	while (p!=NULL &&p->data!=e)
//	{
//		p = p->next;
//	}
//	return p;
//}
//
//int main() {
//	Linklist p = NULL;
//	Linklist head=initiate(p);
//	append(head,10);
//	append(head,20);
//	append(head, 30);
//	Linkinsert(head,2,15);
//	printf("����%d�����\n", length(head));
//	for (int i = 0; i < length(head); i++)//��0�������ͷ���û�д洢���������
//	{
//		printf("%d  ", GetElem(head,i)->data);
//
//	}
//	printf("\n--------------------------------------------------------------\n");
//	Linkdelete(head, 2);
//	for (int i = 0; i < length(head); i++)//��0�������ͷ���û�д洢���������
//	{
//		printf("%d  ", GetElem(head, i)->data);
//
//	}
//	printf("\n%d",GetElem(head,2)->data);
//}