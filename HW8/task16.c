/*
Строка наоборот
Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
void reverse_string()*/

#include <stdio.h>
#include <locale.h>

void reverse(char *str)
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	if (*str)
	{
		reverse(str + 1);
		printf("%c", *str);
	}
}
int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	char a[1000], ch;
	int i = 0;
	while (scanf("%c", &ch) == 1)
	{
		if (ch == '.')
			break;
		a[i++] = ch;
	}
	reverse(a);
	return 0;
}