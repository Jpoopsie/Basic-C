/*
Удалить повторяющиеся символы
В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов.
Требуется удалить из нее повторяющиеся символы и все пробелы.
Результат записать в файл output.txt.*/

#include <stdio.h>

/*Убираю все пробелы в строке*/
char *remove_space(char *string, int number)
{
	static char array[1000];
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		if (string[i] != ' ')
			array[count++] = string[i];
	}
	return array;
}

/*Удаление повторяющихся значений*/
char *remove_repeating(char *string, int number, int *sizeArr)
{
	static char array[1000];
	int count = 0;
	char *space = remove_space(string, number);
	for (int i = 0; i < number; i++)
		array[count++] = space[i];
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (array[i] == array[j])
			{
				for (int k = j; k < count - 1; k++)
					array[k] = array[k + 1];
				count--;
				j--;
			}
		}
	}
	*sizeArr = count;
	return array;
}

/*Запись в ouput file*/
void write_output(char *string, int number)
{
	FILE *output;
	int size = 0;
	char *array = remove_repeating(string, number, &size);
	output = fopen("output.txt", "w");
	printf("%d\n", size);
	for (int i = 0; i < size - 1; i++)
		fprintf(output, "%c", array[i]);
	fclose(output);
	for (int i = 0; i < size; i++)
		printf("%c", array[i]);
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
	write_output(string, count);
	return 0;
}

/*Доделать Output*/