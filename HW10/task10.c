/*
Строка и цифры
Считать число N из файла input.txt.
Сформировать строку из N символов. N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0,
на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
Результат записать в файл output.txt*/

#include <stdio.h>

int find_number(char *ch)
{
	int tmp, number = 0;
	for (int i = 0; i < 2; i++)
	{
		tmp = ch[i] - '0';
		number = number * 10 + tmp;
	}
	return number;
}

void string_number(char *ch)
{
	int i = 0;
	printf("%d", find_number(ch));
}

int main(void)
{
	FILE *input;
	int i = 0;
	char c, ch[2];
	input = fopen("input.txt", "r");
	while ((c = fgetc(input)) != EOF && (c != '\n'))
		ch[i++] = c;
	fclose(input);
	printf("\n");
	string_number(ch);
	return 0;
}