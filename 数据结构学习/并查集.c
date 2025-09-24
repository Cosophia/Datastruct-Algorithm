#include<stdio.h>
#define maxsize 10

//�ɲ��鼯�Ķ����֪�����鼯���������˫�ױ�ʾ����Ϊ���ʣ����ӻ�Ҷ�ӽ�����ͨ��˫�׽����±�����ҵ����������ĸ��ڵ�
typedef int Elementype;
typedef struct ConFin_node {
	Elementype data;
	int parent;
	int position;//�±���Ϣ�������ѯ
}ConFin_node;

typedef struct ConFin_set {
	ConFin_node set[maxsize];
	int length;//��¼�ø����ĳ���
}ConFin_set;


void Initatal(ConFin_set* CFs) {
	for (int i = 0; i < maxsize; i++)
	{
		CFs->set[i].data = -1;
	}
}

void Find(ConFin_set* CFs, ConFin_node x) {
	while (CFs->set[x.position].parent >= 0) //��Ԫ���ڲ��鼯��������Ӧ�ĸ��ڵ��Ƿ����0
	{
		x.position = CFs->set[x.position].parent;
	}
	return x;
}


void Union(ConFin_set* CFs, ConFin_node* root1, ConFin_node* root2) {
	if (root1->parent == root2->parent) {
		CFs->set[root2->position].parent = root1->position; //��r2����r1��
	}
	else
	{
		printf("�ϲ�ʧ��!\n");
	}
}

//����С���ϲ�������˼·��Union���кϲ�������Ϊ�˼������ĸ߶ȵ�����
//��1�����г��ȵ��ֶ�֮�½��бȽ�
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

//���鼯�Ĳ��ҵ��Ż���
ConFin_node super_optimal_Find(ConFin_set* CFs, ConFin_node x) {//ѹ������·��
	ConFin_node root = x;
	while (CFs->set[root.position].parent >= 0) root.position = CFs->set[root.position].parent;
	while (x.data != root.data) {
		int temp = CFs->set[x.position].parent;
		CFs->set[x.position].parent = root.position;
		x.position = temp;
	}
	return root;
}



