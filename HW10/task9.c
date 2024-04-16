/*Удалить повторяющиеся символы
В файле input.txt строка из меленьких и больших английских букв, знаков препинания и пробелов. Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл output.txt.
Формат входных данных
Строка из меленьких и больших английских букв, знаков препинания и пробелов. Размер строки не более 1000 сивмолов.
Формат результата
Строка из меленьких и больших английских букв.
Примеры
Входные данные в файле input.txt
abc cde def
Результат работы в файле output.txt
abcdef*/

#include <stdio.h>

#define MAX_SIZE 1000

void duplicates(char arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(arr[i] == arr[j])
			{
				for(int k = j; k < size - 1; k++)
					arr[k] = arr[k + 1];
				size--;
				j--;
			}
		}
	}
}

int main(void)
{
	char arr[MAX_SIZE] = {0}, ch;
	int count = 0, i = 0;
	FILE *input, *output;
	input = fopen("input.txt", "r");
	while((ch = fgetc(input)) != EOF && (ch != '\0'))
	{
		arr[i++] = ch;
		count++;
	}
	fclose(input);
	duplicates(arr, count);
	output = fopen("output.txt", "w");
	for(int i = 0; i < count; i++)
		fprintf(output, "%c", arr[i]);
	fclose(output);
	return 0;
}