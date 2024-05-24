/*
Проверка на палиндром
Считать предложение из файла input.txt и определить можно ли из английских букв предложения записанного в файле получить одно слово - палиндром.
Ответ напечатать на стандартный поток вывода.
Требуется реализовать логическую функцию и применить ее.
is_palindrom(string)*/

#include <stdio.h>

/*Удаление пробелов в строке*/
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

/*Сортировка массива*/
char *sort_array(char *string, int size)
{
	static char mainArray[1000];
	char dubleArr[1000], oneArr[1000];
	int arrSize = 0;
	char *extArray = delete_space(string, size, &arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = i + 1; j < arrSize; j++)
		{
			if (extArray[i] > extArray[j])
			{
				char tmp = extArray[i];
				extArray[i] = extArray[j];
				extArray[j] = tmp;
			}
		}
	}
	for (int i = 0; i < arrSize; i++)
		dubleArr[i] = extArray[i];
	int a = 0, b = arrSize - 1;
	for (int i = 0; i < arrSize; i++)
	{
		if (extArray[i] == extArray[i + 1])
		{
			dubleArr[a++] = extArray[i];
			dubleArr[b--] = extArray[i + 1];
		}
	}
	
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
	char *first = sort_array(string, size);
	for (int i = 0; i < size; i++)
		printf("%c", first[i]);
	return 0;
}