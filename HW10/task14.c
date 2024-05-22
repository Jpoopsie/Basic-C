/*
Самое длинное слово
В файле input.txt дана строка слов, разделенных пробелами.
Найти самое длинное слово и вывести его в файл output.txt.
Случай, когда самых длинных слов может быть несколько, не обрабатывать.*/

#include <stdio.h>

/*Создаём счётчик букв в слове и возвращаем самое большое слово*/
char *count_words(char *string, int number, int *arrSize)
{
	int count, start = 0, tmp = 0, size;
	char array[1000];
	while (start < number)
	{
		count = 0;
		for (int i = start; i < number + 1; i++)
		{
			if (string[i] == ' ' || string[i] == '\0')
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
	*arrSize = size;
	return array;
}

/*Записываем слово в output file*/
void write_file(char *string, int number)
{
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
	count_words(string, count);
	return 0;
}