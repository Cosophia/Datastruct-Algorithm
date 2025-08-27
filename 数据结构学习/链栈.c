#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct Linknode {
	ElemType data;
	struct Linknode* next;
}Linknode, * Linkstack;



int Initate(Linknode* L) {//链栈的插入和删除与单链表的插入和删除有着异曲同工之妙
	L = (Linkstack)malloc(sizeof(Linknode));
	if (L == NULL)
	{
		return 0;
	}
	else
	{
		L->next = NULL;
		printf("初始化成功!\n");
		return 1;
	}
}



int Linkinsert_head(Linknode* L, ElemType value) {//栈的特性则要求使用头插法，则在头结点之后插入,于是无需向后遍历查找到最后一个节点再插入
	Linknode* p = L;
	int count = 0;
	Linknode* s = (Linkstack)malloc(sizeof(Linknode));
	s->data = value;
	s->next = p->next;
	p->next = s;
	return 1;
}

int Linkdelete_head(Linknode* L)
{
	Linknode* p = L->next;
	L->next = p->next;
	free(p);
	return 1;

}

Linknode* LocateElem(Linknode* L) {
	return L->next;
}


int main() {
	Linknode li;
	Initate(&li);

	for (int i = 0; i < 3; i++)
	{
		Linkinsert_head(&li, i + 1);
	}
	Linkdelete_head(&li);
	Linkdelete_head(&li);
	printf("%d", LocateElem(&li)->data);
}