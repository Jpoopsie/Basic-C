/*
Удалить пробелы из текста
В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
Для решения задачи разработать функцию.
Результат записать в output.txt.*/

#include <stdio.h>

/*Удаляю все пробелы из файла*/
char *delete_space(char *string, int number, int *sizeArr)
{
	int size = 0;
	static char array[1000];
	for (int i = 0; i < number; i++)
	{
		if (string[i] != ' ')
			array[size++] = string[i];
	}
	*sizeArr = size;
	return array;
}

/*Возвращение пробелов в массив*/
char *return_space(char *string, int number, int *sizeArr)
{
	int size = 0, sizeArray, count = 0, s = 0, d = 0;
	static char array[1000];
	char *mainArray = delete_space(string, number, &sizeArray);
	if (string[0] != ' ')
	{
		for (int i = 0; i < number; i++)
		{
			while (string[i] == ' ')
			{
				count++;
				i++;
			}
			if (count >= 1)
			{
				array[size++] = ' ';
				count = 0;
				i--;
			}
			else
				array[size++] = mainArray[s++];
		}
	}
	else
	{
		while (string[d] == ' ')
			d++;
		for (int i = d; i < number; i++)
		{
			while (string[i] == ' ')
			{
				count++;
				i++;
			}
			if (count >= 1)
			{
				array[size++] = ' ';
				count = 0;
				i--;
			}
			else
				array[size++] = mainArray[s++];
		}
	}
	*sizeArr = size;
	return array;
}

/*Запись в output file*/
void write_file(char *string, int number)
{
	FILE *output;
	int size;
	char *mainArray = return_space(string, number, &size);
	output = fopen("output.txt", "w");
	for (int i = 0; i < size; i++)
		fprintf(output, "%c", mainArray[i]);
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
	fclose(input);
	write_file(string, size);
	return 0;
}