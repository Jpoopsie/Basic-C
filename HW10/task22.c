/*
Удалить пробелы из текста
В файле input.txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы).
Для решения задачи разработать функцию.
Результат записать в output.txt.*/

#include <stdio.h>

/*Удаляю все пробелы из файла*/
char *delete_space(char *string, int number, int *sizeArr)
{
	int size;
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
char *return_space(char *string, int number)
{
	int size = 0, sizeArray, count = 0, s = 0;
	static char array[1000];
	char *mainArray = delete_space(string, number, &sizeArray);
	if (string[0] != ' ')
	{
		for (int i = 0; i < number; i++)
		{
			while (string[i] == ' ')
				count++;
			if (count >= 1)
			{
				array[size++] = ' ';
				count = 0;
			}
			else
				array[size++] = mainArray[s++];
		}
	}
	return array;
}

int main(void)
{
	FILE *input;
	char ch, string[1000];
	int size = 0, sizeArr;
	input = fopen("input.txt", "r");
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
		string[size++] = ch;
	fclose(input);
	char *first = delete_space(string, size, &sizeArr);
	for (int i = 0; i < sizeArr; i++)
		printf("%c", first[i]);
	printf("\n");
	char *second = return_space(string, size);
	for (int i = 0; i < size; i++)
		printf("%c", second[i]);
	return 0;
}