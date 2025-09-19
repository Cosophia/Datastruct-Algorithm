#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct ThreadBiTnode {
	ElemType data;
	struct ThreadBiTnode* left_children, * right_children;
	int tag_left, tag_right;
}ThreadBiTnode;

ThreadBiTnode* pre = NULL;

void Threading(ThreadBiTnode* TB) {
	if (TB->left_children == NULL)//����ǰ������
	{
		TB->left_children = pre;
		TB->tag_left = 1;
	}
	if (pre != NULL && TB->right_children == NULL)//����������� ����ָ���ƶ�����һ���ڵ�ʱ���ж���������Ե�һ��������
	{
		pre->right_children = TB;
		pre->tag_right = 1;
	}
	pre = TB; //ǰ��ָ��ָ��ǰ��㣬Ϊ�´ν���ǰ��/���������ṩ����
}

void InThread(ThreadBiTnode* TB) {
	InThread(TB->left_children);
	Threading(TB);
	InThread(TB->right_children);
}

void preThread(ThreadBiTnode* TB) {
	Threading(TB);
	if (TB->tag_left == 0)
	{
		preThread(TB->left_children);//��ֹתȦ

	}
	preThread(TB->right_children);
}

void CreateThreadThree(ThreadBiTnode* T) {
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);
		if (pre->right_children == NULL) //���Ľڵ���û�к�̵� �����ƶ������Ľڵ��ʱ����������ָ��Ľڵ���һ�µ�
			//��ʱ���һ���ڵ���Һ���Ϊ�գ������ڴ��������н�������Ϊ�յ��������
		{
			pre->tag_right = 1;
		}
	}
}

void CreateThreadThree(ThreadBiTnode* T) {
	pre = NULL;
	if (T != NULL)
	{
		preThread(T);
		if (pre->right_children == NULL)
		{
			pre->tag_right = 1;
		}
	}
}


void CreateThreadThree(ThreadBiTnode* T) {
	pre = NULL;
	if (T != NULL)
	{
		postThread(T);
		if (pre->right_children == NULL)
		{
			pre->tag_right = 1;
		}
	}
}



void postThread(ThreadBiTnode* TB) {
	postThread(TB->left_children);
	postThread(TB->right_children);
	Threading(TB);

}


