/*
Проверка на палиндром
Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле получить одно слово - палиндром.
Ответ напечатать на стандартный поток вывода.
Требуется реализовать логическую функцию и применить ее.
is_palindrom(string)*/

#include <stdio.h>

char *delete_space(char *string, int size, int *sizeArr)
{
	int arrSize = 0;
	static char array[1000];
	for (int i = 0; i < size; i++)
	{
		if (string[i] != ' ')
			array[arrSize++] = string[i];
	}
	*sizeArr = arrSize;
	return array;
}

int main(void)
{
	int size = 0, arrSize;
	char ch, string[1000];
	while (scanf("%c", &ch))
	{
		if (ch == '\n')
			break;
		string[size++] = ch;
	}
	char *first = delete_space(string, size, &arrSize);
	for (int i = 0; i < arrSize; i++)
		printf("%c", first[i]);
	return 0;
}