/*
Количество цифр в тексте
Составить логическую функцию, которая определяет, что текущий символ это цифра. Написать программу считающую количество цифр в тексте.
int is_digit(char c)*/

#include <stdio.h>

int is_digit(char c)
{
	return c >= '0' && c <= '9';
}

int main(void)
{
	char str[1000], ch;
	int count = 0, i = 0;
	while (scanf("%c", &ch) == 1)
	{
		if (ch == '\n')
			break;
		str[i++] = ch;
	}
	for (int k = 0; str[k] != '\0'; k++)
	{
		if (is_digit(str[k]))
			count++;
	}
	printf("%d\n", count);
	return 0;
}