#include<stdio.h>
#define maxsize 20

typedef int Element;

/*˫�ױ�ʾ��*/
typedef struct {
	Element data;
	int parent;
}PTnode;

typedef struct {
	PTnode nodes[maxsize];
	int node_number;
}Ptree;
//������ʽ�����������ÿ�������Ԫ���ܹ��洢�ý��������Լ���������ڵ��±�

//���ƣ�Ѱ�Һ��ӽڵ�ʱֻ��ͨ�������ҵ���Ӧ�ĸ����


/*���ӱ�ʾ��*/
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
//������ʽ�����������ÿ�������Ԫ���ܹ��洢�ý������ݺ������к������������ʽ�洢
//���ƣ�Ѱ��˫�׽ڵ㲻���㣬ֻ�ܱ���ÿ��˳�����ÿһ����������ҵ�

/*�����ֵܱ�ʾ��*/

typedef struct CSNode {
	Element data;
	struct CSNode* firstchild, * nextsibing
}CSnode;

//���Ĺ���������Ը��ڵ����֦Ϊ�䣨�������ң��ĳ��ӣ���֦Ϊ�ø��ڵ���ֵ�