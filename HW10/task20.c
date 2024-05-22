/*
Ling заменить на Cao
В файле input.txt дано предложение.
Необходимо заменить все имена «Ling» на «Cao» и результат записать в файл output.txt.*/

#include <stdio.h>

/*Считываем массив и заменяем слова*/
char *change(char *string, int number, int *sizeArr)
{
	static char array[1000];
	int size = 0;
	for (int i = 0; i < number; i++)
	{
		if (string[i] == 'L' && string[i + 1] == 'i' && string[i + 2] == 'n' && string[i + 3] == 'g')
		{
			array[size++] = 'C';
			array[size++] = 'a';
			array[size++] = 'o';
			i += 3;
		}
		else
			array[size++] = string[i];
	}
	*sizeArr = size;
	return array;
}

/*Запись в output file*/
void write_file(char *string, int number)
{
	FILE *output;
	int size;
	char *array = change(string, number, &size);
	output = fopen("output.txt", "w");
	for (int i = 0; i < size; i++)
		fprintf(output, "%c", array[i]);
	fclose(output);
}

int main(void)
{
	FILE *input;
	char ch, string[1000];
	int count = 0;
	input = fopen("input.txt", "r");
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
		string[count++] = ch;
	fclose(input);
	write_file(string, count);
	return 0;
}