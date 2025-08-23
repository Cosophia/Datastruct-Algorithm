#include<stdio.h>
#include<stdlib.h>

typedef struct LoopDLode {
	int data;
	struct LoopDLode *prior,*next;
}LoopDLode,*LoopDLinklist;

LoopDLinklist Initate(LoopDLinklist L) {
	L=(LoopDLode*)malloc(sizeof(LoopDLode));
	if (L==NULL)
	{
		return NULL;
	}
	else
	{
		L->prior = L;
		L->next = L;
		printf("循环双链表分配成功!");
	}
	return L;
}

int LoopDLodeinsert(LoopDLinklist L,int index,int value) {
	LoopDLinklist p = L;
	int count = 0;
	while (p->next!=L && count<index-1)
	{
		p = p->next;
		count++;
	}
	if (p==NULL)
	{
		return 0;
	}
	LoopDLinklist s=(LoopDLinklist)malloc(sizeof(LoopDLode));
	if (s == NULL)
	{
		return 0;
	}
	s->data = value;
	s->next = p->next;
	p->next->prior = s;
	if (p->next == NULL)
	{
		return 0;
	}
	p->next = s;
	s->prior = p;
	return 1;
}

void search(LoopDLinklist L) {
	LoopDLinklist p = L->next;
	while (p->next != L )
	{
		printf("%d  ",p->data);
		p = p->next;
	}
}

int main() {
	LoopDLinklist Li = NULL;
	LoopDLinklist L = Initate(Li);
	LoopDLodeinsert(L,1,10);
	LoopDLodeinsert(L, 2, 20);
	LoopDLodeinsert(L, 3, 30);
	LoopDLodeinsert(L, 4, 40);
	search(L);
	return 0;
}