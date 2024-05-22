/*
Разобрать на слова
В файле input.txt дано предложение требуется разобрать его на отдельные слова.
Напечатать каждое слово на отдельной строке в файл output.txt.*/

#include <stdio.h>

int main(void)
{
	FILE *input, *output;
	char ch;
	int i = 0;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	while ((ch = fgetc(input)) != EOF && (ch != '\n'))
	{
		if (ch == ' ' && i == 0)
		{
			fputc('\n', output);
			i++;
		}
		else if (ch != ' ')
		{
			i = 0;
			fprintf(output, "%c", ch);
		}
	}
	return 0;
}