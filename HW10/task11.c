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
void firstArray(char *ch, int number)
{
	int count = separator(ch, number);
	char arr1[count];
	int meter = 0, k = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j <= count; j++)
		{
			if (ch[i] == ch[j])
				meter++;
		}
		if (meter == 0)
			arr1[k++] = ch[i];
	}
	for (int i = 0; i < k; i++)
		printf("%c", arr1[i]);
}

/*Сравниваем 2 части массива, и ищём одинаковые буквы в обоих частях*/
// void comparison(char *ch, int number)
// {
// 	int count = separator(ch, number);
// }

int main(void)
{
	FILE *input;
	char c, ch[300];
	int i = 0;
	input = fopen("input.txt", "r");
	while ((c = fgetc(input)) != EOF && (c != '\n'))
		ch[i++] = c;
	fclose(input);
	firstArray(ch, i);
	return 0;
}