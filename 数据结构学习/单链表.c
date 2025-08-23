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
//	//}这是不带头结点的写法
//	L = (LNode*)malloc(sizeof(LNode));//而带头结点的写法需要对该链表进行动态分配
//	if (L == NULL) {
//		perror("动态分配失败!");
//		exit(EXIT_FAILURE);
//	}
//	else
//	{
//		L->next = NULL;
//		printf("动态分配成功!");
//		return L;
//	}
//	
//}
//
//void append(Linklist L,int value) {//尾插法
//	LNode* Node = (LNode*)malloc(sizeof(LNode));//对结点进行初始化
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
//int Linkinsert(Linklist L,int index,Elemtype value) {//按位序插入
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
//	//对某个结点前或后面插入新的结点有所不同，后插法逻辑较为简单
//	//前插法则是在后插法的基础上对数据域进行转移
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
//int Linkdelete(Linklist L, int index) {//按位序删除
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
//	printf("共有%d个结点\n", length(head));
//	for (int i = 0; i < length(head); i++)//第0个结点是头结点没有存储具体的数据
//	{
//		printf("%d  ", GetElem(head,i)->data);
//
//	}
//	printf("\n--------------------------------------------------------------\n");
//	Linkdelete(head, 2);
//	for (int i = 0; i < length(head); i++)//第0个结点是头结点没有存储具体的数据
//	{
//		printf("%d  ", GetElem(head, i)->data);
//
//	}
//	printf("\n%d",GetElem(head,2)->data);
//}