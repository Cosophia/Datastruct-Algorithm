#include<stdio.h>
#include<stdlib.h>
typedef struct DLNode {
	int data;
	struct DLNode* prior;
	struct DLNode* next;
}DLNode,*DoubleLinkList;

int isnull(DLNode* L) {
	if (L->next == NULL)
	{
		return 1;
	}
	else return 0;
}

DoubleLinkList Initate(DLNode* L) {
	L= (DoubleLinkList)malloc(sizeof(DLNode));
	if (L==NULL)
	{
		return NULL;
	}
	else
	{
		L->prior = NULL;
		L->next = NULL;
		printf("初始化成功(带头结点)!");
		return L;
	}
}


int DLinkinsert(DLNode* L, int index,int value) {
	if (index<1)
	{
		return 0;
	}
	DLNode* p = L;
	int count = 0;
	while (p!=NULL && count<index-1) {//p->next!=NULL 意味着当前节点为最后一个结点
		p = p->next;                     //(头结点,最后一个有效结点]才可进行前插
		count ++;
	}
	if (p==NULL)
	{
		return 0;
	}
	DLNode* s = (DLNode*)malloc(sizeof(DLNode));
	if (s==NULL)
	{
		return 0;
	}
	s->data = value;
	s->next = p->next;
	/*if (p->next == NULL)
	{
		return 0;
	}*/
	 if (p->next != NULL) p->next->prior = s;
	/*if (p == NULL)
	{
		return 0;
	}*/
	p->next = s;
	s->prior = p;
	return 1;
}

void search(DLNode* L) {
	DLNode* p = L->next;
	while (p!=NULL) {
		printf("%d  ", p->data);
		p = p->next;
	}
}


int DLinkdelete(DLNode* L,int index){
	if (index<1)
	{
		return 0;
	}
	else
	{
		DLNode* p = L;//头结点
		int count = 0;
		while (p->next!=NULL && count<index-1)//p->next!=NULL 意味着当前节点为最后一个结点
		{
			p = p->next;//(头结点, 最后一个有效结点]才可进行结点的删除
			count++;
		}
		if (p==NULL)
		{
			return 0;
		}
		DLNode* s = p->next;
		if (s == NULL)
		{
			return 0;
		}
		p->next = s->next;
		if(s->next!=NULL) s->next->prior = p;
		free(s);
		return 1;
	}
}

DLNode* Getelem(DLNode* L,int index) {
	DLNode* p = L->next;
	int count = 0;
	while (p!=NULL && count<index-1)
	{
		//printf("%d  ", p->data);
		p = p->next;
		count++;
	}
	return p;
}

int main() {
	DoubleLinkList Li = NULL;
	DoubleLinkList L = Initate(Li);
	if (isnull(L)) printf("为空!");
	else  printf("不为空!");
	DLinkinsert(L,1,10);
	DLinkinsert(L,2,20);
	if (isnull(L)) printf("为空!");
	else  printf("不为空!");
	DLinkinsert(L, 3,15);
	search(L);
	DLinkdelete(L,3);
	printf("\n");
	search(L);
	printf("\n");
	DLinkinsert(L, 3, 15);
	DLinkinsert(L, 4, 45);
	DLinkinsert(L, 5, 55);
	printf("\n");
	search(L);
	printf("\n%d",Getelem(L, 5)->data);
	return 0;
}