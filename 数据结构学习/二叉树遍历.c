#include<stdio.h>
#include<stdlib.h>

typedef int Elemtype;

typedef struct BiTNode {
	Elemtype data;
	struct BiTNode* left_children, * right_children;
}BiTNode, * BiTree;

void visit(BiTNode Root) {
	printf("%d  ", Root.data);
}




void preOrder(BiTNode* Root) {
	if (Root != NULL)
	{
		visit(*Root);
		preOrder(Root->left_children);//移动到当前节点的左结点
		preOrder(Root->right_children);//移动当前节点的右结点
	}
}

void inOrder(BiTNode* Root) {
	if (Root != NULL)
	{
		inOrder(Root->left_children);
		visit(*Root);
		inOrder(Root->right_children);
	}
}

void lastOrder(BiTNode* Root) {
	if (Root != NULL)
	{
		lastOrder(Root->left_children);
		lastOrder(Root->right_children);
		visit(*Root);
	}
}

void Initate(BiTNode** root, Elemtype* value) {
	*root = (BiTNode*)malloc(sizeof(BiTNode));
	if (*root == NULL)
	{
		printf("分配失败!\n");
	}
	else
	{
		(*root)->data = *value;
		(*root)->left_children = NULL;
		(*root)->right_children = NULL;
		printf("分配成功!\n");
	}
}

int main() {
	BiTNode* root = NULL;
	BiTNode* b1 = NULL, * b2 = NULL;
	int a = 1, b = 2, c = 3;
	Initate(&root, &a);
	Initate(&b1, &b);
	Initate(&b2, &c); root->left_children = b1;
	root->right_children = b2;
	preOrder(root);
	printf("\n");
	inOrder(root);
	printf("\n");
	lastOrder(root);
	return 0;
}