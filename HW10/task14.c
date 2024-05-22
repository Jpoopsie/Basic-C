/*
Самое длинное слово
В файле input.txt дана строка слов, разделенных пробелами.
Найти самое длинное слово и вывести его в файл output.txt.
Случай, когда самых длинных слов может быть несколько, не обрабатывать.*/

#include <stdio.h>

/*Создаём счётчик букв в слове и возвращаем самое большое слово*/
char *count_words(char *string, int number, int *arrSize)
{
	int count, start = 0, tmp = 0, size, flag;
	static char array[1000];
	for (int i = 0; i < number; i++)
	{
		if (string[i] == ' ' || string[i] == '\0' || string[i] == '\n')
		{
			flag = 1;
			break;
		}
		else
			flag = 0;
	}
	if (flag == 1)
	{
		while (start < number)
		{
			count = 0;
			for (int i = start; i < number + 1; i++)
			{
				if (string[i] == ' ' || string[i] == '\0' || string[i] == '\n')
				{
					start++;
					if (count > tmp)
					{
						tmp = count;
						size = 0;
						for (int k = i - count; k < i; k++)
							array[size++] = string[k];
					}
					printf("%d\n", count);
					break;
				}
				count++;
				start++;
			}
		}
	}

	/*Если пришло одно слово без пробелов и перехода строки*/
	else
	{
		size = 0;
		for (int i = 0; i < number; i++)
			array[size++] = string[i];
	}
	*arrSize = size;
	return array;
}

/*Записываем слово в output file*/
void write_file(char *string, int number)
{
	FILE *output;
	int sizeArr = 0;
	char *array = count_words(string, number, &sizeArr);
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
	for (int i = 0; i < count; i++)
		printf("%c", string[i]);
	printf("\n");
	write_file(string, count);
	return 0;
}