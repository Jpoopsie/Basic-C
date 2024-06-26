/*
Большими буквами
Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.*/

/*Дан текст состоящий из английских букв и цифр, заканчивается символом «.» Перевести все заглавные английские буквы в строчные.*/

#include <stdio.h>

void to_uppercase(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
	}
}

int main()
{
	char str[2000], ch;
	int i = 0, count = 0;
	while (scanf("%c", &ch) == 1)
	{
		if (ch == '\.')
			break;
		str[i++] = ch;
		count++;
	}
	to_uppercase(&str[0]);
	for (int k = 0; k < count; k++)
		printf("%c", str[k]);
	return 0;
}