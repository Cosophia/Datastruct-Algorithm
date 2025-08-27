#include<stdio.h>
#define Maxsize 10

typedef int ElemType;

typedef struct {//静态数组存放栈中元素
	ElemType data[Maxsize];
	int top;//栈顶指针
}Seqstack;


void Initate(Seqstack* S) {
	S->top = -1;
	printf("初始化成功!");
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
	{//由于top指针的定义是指向栈的栈顶，所以压栈时要将先改变栈顶指针
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
	{//由于top指针的定义是指向栈的栈顶，所以压栈时要将先改变栈顶指针
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
	printf("栈顶值为:%d\n", GetTop(&s));
	printf("修改完后的值:%d", modify(&s, 2, 76));
	printf("\n");
	search(&s);
	printf("栈顶值为%d\n", GetTop(&s));
	return 0;
}