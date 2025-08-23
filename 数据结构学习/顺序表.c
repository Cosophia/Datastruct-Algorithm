#include<stdio.h>
#include<stdlib.h>
#define Maxmone 300;

typedef int Elemtype;


//动态分配
typedef struct  {
	Elemtype* data;
	int length,Maxsize;
}SeqList;

void initList(SeqList* L) {
	printf("请输出您要分配的大小：");
	int InitiSize;
	scanf_s("%d",&InitiSize);
	L->data = (Elemtype*)malloc(InitiSize*sizeof(Elemtype));
	L->length = 0;
	L->Maxsize = InitiSize;
}

int isnull(SeqList* L) {
	if (L->Maxsize == 0) return 1;
	else return 0;	
}

int insert(SeqList* L,int index,Elemtype value) {//index表示的是要插入的位置，value表示的是要插入的值
	if (index < 1 || index > L->length+1) {//判断插入的位置是否合法
		printf("插入失败\n");
		return 0;
	}
	if (L->length -1 >= L->Maxsize) {//判断顺序表能够再插入
		printf("插入失败\n");
		return 0;
	}
	else {
		for (int i = L->length-1; i >=index -1; i--)
		{//将元素后移
			 L->data[i] = L->data[i-1];
		}
		L->data[index-1] = value;
		L->length += 1;
	}
	return 1;
}

int search(SeqList* L) {
	for (int i = 0; i < L->Maxsize; i++)
	{
		printf("%d  ", L->data[i]);
	}
}


int Seqdelete (SeqList* L,int index, Elemtype value) {
	if (index < 1 || index > L->length) {
		printf("插入失败!");
		return 0;
	}
	value = L->data[index-1];
	printf("顺序表中位于%d的值:%d",index,value);
	for (int i = index; i < L->length; i++){//前移包括当前位
		L->data[i-1] = L->data[i];
	}
	L->length -= 1;
	return 1;
}

int modify(SeqList* L, int index, Elemtype value) {
	if (index < 0 || index > L->length - 1)
	{
		printf("所要查找的值不存在!");
		return 0;
	}
	else
	{
		for (int i = 0; i < L->length; i++)
		{
			if (i==index-1)
			{
				L->data[i] = value;
			}
		}
	}
}


void append(SeqList* L,int value) {
	L->data[L->length] = value;
	L->length += 1;
}

Elemtype GetElem(SeqList* L,int index) {
	return L->data[index-1];
}

int LocateElem(SeqList* L,int value) {
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == value)
		{
			return i + 1;
		}
	}
	return 0;
}

int main() {
	SeqList L;
	initList(&L);
	printf("顺序表初始化成功,该表最大的空间大小为:%d\n",L.Maxsize);
	int isnull_res= isnull(&L);
	if (isnull_res == 1) printf("顺序表为空!\n");
	else printf("顺序表不为为空\n");
	for (int i = 0; i < L.Maxsize; i++)
	{
		append(&L,i*i+5);
		printf("%d  ", L.data[i]);
	}
	printf("\n");
	insert(&L, 3, 666);
	printf("插入后的结果:");
	search(&L);
	printf("\n");
	int spot = 0;
	int res = Seqdelete(&L,3,spot);
	printf("\n");
	printf("删除后的结果:");
	search(&L);
	printf("\n");
	int value;
	printf("输入修改后的具体值:");
	scanf_s("%d",&value);
	modify(&L,3,value);
	printf("修改后的结果:");
	search(&L);

}