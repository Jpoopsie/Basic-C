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
char *sort_array(char *string, int size, int *mainArrSize)
{
	static char mainArray[1000];
	char dubleArr[1000] = {'\0'}, oneArr[1000] = {'\0'};
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
	int a = 0, b = arrSize - 1;
	for (int i = 0; i < arrSize; i++)
	{
		if (extArray[i] == extArray[i + 1])
		{
			dubleArr[a++] = extArray[i];
			dubleArr[b--] = extArray[i + 1];
			i++;
		}
	}
	int siziDuble = arrSize;
	for (int i = 0; i < siziDuble; i++)
	{
		if (dubleArr[i] == '\0')
		{
			for (int j = i; j < siziDuble; j++)
				dubleArr[j] = dubleArr[j + 1];
			i--;
			siziDuble--;
		}
	}
	int count = 1, sizeOne = 0;
	for (int i = 0; i < arrSize; i++)
		oneArr[i] = extArray[i];
	for (int i = 0; i < arrSize; i++)
	{
		count = 1;
		for (int j = i + 1; j < arrSize; j++)
		{
			if (extArray[i] == extArray[j])
			{
				count++;
				i++;
			}
		}
		if (count % 2 == 1)
			oneArr[sizeOne++] = extArray[i];
	}
	int mainSize = 0;
	for (int i = 0; i < siziDuble / 2; i++)
		mainArray[mainSize++] = dubleArr[i];
	for (int i = 0; i < sizeOne; i++)
		mainArray[mainSize++] = oneArr[i];
	for (int i = siziDuble / 2; i < siziDuble; i++)
		mainArray[mainSize++] = dubleArr[i];
	*mainArrSize = mainSize;
	return mainArray;
}

void is_palindrom(char *string, int size)
{
	int arrSize, count = 0, a = 0;
	char array[1000];
	char *mainArray = sort_array(string, size, &arrSize);
	int b = arrSize - 1;
	for (int i = 0; i < arrSize; i++)
		array[i] = mainArray[i];
	for (int i = 0; i < arrSize / 2; i++)
	{
		if (array[a++] == array[b--])
			count++;
	}
	if (count == arrSize / 2 && count >= 1)
		printf("YES");
	else
		printf("NO");
}

int main(void)
{
	FILE *input;
	input = fopen("input.txt", "r");
	int size = 0;
	char ch, string[1000];
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
		string[size++] = ch;
	fclose(input);
	// while (scanf("%c", &ch))
	// {
	// 	if (ch == '\n')
	// 		break;
	// 	string[size++] = ch;
	// }
	is_palindrom(string, size);
	return 0;
}