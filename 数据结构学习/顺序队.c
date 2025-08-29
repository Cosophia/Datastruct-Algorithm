#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10

typedef int ElemType;

typedef struct {
	ElemType data[Maxsize];
	int front, rear;
	int size;
}Sequeue;

//��̬����
int Initate(Sequeue* Q) {
	Q->front = 0;
	Q->rear = -1;
	Q->size = 0;
	printf("����ɹ�!");
	return 1;
}

ElemType Enqueue(Sequeue* Q, ElemType value) {
	if (Q->size == Maxsize)
	{
		printf("\n����Ϊ��!");
		return 0;
	}
	else
	{
		Q->rear = (Q->rear + 1) % Maxsize;
		Q->data[Q->rear] = value;
		Q->size += 1;
		return 1;
	}
}

ElemType Dequeue(Sequeue* Q, ElemType* rubish) {
	if (Q->size == 0)
	{
		printf("\n����Ϊ��!");
		return 0;
	}
	else
	{
		rubish = &Q->data[Q->front];
		//Q->data[Q->front] = 0;
		printf("\n��ǰ���ӵ�ֵΪ��ͷ:%d", *rubish);
		Q->front = (Q->front + 1) % Maxsize;
		Q->size -= 1;
		return 1;
	}
}

ElemType GetELem(Sequeue* Q) {
	if (Q->size == 0)
	{
		return 0;
	}
	else return Q->data[Q->front];
}

int main() {
	Sequeue q;
	ElemType val;
	Initate(&q);
	for (int i = 0; i < 10; i++)
	{
		if (Enqueue(&q, i + 1) == 0) break;
		printf("\nԪ��%d�������", i + 1);
	}
	GetELem(&q);
	printf("\nĿǰ��ͷΪ:%d", GetELem(&q));

	for (int i = 0; i < 4; i++)
	{
		if (Dequeue(&q, &val) == 0) break;
	}
	GetELem(&q);
	printf("\nĿǰ��ͷΪ:%d", GetELem(&q));

	for (int i = 0; i < 10; i++)
	{
		if (Dequeue(&q, &val) == 0) break;
	}
	GetELem(&q);
	printf("\nĿǰ��ͷΪ:%d", GetELem(&q));

	for (int i = 0; i < 5; i++)
	{
		if (Enqueue(&q, i + 1) == 0) break;
		printf("\nԪ��%d�������", i + 1);
	}
	GetELem(&q);
	printf("\nĿǰ��ͷΪ:%d", GetELem(&q));
	return 0;
}