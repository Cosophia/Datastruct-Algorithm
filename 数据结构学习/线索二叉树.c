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
	if (TB->left_children == NULL)//建立前驱线索
	{
		TB->left_children = pre;
		TB->tag_left = 1;
	}
	if (pre != NULL && TB->right_children == NULL)//建立后继线索 在主指针移动到下一个节点时该判断条件才相对第一次有意义
	{
		pre->right_children = TB;
		pre->tag_right = 1;
	}
	pre = TB; //前驱指针指向当前结点，为下次建立前驱/后驱线索提供基础
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
		preThread(TB->left_children);//防止转圈

	}
	preThread(TB->right_children);
}

void CreateThreadThree(ThreadBiTnode* T) {
	pre = NULL;
	if (T != NULL)
	{
		InThread(T);
		if (pre->right_children == NULL) //最后的节点是没有后继的 所以移动到最后的节点的时候则主副所指向的节点是一致的
			//此时最后一个节点的右孩子为空，所以在创建函数中将其设置为空的线索后继
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


