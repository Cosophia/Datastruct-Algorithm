#include<stdio.h>
#include<stdlib.h>
#define Maxsize 225

typedef struct SString {//��̬����(����˳��洢)
	char word[Maxsize];
	int length;
}SString;


typedef struct HString {//��̬����(�Ƕ���˳��洢)
	char* word;
	int length;
}HString;



//��̬����ķ���
int Initate(HString* s) {
	int Initate;
	printf("�������Ҫ����Ŀռ��С:");
	scanf_s("%d", &Initate);
	if (Initate <= 0) return 0;
	s->word = (char*)malloc(Initate * sizeof(char));
	s->length = 0;
	return 1;
}

void StrAssign(HString* T, char* chars) {//�ַ�����ֵ,����һ����
	for (int i = 0; chars[i] != '\0'; i++)
	{
		T->word[i] = chars[i];
		T->length += 1;
	}
	T->word[T->length] = '\0';
}

int String_length(HString* T) {//�󴮳�
	return T->length;
}

void clear_string(HString* T) {//��մ�
	free(T->word);
	T->length = 0;
}

int isEmpty(HString* T) {//�п�
	if (T->length == 0) return 1;
	else return 0;
}

int string_cmp(HString* T, HString* S) {//�Ƚϴ�
	int time = T->length < S->length ? T->length : T->length;
	for (int i = 0; i < time; i++)
	{
		if (T->word[i] != S->word[i])
		{
			return T->word[i] - S->word[i];
		}
	}
	return T->length - S->length;
}

int string_concat(HString* T, const HString s1, const HString s2) {
	if (T->word) {
		free(T->word);
		T->word = NULL;
	}
	int k = 0;
	T->length = s1.length + s2.length;
	T->word = (char*)malloc(T->length * sizeof(char));
	for (int i = 0; i < s1.length; i++) T->word[k++] = s1.word[i];
	for (int i = 0; i < s2.length; i++) T->word[k++] = s2.word[i];
	T->word[T->length] = '\0';
	return 1;
}

int Substring(const HString* T, HString* sub, int position, int len) {
	if (position < 0 || position >T->length || len < 0 || len >T->length - position)
	{
		return 0;
	}
	if (sub->word)
	{
		free(sub->word);
		sub->word = NULL;
	}
	sub->length = len;
	sub->word = (char*)malloc((len + 1) * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		sub->word[i] = T->word[position + i];
	}
	sub->word[len] = '\0';
	return 1;
}

int main() {
	HString str1;
	Initate(&str1);
	StrAssign(&str1, "chars");
	printf("%s", str1.word);



	return 0;
}