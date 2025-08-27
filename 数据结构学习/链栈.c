#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct Linknode {
	ElemType data;
	struct Linknode* next;
}Linknode, * Linkstack;



int Initate(Linknode* L) {//��ջ�Ĳ����ɾ���뵥����Ĳ����ɾ����������ͬ��֮��
	L = (Linkstack)malloc(sizeof(Linknode));
	if (L == NULL)
	{
		return 0;
	}
	else
	{
		L->next = NULL;
		printf("��ʼ���ɹ�!\n");
		return 1;
	}
}



int Linkinsert_head(Linknode* L, ElemType value) {//ջ��������Ҫ��ʹ��ͷ�巨������ͷ���֮�����,�����������������ҵ����һ���ڵ��ٲ���
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