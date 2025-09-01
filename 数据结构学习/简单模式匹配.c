#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char* word;
	int length;
}STring;


//动态分配的方法
int Initate(STring* s) {
	int Initate;
	printf("请输出您要分配的空间大小:");
	scanf_s("%d", &Initate);
	if (Initate <= 0) return 0;
	s->word = (char*)malloc(Initate * sizeof(char));
	s->length = 0;
	return 1;
}

void StrAssign(STring* T, char* chars) {//字符串赋值,生成一个串
	for (int i = 0; chars[i] != '\0'; i++)
	{
		T->word[i] = chars[i];
		T->length += 1;
	}
	T->word[T->length] = '\0';
}

int match(STring M, STring T) {
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
			i = i - j + 1;
			j = 0;
		}
	}
	if (j > T.length || flag == T.length) return i - T.length;
	else return 0;
}


int main() {
	STring s1, s2;
	Initate(&s1);
	Initate(&s2);
	StrAssign(&s1, "gollabcogoole");
	StrAssign(&s2, "abc");
	if (match(s1, s2) > 0)
	{
		printf("从%d个数开始能匹配到.\n", match(s1, s2));

	}
	else
	{
		printf("无法匹配到!\n");

	}

}

