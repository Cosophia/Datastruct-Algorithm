#include<stdio.h>
#include<stdlib.h>
#define Maxsize 20

typedef struct BiTnode {
	int data;
	struct BiTnode* left_children, * right_children;
}BiTnode;

typedef struct Sequeue {
	struct BiTnode data[Maxsize];
	int front, rear;
	int size;
}Sequeue;



void Bi_initate(BiTnode** B) {
	*B = malloc(sizeof(BiTnode));
	if (!*B)
	{
		printf("二叉树节点分配失败!\n");
	}
	else
	{
		(*B)->left_children = NULL;
		(*B)->right_children = NULL;
		printf("二叉树节点分配成功!\n");
	}
}

void Initate(Sequeue* Q) {
	for (int i = 0; i < Maxsize; i++)
	{
		Q->data->data = 0;
	}
	Q->front = 0;
	Q->rear = -1;
	Q->size = 0;
	printf("分配成功!\n");

}

void Enqueue(Sequeue* Q, BiTnode* b) {
	if (Q->size == Maxsize)
	{
		printf("分配空间已满\n");
	}
	else
	{
		Q->rear = (Q->rear + 1) % Maxsize;
		Q->data[Q->rear] = *b;
		Q->size += 1;
	}
}

void Dequeue(Sequeue* Q, BiTnode* current) {
	if (Q->size == 0)
	{
		printf("该队列为空!\n");
	}
	else
	{
		//printf("%d  ", Q->data[Q->front].data);
		*current = Q->data[Q->front];
		Q->front = (Q->front + 1) % Maxsize;
		Q->size -= 1;
	}
}

int GetElem(Sequeue* Q) {
	if (Q->size == 0)
	{
		printf("该队列为空!\n");
	}
	return Q->data[Q->front].data;
}


BiTnode* CreateArrayBiTree(int* array, int n) {
	BiTnode** nodes = malloc(n * sizeof(BiTnode*));
	if (!nodes)
	{
		printf("各个节点的指针分配失败!\n");
	}
	for (int i = 0; i < n; i++)
	{
		nodes[i] = malloc(sizeof(BiTnode));
		nodes[i]->data = array[i];
		nodes[i]->left_children = NULL;
		nodes[i]->right_children = NULL;
	}
	for (int i = 0; i < n; i++)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		if (left < n) nodes[i]->left_children = nodes[left];
		if (right < n) nodes[i]->right_children = nodes[right];
	}
	BiTnode* root = nodes[0];
	if (root)
	{
		printf("二叉树初始化成功!\n");
	}
	free(nodes);
	return root;
}

void HierarchyOrder(BiTnode* root, Sequeue* Q) {

	Enqueue(Q, root);
	BiTnode* cur = root;
	while (Q->size)
	{
		Dequeue(Q, cur);
		printf("%d  ", cur->data);
		if (cur->left_children)
		{
			Enqueue(Q, cur->left_children);
		}
		if (cur->right_children)
		{
			Enqueue(Q, cur->right_children);
		}

	}
}

int main() {
	Sequeue Q1;
	Initate(&Q1);
	//Enqueue(&Q1, 1);
	//Enqueue(&Q1, 2);
	//Enqueue(&Q1, 3);
	//Dequeue(&Q1);
	//Dequeue(&Q1);
	//for (int i = 0; i < Maxsize; i++)
	//{
	//	if (Q1.data[i]==0) continue;
	//	else printf("第%d位元素是:%d\n",i+1, Q1.data[i]);
	//}
	//BiTnode* B1 = NULL;
	//BiTnode* B2 = NULL;
	//BiTnode* B3 =NULL;
	//Bi_initate(&B1);
	//Bi_initate(&B2);
	//Bi_initate(&B3);
	//B1->left_children = B2;
	//B1->right_children = B3;
	//B2->data = 5;
	//B3->data = 9;
	//printf("%d",B1->left_children->data);
	//printf("%d", B1->right_children->data);
	int array[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	BiTnode* root = CreateArrayBiTree(array, sizeof(array) / sizeof(int));
	//printf("%d", root->left_children->right_children->data); 
	HierarchyOrder(root, &Q1);
	return 0;
}