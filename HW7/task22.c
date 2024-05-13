/*
Сумма цифр в тексте
Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте.
int digit_to_num(char c)*/

#include <stdio.h>

int digit_to_num(char c)
{
	int i;
	if (c >= '0' && c <= '9')
	{
		i = c - '0';
		return i;
	}
	return 0;
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
		if (digit_to_num(str[k]))
			count += digit_to_num(str[k]);
	}
	printf("%d\n", count);
	return 0;
}