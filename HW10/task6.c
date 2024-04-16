/*Проверка на палиндром
В файле input.txt символьная строка не более 1000 символов. Необходимо проверить, является ли она палиндромом (палиндром читается одинаково в обоих направлениях). Реализовать логическую функцию is_palindrom(str) и записать ответ в файл output.txt.
Формат входных данных
Строка из заглавных английских букв
Формат результата
YES или NO
Примеры
Входные данные в файле input.txt
ABCDEF
Результат работы в файле output.txt
NO
Входные данные в файле input.txt
KAZAK
Результат работы в файле output.txt
YES*/

#include <stdio.h>

#define MAX_SIZE 1000

char is_palindrom(char str[], int size)
{
	for(int i = 0; i < size / 2; ++i)
	{
		if(str[i] != str[size - i - 1])
			return 0;
	}
	return 1;
}

int main(void)
{
	FILE *input, *output;
	char str[MAX_SIZE] = {0}, ch;
	int i = 0, count = 0;
	input = fopen("input.txt", "r");
	while((ch = fgetc(input)) != EOF && (ch != '\n'))
		{
		str[i++] = ch;
		count++;
		}
	fclose(input);
	output = fopen("output.txt", "w");
	if(is_palindrom(str, count))
		fprintf(output, "YES\n");
	else
		fprintf(output, "NO\n");
	return 0;
}