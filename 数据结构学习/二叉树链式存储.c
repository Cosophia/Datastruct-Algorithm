#include<stdio.h>
#include<stdlib.h>

typedef int Elemtpye;

typedef struct BiTreeNode {
	Elemtpye data;
	struct BiTreeNode* left_children, * right_children;
}BiTreeNode;


void node_Initate(BiTreeNode** node, Elemtpye* node_value) {
	*node = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	if (*node == NULL)
	{
		printf("分配失败!\n");
	}
	else
	{
		(*node)->data = *node_value;
		(*node)->left_children = NULL;
		(*node)->right_children = NULL;
		printf("分配成功!\n");
	}
	return;
}





int main() {
	BiTreeNode* root = NULL;
	BiTreeNode* n1, * n2;
	int a = 1, b = 2, c = 3;
	node_Initate(&root, &a);
	node_Initate(&n1, &b);
	node_Initate(&n2, &c);
	root->left_children = n1;
	root->right_children = n2;
	printf("%d\n", root->left_children->data);
	printf("%d\n", root->right_children->data);
	return 1;
}