#include<stdio.h>
#include<stdlib.h>
#define Maxmone 300;

typedef int Elemtype;


//��̬����
typedef struct  {
	Elemtype* data;
	int length,Maxsize;
}SeqList;

void initList(SeqList* L) {
	printf("�������Ҫ����Ĵ�С��");
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

int insert(SeqList* L,int index,Elemtype value) {//index��ʾ����Ҫ�����λ�ã�value��ʾ����Ҫ�����ֵ
	if (index < 1 || index > L->length+1) {//�жϲ����λ���Ƿ�Ϸ�
		printf("����ʧ��\n");
		return 0;
	}
	if (L->length -1 >= L->Maxsize) {//�ж�˳����ܹ��ٲ���
		printf("����ʧ��\n");
		return 0;
	}
	else {
		for (int i = L->length-1; i >=index -1; i--)
		{//��Ԫ�غ���
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
		printf("����ʧ��!");
		return 0;
	}
	value = L->data[index-1];
	printf("˳�����λ��%d��ֵ:%d",index,value);
	for (int i = index; i < L->length; i++){//ǰ�ư�����ǰλ
		L->data[i-1] = L->data[i];
	}
	L->length -= 1;
	return 1;
}

int modify(SeqList* L, int index, Elemtype value) {
	if (index < 0 || index > L->length - 1)
	{
		printf("��Ҫ���ҵ�ֵ������!");
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
	printf("˳����ʼ���ɹ�,�ñ����Ŀռ��СΪ:%d\n",L.Maxsize);
	int isnull_res= isnull(&L);
	if (isnull_res == 1) printf("˳���Ϊ��!\n");
	else printf("˳���ΪΪ��\n");
	for (int i = 0; i < L.Maxsize; i++)
	{
		append(&L,i*i+5);
		printf("%d  ", L.data[i]);
	}
	printf("\n");
	insert(&L, 3, 666);
	printf("�����Ľ��:");
	search(&L);
	printf("\n");
	int spot = 0;
	int res = Seqdelete(&L,3,spot);
	printf("\n");
	printf("ɾ����Ľ��:");
	search(&L);
	printf("\n");
	int value;
	printf("�����޸ĺ�ľ���ֵ:");
	scanf_s("%d",&value);
	modify(&L,3,value);
	printf("�޸ĺ�Ľ��:");
	search(&L);

}