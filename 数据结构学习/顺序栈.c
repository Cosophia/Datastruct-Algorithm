#include<stdio.h>
#define Maxsize 10

typedef int ElemType;

typedef struct {//��̬������ջ��Ԫ��
	ElemType data[Maxsize];
	int top;//ջ��ָ��
}Seqstack;


void Initate(Seqstack* S) {
	S->top = -1;
	printf("��ʼ���ɹ�!");
}

int StackEmpty(Seqstack* S) {
	if (S->top == -1) return 1;
	else return 0;
}

int push(Seqstack* S, int value) {
	if (S->top == Maxsize - 1)
	{
		return 0;
	}
	else
	{//����topָ��Ķ�����ָ��ջ��ջ��������ѹջʱҪ���ȸı�ջ��ָ��
		S->top += 1;
		S->data[S->top] = value;
		return 1;
	}
}

int pop(Seqstack* S, int value) {
	if (S->top == -1)
	{
		return 0;
	}
	else
	{//����topָ��Ķ�����ָ��ջ��ջ��������ѹջʱҪ���ȸı�ջ��ָ��
		int x;
		x = S->data[S->top];
		S->top -= 1;
		return 1;
	}
}

int GetTop(Seqstack* S) {
	if (S->top == -1) return 0;
	return S->data[S->top];
}

int modify(Seqstack* S, int index, int newvalue) {
	if (S->top == -1) return 0;
	else
	{
		int p = 0;
		while (p < index - 1)
		{
			p += 1;
		}
		return S->data[p] = newvalue;
	}
}

void search(Seqstack* S) {
	int p = 0;
	while (p <= S->top) {
		printf("%d  ", S->data[p]);
		p += 1;
	}
}

int main() {
	Seqstack s;
	Initate(&s);
	for (int i = 0; i < 5; i++)
	{
		push(&s, i + 1);
	}
	printf("\n");
	search(&s);
	printf("ջ��ֵΪ:%d\n", GetTop(&s));
	printf("�޸�����ֵ:%d", modify(&s, 2, 76));
	printf("\n");
	search(&s);
	printf("ջ��ֵΪ%d\n", GetTop(&s));
	return 0;
}