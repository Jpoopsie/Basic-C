/*
Составить палиндром
Разработать функцию дана строка из маленьких английских букв.
Составить из символов палиндром максимальной длинны.
При составлении палиндрома буквы в палиндроме должны быть расположены в лексикографическом порядке.
Записать ответ в файл output.txt.*/

#include <stdio.h>

/*Сортируем массив по возрастанию*/
char *spliting_array(char *string, int size)
{
	static char array[1000];
	char temp;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (string[i] > string[j])
			{
				temp = string[i];
				string[i] = string[j];
				string[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
		array[i] = string[i];
	return array;
}

/*Делаем симетричный массив*/
char *symmetry_array(char *string, int size, int *sizeArray)
{
	static char array[1000];
	int a = 0, b = size - 1;
	char *mainArray = spliting_array(string, size);
	for (int i = 0; i < size; i++)
	{
		if (mainArray[i] == mainArray[i + 1])
		{
			array[a++] = mainArray[i];
			array[b--] = mainArray[i + 1];
			i++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (array[i] == '\0')
		{
			for (int j = i; j < size; j++)
				array[j] = array[j + 1];
			i--;
			size--;
		}
	}
	*sizeArray = size;
	return array;
}

/*Ищем одну букву*/
char *search_letter(char *string, int size)
{
	static char array[1000];
	int count = 1, a = 0;
	char *symmetryArr = spliting_array(string, size);
	for (int i = 0; i < size; i++)
	{
		count = 1;
		for (int j = i + 1; j < size; j++)
		{
			if (string[i] == string[j])
			{
				count++;
				i++;
			}
		}
		if (count % 2 == 1)
			array[a++] = symmetryArr[i];
	}
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (array[i] < array[j])
			{
				char temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	return array;
}

/*Вставляем букву в массив*/
char *insert_letter(char *string, int size, int *sizeArray)
{
	static char array[1000];
	int sizeArr = 0, sizeMainArr;
	char *symmetry = symmetry_array(string, size, &sizeMainArr);
	char *oneLetter = search_letter(string, size);
	for (int i = 0; i < sizeMainArr / 2; i++)
		array[sizeArr++] = symmetry[i];
	array[sizeArr++] = oneLetter[0];
	for (int i = sizeMainArr / 2; i < sizeMainArr; i++)
		array[sizeArr++] = symmetry[i];
	*sizeArray = sizeArr;
	return array;
}

/*Запись в output file*/
void write_file(char *string, int size)
{
	FILE *output;
	int sizeArr;
	char *mainArray = insert_letter(string, size, &sizeArr);
	output = fopen("output.txt", "w");
	for (int i = 0; i < sizeArr; i++)
		fprintf(output, "%c", mainArray[i]);
	fclose(output);
}

int main(void)
{
	FILE *input;
	int size = 0;
	char ch, string[1000];
	input = fopen("input.txt", "r");
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
		string[size++] = ch;
	fclose(input);
	write_file(string, size);
	return 0;
}