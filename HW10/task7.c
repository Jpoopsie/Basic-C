/*Количество букв
В файле input.txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. Учитывать только английские буквы. Результат записать в файл output.txt.
Формат входных данных
Строка состоящая из английских букв, цифр, пробелов и знаков препинания.
Формат результата
Два целых числа. Количество строчных букв и количество заглавных букв.
Примеры
Входные данные в файле input.txt
aabbAB
Результат работы в файле output.txt
4 2
Входные данные в файле input.txt
HELLO WORLD
Результат работы в файле output.txt
0 10*/

#include <stdio.h>

#define MAX_SIZE 10000

int main(void)
{
	int small = 0, big = 0, i = 0, count = 0;
	char str[MAX_SIZE] = {0}, ch;
	FILE *input, *output;
	input = fopen("input.txt", "r");
	while ((ch = fgetc(input)) != EOF && (ch != '\0'))
	{
		str[i++] = ch;
		count++;
	}
	fclose(input);
	for (int a = 0; a < count; a++)
	{
		if (str[a] >= 'a' && str[a] <= 'z')
			small++;
		else if (str[a] >= 'A' && str[a] <= 'Z')
			big++;
	}
	output = fopen("output.txt", "w");
	fprintf(output, "%d %d", small, big);
	fclose(output);
	return 0;
}