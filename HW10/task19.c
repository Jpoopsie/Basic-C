/*
Cao заменить на Ling
В файле input.txt дано предложение.
Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.*/

#include <stdio.h>

/*Замена слов*/
char *change(char *string, int number, int *sizeArr)
{
	static char array[2000];
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		if (string[i] == 'C' && string[i + 1] == 'a' && string[i + 2] == 'o')
		{
			array[count++] = 'L';
			array[count++] = 'i';
			array[count++] = 'n';
			array[count++] = 'g';
			i += 2;
		}
		else
			array[count++] = string[i];
	}
	*sizeArr = count;
	return array;
}

/*Вывод в output*/
void write_file(char *string, int number)
{
	FILE *output;
	int sizeArr;
	char *array = change(string, number, &sizeArr);
	output = fopen("output.txt", "w");
	for (int i = 0; i < sizeArr; i++)
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