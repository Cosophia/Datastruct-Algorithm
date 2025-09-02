#include<stdio.h>
#include<stdlib.h>

typedef struct HString {
	char* word;
	int length;
}HString;


void Initate(HString* T) {
	printf("请输入您要分配的空间大小:");
	int initate;
	scanf_s("%d", &initate);
	if (Initate <= 0)printf("输入有误::");
	else {
		T->word = (char*)malloc(initate * sizeof(char));
		T->length = 0;
		printf("分配成功!\n");
	}
}

int* get_next(HString M) {
	int* next = (int*)malloc((M.length) * sizeof(int));
	next[0] = -1;
	int i = 0, j = -1;
	while (i < M.length)
	{
		if (j == -1 || M.word[i] == M.word[j])
		{
			++i; ++j;
			if (i <= M.length) next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}

	return next;
}

void StrAssign(HString* T, char* chars) {
	if (T->length > 0)
	{
		free(T->word);
		T->word = NULL;
	}
	else
	{
		for (int i = 0; chars[i] != '\0'; i++)
		{
			T->word[i] = chars[i];
			T->length += 1;
		}
		T->word[T->length] = '\0';
	}
}

int match(HString M, HString T, int* next) {//kmp match
	int i = 0, j = 0;
	int flag = 0;
	while (i <= M.length && j <= T.length && flag < T.length)
	{
		if (M.word[i] == T.word[j])
		{
			flag += 1;
			i++;
			j++;
		}
		else
		{
			if (j == -1)
			{
				i = i - j + 1;
				j = 0;
			}
			else j = next[j];
		}
	}
	if (j > T.length || flag == T.length) {
		printf("匹配成功!\n");
		return i - T.length;
	}
	else return 0;
}

int main() {
	HString str1, str2;
	Initate(&str1);
	Initate(&str2);
	StrAssign(&str1, "gollabcogoole");
	StrAssign(&str2, "goole");
	//printf("%d",str1.length);
	int* next = get_next(str2);
	printf("next数组为:\n");
	for (int i = 0; i < str2.length; i++)
	{
		printf("%d ", next[i] + 1);
	}
	printf("\n");
	match(str1, str2, next);
	return 1;
}