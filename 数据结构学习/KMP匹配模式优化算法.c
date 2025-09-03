#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char* word;
	int length;
}HString;


void Initate(HString* T) {
	int initate;
	printf("«Î ‰»Î∑÷≈‰ø’º‰¥Û–°:");
	scanf_s("%d", &initate);
	if (initate <= 0)
	{
		printf("∑÷≈‰ ß∞‹!\n");
	}
	else
	{
		T->word = (char*)malloc(initate * sizeof(char));
		T->length = 0;
	}
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


int* get_nextval(HString M) {
	int i = 0, j = -1;
	int* nextval = (int*)malloc((M.length + 1) * sizeof(int));
	if (nextval==NULL)
	{
		printf("∑÷≈‰ ß∞‹!\n");
		return NULL;
	}
	nextval[0] = -1;
	while (i < M.length) {
		if (j == -1 || M.word[i] == M.word[j])
		{
			++i; ++j;
			if (M.word[i] != M.word[j])
			{
				nextval[i] = j;
			}
			else
			{
				nextval[i] = nextval[j];
			}
		}
		else
		{
			j = nextval[j];
		}
	}
	nextval[M.length] = '\0';
	return nextval;
}

int match(HString M, HString T, int* nextval) {
	int i = 0, j = 0;
	while (i <= M.length && j <= T.length) {
		if (M.word[i] == T.word[j])
		{
			++i; ++j;
		}
		else
		{
			if (j == -1)
			{
				i += 1;
				j = 0;
			}
			else j = nextval[j];
		}
	}
	if (j > T.length)
	{
		printf("∆•≈‰≥…π¶!\n");
		return i - T.length;
	}
	else {
		printf("∆•≈‰ ß∞‹!\n");
		return 0;
	}
}


int main() {
	HString str1, str2;
	Initate(&str1);
	Initate(&str2);
	StrAssign(&str1, "ababccdaabaac");

	StrAssign(&str2, "abaac");
	int* nextval = get_nextval(str2);
	for (int i = 0; i < str2.length; i++)
	{
		printf("%d  ", nextval[i]);
	}
	match(str1, str2, nextval);
	return 1;
}

