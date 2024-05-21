/*
По одному разу
В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом.
Найдите только те символы слов, которые встречаются в обоих словах только один раз.
Напечатайте их через пробел в файл output.txt в лексикографическом порядке.*/

#include <stdio.h>

/*Разделить массив на 2 части, до пробела, что бы сравнивать 2 части массива*/
int separator(char *ch, int number)
{
	int count = 0;
	for (int i = 0; i < number; i++)
	{
		if (ch[i] == ' ')
			break;
		count++;
	}
	return count;
}

/*Создаём первый массив в который кладём первое слово до пробела и убираем повторяющиеся буквы*/
char *firstArray(char *ch, int number)
{
	int count = separator(ch, number);
	// printf("%d\n", count);
	static char arr[100];
	int meter, k = 0;
	for (int i = 0; i < count; i++)
	{
		meter = 0;
		for (int j = 0; j <= count; j++)
		{
			if (ch[i] == ch[j])
				meter++;
		}
		if (meter == 1)
			arr[k++] = ch[i];
	}
	return arr;
}

/*Создаём второй массив в который кладём первое слово до пробела и убираем повторяющиеся буквы*/
char *secondArray(char *ch, int number)
{
	int count = separator(ch, number);
	static char arr1[100];
	// printf("%d\n", count);
	int meter, k = 0;
	for (int i = count + 1; i < number; i++)
	{
		meter = 0;
		for (int j = count + 1; j <= number; j++)
		{
			if (ch[i] == ch[j])
				meter++;
		}
		if (meter == 1)
			arr1[k++] = ch[i];
	}
	return arr1;
}

/*Сравниваем 2 части массива, и ищём одинаковые буквы в обоих частях*/
void comparison(char *ch, int number)
{
	FILE *output;
	char array[100];
	int count = 0, tmp;
	char *first = firstArray(ch, number);
	char *second = secondArray(ch, number);
	int firstLen = 0;
	int secondLen = 0;

	while (first[firstLen] != '\0')
		firstLen++;
	while (second[secondLen] != '\0')
		secondLen++;
	for (int i = 0; i < firstLen; i++)
	{
		for (int j = 0; j < secondLen; j++)
		{
			if (first[i] == second[j])
				array[count++] = first[i];
		}
	}

	/* Cортировка массива по лексиграфическому порядку*/
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
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
	for (int i = 0; i < count; i++)
		fprintf(output, "%c ", array[i]);
	fclose(output);
	printf("%s %d\n", first, firstLen);
	printf("%s %d", second, secondLen);
}

int main(void)
{
	FILE *input;
	char c, ch[300];
	int i = 0;
	input = fopen("input.txt", "r");
	while ((c = fgetc(input)) != EOF && (c != '\n'))
		ch[i++] = c;
	fclose(input);
	comparison(ch, i);
	return 0;
}