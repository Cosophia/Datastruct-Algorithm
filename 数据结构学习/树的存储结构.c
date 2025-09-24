#include<stdio.h>
#define maxsize 20

typedef int Element;

/*双亲表示法*/
typedef struct {
	Element data;
	int parent;
}PTnode;

typedef struct {
	PTnode nodes[maxsize];
	int node_number;
}Ptree;
//树的形式用数组表述，每个数组的元素能够存储该结点的数据以及父结点所在的下标

//劣势：寻找孩子节点时只能通过遍历找到对应的父结点


/*孩子表示法*/
typedef struct CTNode {
	int child;
	struct CTNode* next;
};
typedef struct {
	Element data;
	struct CTNode* firstChild;
}CTBox;
typedef struct {
	CTBox nodes[maxsize];
	int nodes_num, root_num;
}CTree;
//树的形式用数组表述，每个数组的元素能够存储该结点的数据和其所有孩子用链表的形式存储
//劣势：寻找双亲节点不方便，只能遍历每个顺序表中每一个链表才能找到

/*孩子兄弟表示法*/

typedef struct CSNode {
	Element data;
	struct CSNode* firstchild, * nextsibing
}CSnode;

//树的构成是由相对根节点的左枝为其（从左往右）的长子，右枝为该根节点的兄弟