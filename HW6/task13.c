/*Дан текст состоящий из английских букв и цифр, заканчивается символом «.» Перевести все заглавные английские буквы в строчные.*/

#include <stdio.h>

void to_lowercase(char str[])
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
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
	to_lowercase(&str[0]);
	for (int k = 0; k < count; k++)
		printf("%c", str[k]);
	return 0;
}