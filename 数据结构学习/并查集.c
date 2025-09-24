#include<stdio.h>
#define maxsize 10

//由并查集的定义可知，并查集的设计利用双亲表示法更为合适，孩子或叶子结点可以通过双亲结点的下标逐层找到其所在树的根节点
typedef int Elementype;
typedef struct ConFin_node {
	Elementype data;
	int parent;
	int position;//下标信息，方便查询
}ConFin_node;

typedef struct ConFin_set {
	ConFin_node set[maxsize];
	int length;//记录该该树的长度
}ConFin_set;


void Initatal(ConFin_set* CFs) {
	for (int i = 0; i < maxsize; i++)
	{
		CFs->set[i].data = -1;
	}
}

void Find(ConFin_set* CFs, ConFin_node x) {
	while (CFs->set[x.position].parent >= 0) //该元素在并查集中所所对应的父节点是否大于0
	{
		x.position = CFs->set[x.position].parent;
	}
	return x;
}


void Union(ConFin_set* CFs, ConFin_node* root1, ConFin_node* root2) {
	if (root1->parent == root2->parent) {
		CFs->set[root2->position].parent = root1->position; //将r2并到r1下
	}
	else
	{
		printf("合并失败!\n");
	}
}

//利用小树合并大树的思路对Union进行合并，这是为了减少数的高度的增加
//法1：在有长度的字段之下进行比较
void Optimal_Union(ConFin_set* CFs, ConFin_set* set1, ConFin_set* set2) {
	if (set1->length > set2->length)
	{
		set2->set->parent = set1->set->position;
	}
	else
	{
		set1->set->parent = set2->set->position;
	}
}

//并查集的查找的优化：
ConFin_node super_optimal_Find(ConFin_set* CFs, ConFin_node x) {//压缩查找路径
	ConFin_node root = x;
	while (CFs->set[root.position].parent >= 0) root.position = CFs->set[root.position].parent;
	while (x.data != root.data) {
		int temp = CFs->set[x.position].parent;
		CFs->set[x.position].parent = root.position;
		x.position = temp;
	}
	return root;
}



