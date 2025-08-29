#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Linknode {
	ElemType data;
	struct Linknode* next;
}Linknode;

typedef struct {
	Linknode* front, * rear;
}Linkqueue;

int Initate(Linkqueue* Q) {
	if (Q == NULL)
	{
		return 0;
	}
	Linknode* head = (Linknode*)malloc(sizeof(Linknode));
	if (head == NULL)
	{
		return 0;
	}
	else
	{
		Q->front = head;
		Q->rear = head;
		Q->front->next = NULL;
		printf("�������!\n");
		return 1;
	}
}

int Enqueue(Linkqueue* Q, ElemType value) {
	Linknode* newnode = (Linknode*)malloc(sizeof(Linknode));
	if (newnode == NULL)
	{
		return 0;
	}
	newnode->data = value;
	newnode->next = NULL;
	Q->rear->next = newnode;
	Q->rear = newnode;
	printf("Ԫ��%d���\n", newnode->data);
	return 1;
}

int Dequeue(Linkqueue* Q) {
	if (Q->front == Q->rear)
	{
		printf("����Ϊ�գ�");
		return 0;
	}
	else
	{
		Linknode* p = Q->front->next;
		Q->front->next = p->next;
		printf("%d���ӳɹ�\n", p->data);
		if (p = Q->rear)
		{
			Q->rear = Q->front;
		}

		free(p);
		return 1;
	}
}

ElemType GetElem(Linkqueue* Q) {
	if (Q->front->next == NULL) return 0;
	else return Q->front->next->data;
}

int main()
{
	Linkqueue ln;
	Initate(&ln);
	for (int i = 0; i < 5; i++)
	{
		Enqueue(&ln, i + 1);

	}
	printf("��ͷ��%d\n", GetElem(&ln));
	Dequeue(&ln);
	printf("��ͷ��%d", GetElem(&ln));

	return 1;
}
