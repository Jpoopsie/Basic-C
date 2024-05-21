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
char *remove_repeating(char *string, int number)
{
	static char array[1000];
	int count = 0;
	char *space = remove_space(string, number);
	for (int i = 0; i < number; i++)
	{
		int flag = 0;
		for (int j = 0; j < count; j++)
		{
			if (space[i] == space[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			array[count++] = space[i];
	}
	return array;
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
	for (int i = 0; i < count; i++)
		printf("%c", string[i]);
	printf("\n");
	char *first = remove_space(string, count);
	for (int i = 0; i < count; i++)
		printf("%c", first[i]);
	printf("\n");
	char *second = remove_repeating(string, count);
	for (int i = 0; i < count; i++)
		printf("%c", second[i]);
	return 0;
}