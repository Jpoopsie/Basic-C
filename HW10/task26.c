/*
Soundex
Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию.
На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
Если коды двух слов совпадают, то слова, как правило, звучат похоже.
Вам требуется реализовать этот алгоритм. Он работает так:
Первая буква слова сохраняется.
В остальной части слова:
буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
1: b, f, p, v
2: c, g, j, k, q, s, x, z
3: d, t
4: l
5: m, n
6: r
Любая последовательность одинаковых цифр сокращается до одной такой цифры.
Итоговая строка обрезается до первых четырёх символов.
Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.
Примеры:
аmmonium → ammnm → a5555 → a5 → a500
implementation → implmnttn → i51455335 → i514535 → i514*/

#include <stdio.h>

/*Удаленин гласных букв*/
char *delete_vowel(char *string, int size, int *sizeArr)
{
	int arrSize = 0;
	static char array[100];
	char deleteArr[8] = {"aehiouwy"};
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (string[i] == deleteArr[j])
			{
				for (int k = i; k < size; k++)
					string[k] = string[k + 1];
				size--;
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < size; i++)
		array[arrSize++] = string[i];
	*sizeArr = size;
	return array;
}

/*Замена букв цифрами*/
char *replace_letter(char *string, int size, int *arrSize)
{
	static char array[20];
	int sizeArr;
	char *first = delete_vowel(string, size, &sizeArr);
	for (int i = 1; i < sizeArr; i++)
	{
		switch (first[i])
		{
		case 'b':
		case 'f':
		case 'p':
		case 'v':
			first[i] = '1';
			break;
		case 'c':
		case 'g':
		case 'j':
		case 'k':
		case 'q':
		case 's':
		case 'x':
		case 'z':
			first[i] = '2';
			break;
		case 'd':
		case 't':
			first[i] = '3';
			break;
		case 'l':
			first[i] = '4';
			break;
		case 'm':
		case 'n':
			first[i] = '5';
			break;
		case 'r':
			first[i] = '6';
			break;
		}
	}
	array[0] = first[0];
	for (int i = 1; i < sizeArr; i++)
		array[i] = first[i];
	*arrSize = sizeArr;
	return array;
}

/*Удаление повторяющихся цифр*/
char *delete_repeating(char *string, int size, int *arrSize)
{
	int sizeArr;
	char *first = replace_letter(string, size, &sizeArr);
	int fullSize = 0;
	static char array[20] = {'\0'};
	for (int i = 1; i < sizeArr; i++)
	{
		if (first[i] == first[i + 1])
		{
			for (int j = i; j < sizeArr; j++)
				first[j] = first[j + 1];
			sizeArr--;
			i--;
		}
	}
	array[fullSize++] = first[0];
	for (int i = 1; i < sizeArr; i++)
		array[fullSize++] = first[i];
	*arrSize = fullSize;
	return array;
}

/*Возвращаем правильный массив*/
char *return_array(char *string, int size, int *arrSize)
{
	int sizeArr;
	char *first = delete_repeating(string, size, &sizeArr);
	static char array[20];
	int fullSize = 0;
	if (sizeArr < 4)
	{
		for (int i = 0; i < 4; i++)
		{
			if (first[i] == '\0')
				first[i] = '0';
		}
		for (int i = 0; i < 4; i++)
			array[fullSize++] = first[i];
	}
	else if (sizeArr > 4)
	{
		for (int i = 0; i < 4; i++)
			array[fullSize++] = first[i];
	}
	else
	{
		for (int i = 0; i < 4; i++)
			array[fullSize++] = first[i];
	}
	*arrSize = fullSize;
	return array;
}

/*Запись в output file*/
void write_file(char *string, int size)
{
	FILE *output;
	int sizeArr;
	char *first = return_array(string, size, &sizeArr);
	output = fopen("output.txt", "w");
	for (int i = 0; i < sizeArr; i++)
		fprintf(output, "%c", first[i]);
	fclose(output);
}

int main(void)
{
	FILE *input;
	// int sizeArr;
	int size = 0;
	char ch, string[20];
	input = fopen("input.txt", "r");
	// ch = fscanf(input, "%c", &ch);
	// string[size++] = ch;
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
		string[size++] = ch;
	if (input == NULL)
		perror("Error open file");
	fclose(input);
	// while (scanf("%c", &ch))
	// {
	// 	if (ch == '\n')
	// break;
	// 	string[size++] = ch;
	// }
	// char *del = return_array(string, size, &sizeArr);
	// for (int i = 0; i < sizeArr; i++)
	// 	printf("%c", del[i]);
	write_file(string, size);
	return 0;
}