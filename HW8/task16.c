/*
Строка наоборот
Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
void reverse_string()*/

#include <stdio.h>

void reverse(char *str, int len)
{
	if (len)
	{
		reverse(str + 1, len - 1);
		printf("%c", *str);
	}
}

int main()
{
	char a[1000], ch;
	int i = 0;
	int str_len;
	while ((ch = getchar()) != '.' && ch != EOF)
	{
		a[i++] = ch;
		str_len = i;
		a[str_len] = '\0';
	}
	reverse(a, str_len);
	return 0;
}