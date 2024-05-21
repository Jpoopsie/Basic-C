/*
Числа в массив
В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы.
Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив.
Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
Вывести массив по возрастанию в файл output.txt.*/

#include <stdio.h>

/*Находим цифры в файле и переводим их в промежуточный массив типа int*/
int *find_number(char *string, int size)
{
	static int array[1000];
	int sizeAr = 0;
	for (int i = 0; i < size + 1; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
			array[sizeAr++] = string[i] - '0';
		else
			array[sizeAr++] = -1;
	}
	return array;
}

/*Создаём основной массив где убираем промежуточный результат и соединяем отдельные цифры в числа*/
int *create_array(char *string, int size, int *arraySize)
{
	static int array[1000];
	int *intermediateArr = find_number(string, size);
	int sizeArr = 0, stats;
	for (int i = 0; i < size; i++)
	{
		if (intermediateArr[i] != -1)
		{
			if (intermediateArr[i + 1] == -1)
				array[sizeArr++] = intermediateArr[i];
			else
			{
				stats = intermediateArr[i];			   // = 9
				for (int j = i + 1; j < size + 1; j++) // = 9
				{
					if (intermediateArr[j] != -1)
						stats = stats * 10 + intermediateArr[j];
					else
					{
						array[sizeArr++] = stats;
						i = j - 1;
						break;
					}
				}
			}
		}
	}
	*arraySize = sizeArr;
	return array;
}

/*Сортировка массива по возрастанию и запись в output*/
void sort(char *string, int size)
{
	FILE *output;
	int arrSize = 0, tmp;
	int *array = create_array(string, size, &arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		for (int j = i + 1; j < arrSize; j++)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
	output = fopen("output.txt", "w");
	for (int i = 0; i < arrSize; i++)
		fprintf(output, "%d ", array[i]);
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
	sort(string, count);
	return 0;
}