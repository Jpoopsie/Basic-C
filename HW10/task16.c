/*
Разобрать на слова
В файле input.txt дано предложение требуется разобрать его на отдельные слова.
Напечатать каждое слово на отдельной строке в файл output.txt.*/

#include <stdio.h>

/*Убрать пробелы спереди*/
char *delete_first_space(char *string, int size, int *arrSize)
{
	static char array[1000];
	int sizeArr = 0;
	int count = 0;
	if (string[0] == ' ')
	{
		while (string[count] == ' ')
			count++;
	}
	else
		count = 0;
	for (int i = count; i < size; i++)
		array[sizeArr++] = string[i];
	*arrSize = sizeArr;
	return array;
}
/*Удалить лишние пробелы*/
char *delete_space(char *string, int size, int *sizeArr)
{
	int fullSize = 0, arrSize;
	int count = 0;
	static char array[1000];
	char *first = delete_first_space(string, size, &arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		if (first[i] == ' ')
			count++;
		else
		{
			if (count >= 1)
				array[fullSize++] = ' ';
			array[fullSize++] = first[i];
			count = 0;
		}
	}
	*sizeArr = fullSize;
	return array;
}

/*Вместо пробелов ставим перенос строки и записываем в output file*/
void write_output(char *string, int size)
{
	FILE *output;
	int sizeArr;
	char *first = delete_space(string, size, &sizeArr);
	output = fopen("output.txt", "w");
	for (int i = 0; i < sizeArr; i++)
	{
		if (first[i] == ' ')
			fprintf(output, "\n");
		else
			fprintf(output, "%c", first[i]);
	}
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
	// while (scanf("%c", &ch))
	// {
	// 	if (ch == '\n')
	// 		break;
	// 	string[size++] = ch;
	// }
	write_output(string, size);
	return 0;
}