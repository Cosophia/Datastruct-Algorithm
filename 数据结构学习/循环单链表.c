#include<stdio.h>
#include<stdlib.h>


typedef struct Looplink {
	int data;
	struct Looplink* next;
}Looplink, *LoopLinkList;

LoopLinkList Initate(Looplink* L) {
	L=(LoopLinkList)malloc(sizeof(Looplink));
	if (L==NULL)
	{
		return NULL;
	}
	else
	{
		L->data = 65536;
		L->next = L;
		printf("循环单链表的头结点分配完成!");
		return L;
	}
}

int isnull(Looplink* L)
{
	if (L->next == L) return 1;
	else return 0;
}

int isTail(Looplink* L,Looplink* p)
{
	if (p->next == L) return 1;
	else return 0;
}

int Looplinkinsert(LoopLinkList L,int index,int value)
{
	if (index<1)
	{
		return 0;
	}
	int count = 0;
	Looplink* p = L;
	while (p!=NULL && count<index-1)
	{
		p = p->next;
		count++;
	}
	if (p==NULL)
	{
		return 0;
	}
	Looplink* s = (LoopLinkList)malloc(sizeof(Looplink));
	if (s==NULL)
	{
		return 0;
	}
	s->data = value;
	s->next = p->next;
	p->next = s;
	return 1;
}

void search(LoopLinkList L) {
	LoopLinkList p = L;
	while (p->next!=L)
	{
		p = p->next;
		printf("%d  ",p->data);
	}
}

int Looplinkdelete(LoopLinkList L,int index) {
	if (index<1)
	{
		return 0;
	}
	LoopLinkList p = L; 
	int count = 0;
	while (p->next!=L && count<index-1)
	{
		p = p->next;
		count++;
	}
	LoopLinkList s = p->next;
	if (s==NULL)
	{
		return 0;
	}
	p->next = s->next;
	free(s);
	return 1;
}

LoopLinkList Getelem(LoopLinkList L,int index) {
	LoopLinkList p = L->next;
	int count = 0;
	while (p!=NULL && count<index-1)
	{
		p = p->next;
		count++;
	}
	return p;
}

int modify(LoopLinkList L,int index,int value) {
	LoopLinkList p = L->next;
	int count = 0;
	while (p!=NULL && count<index-1) {
		p = p->next;
		count++;
	}
	if (p==NULL)
	{
		return 0;
	}
	p->data = value;
	return 1;
}

int main() {
	LoopLinkList Li = NULL;
	LoopLinkList L = Initate(Li);
	Looplinkinsert(L, 1, 10);
	Looplinkinsert(L, 2, 20); 
	Looplinkinsert(L, 3, 30); 
	Looplinkinsert(L, 4, 40);
	printf("\n");
	search(L);
	Looplinkdelete(L,4);
	Looplinkinsert(L, 1, 11);
	printf("\n");
	search(L);
	modify(L,4,111);
	printf("\n%d", Getelem(L,3)->data);
	printf("\n");
	search(L);
	return 0;
}