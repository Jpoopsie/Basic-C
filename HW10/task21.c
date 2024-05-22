/*
Пары соседних символов
В файле input.txt записаны символы.
Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел.
Если количество символов нечетно (пробелы не считаем), то последний символ не меняем.
Результат записать в файл output.txt.*/

#include <stdio.h>

/*Удаляем пробелы и считаем количество символов в строке*/
char *count(char *string, int number, int *sizeArr)
{
	static char array[1000];
	int size = 0;
	for (int i = 0; i < number; i++)
	{
		if (string[i] != ' ')
			array[size++] = string[i];
	}
	*sizeArr = size;
	return array;
}

/*Меняем местами пары соседних символов*/
char *change(char *string, int size, int *sizeArray)
{
	int sizeArr;
	char tmp;
	char *array = count(string, size, &sizeArr);
	if (sizeArr % 2 == 1)
	{
		for (int i = 0; i < sizeArr - 1; i += 2)
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
		}
	}
	else
	{
		for (int i = 0; i < sizeArr; i += 2)
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
		}
	}
	*sizeArray = sizeArr;
	return array;
}

/*Возвращаем пробелы в массив*/
char *return_space(char *string, int size)
{
	static char array[1000];
	int sizeArr, k = 0, s = 0;
	char *mainArray = change(string, size, &sizeArr);
	for (int i = 0; i < size; i++)
	{
		if (string[i] == ' ')
			array[k++] = ' ';
		else
			array[k++] = mainArray[s++];
	}
	return array;
}

/*Запишем результат в output file*/
void write_file(char *string, int size)
{
	FILE *output;
	char *array = return_space(string, size);
	output = fopen("output.txt", "w");
	for (int i = 0; i < size; i++)
		fprintf(output, "%c", array[i]);
	fclose(output);
}

int main(void)
{
	FILE *input;
	char ch, string[1000];
	int size = 0;
	input = fopen("input.txt", "r");
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
		string[size++] = ch;
	write_file(string, size);
	return 0;
}