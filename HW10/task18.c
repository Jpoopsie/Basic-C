/*
Hello name
В файле input.txt в одной строке фамилию, имя и отчество.
Сформировать файл приветствие output.txt, где останутся имя и фамилия*/

#include <stdio.h>

/*Нахождение фамилии в input file*/
char *last_name(char *string, int *sizeArr)
{
	static char first[100];
	int firstSize = 100, count = 0;
	for (int i = 0; i < firstSize; i++)
	{
		if (string[i] == ' ')
		{
			firstSize = count;
			for (int k = 0; k < firstSize; k++)
				first[k] = string[k];
			count = 0;
			break;
		}
		count++;
	}
	*sizeArr = firstSize;
	return first;
}

/*Нахождение имени в input file*/
char *first_name(char *string, int *sizeArr)
{
	static char second[100];
	int secondSize = 100, count = 0, firstSize;
	last_name(string, &firstSize);
	for (int i = firstSize + 1; i < secondSize; i++)
	{
		if (string[i] == ' ')
		{
			secondSize = count;
			for (int k = 0; k < secondSize; k++)
				second[k] = string[k + firstSize + 1];
			count = 0;
			break;
		}
		count++;
	}
	*sizeArr = secondSize;
	return second;
}

/*Запись в output file*/
void write_file(char *string)
{
	FILE *output;
	int firstSize;
	int secondSize;
	char *first = first_name(string, &firstSize);
	char *second = last_name(string, &secondSize);
	output = fopen("output.txt", "w");
	fprintf(output, "Hello, ");
	for (int i = 0; i < firstSize; i++)
		fprintf(output, "%c", first[i]);
	fprintf(output, " ");
	for (int i = 0; i < secondSize; i++)
		fprintf(output, "%c", second[i]);
	fprintf(output, "!");
	fclose(output);
}

int main(void)
{
	FILE *input;
	int count = 0;
	char ch, string[100];
	input = fopen("input.txt", "r");
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
		string[count++] = ch;
	fclose(input);
	write_file(string);
	return 0;
}