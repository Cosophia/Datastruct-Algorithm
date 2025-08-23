#include<stdio.h>
#include<stdlib.h>

typedef struct LoopDLode {
	int data;
	struct LoopDLode* prior, * next;
}LoopDLode, * LoopDLinklist;

LoopDLinklist Initate(LoopDLinklist L) {
	L = (LoopDLode*)malloc(sizeof(LoopDLode));
	if (L == NULL)
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

int LoopDLodeinsert(LoopDLinklist L, int index, int value) {
	LoopDLinklist p = L;
	int count = 0;
	while (p->next != L && count < index - 1)
	{
		p = p->next;
		count++;
	}
	if (p == NULL)
	{
		return 0;
	}
	LoopDLinklist s = (LoopDLinklist)malloc(sizeof(LoopDLode));
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
	LoopDLinklist p = L;
	while (p->next != L)
	{
		p = p->next;
		printf("%d  ", p->data);

	}


}

int LoopDLodedelete(LoopDLinklist L, int index)
{
	LoopDLinklist p = L;
	if (p == NULL)
	{
		return 0;
	}
	int count = 0;
	while (p->next != L && count < index - 1)
	{
		p = p->next;
		count++;
	}
	LoopDLinklist s = p->next;
	p->next = s->next;
	s->next->prior = s->prior;
	free(s);
	return 1;
}



LoopDLinklist GetElem(LoopDLinklist L, int index) {
	if (index < 1)
	{
		return NULL;
	}
	LoopDLinklist p = L->next;
	int count = 0;
	while (count < index - 1)
	{
		p = p->next;
		count++;
	}
	return p;
}

int main() {
	LoopDLinklist Li = NULL;
	LoopDLinklist L = Initate(Li);
	LoopDLodeinsert(L, 1, 10);
	LoopDLodeinsert(L, 2, 20);
	LoopDLodeinsert(L, 3, 30);
	LoopDLodeinsert(L, 4, 40);
	printf("\n");
	search(L);
	LoopDLodedelete(L, 1);
	printf("\n");
	search(L);
	printf("\n");
	printf("%d", GetElem(L, 3)->data);
	return 0;
}