/*
Заканчивается на a
В файле input.txt дано предложение.
Необходимо определить, сколько слов заканчиваются на букву 'а'.
Ответ записать в файл output.txt.*/

#include <stdio.h>

/*Счётчик буквы а*/
int count_letter(char *string, int number)
{
	int count = 0, flag;
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
		for (int i = 0; i < number; i++)
		{
			if (string[i] == ' ' || string[i] == '\0' || string[i] == '\n')
			{
				if (string[i - 1] == 'a')
					count++;
			}
		}
	}
	else
	{
		if (string[number - 1] == 'a')
			count++;
	}
	return count;
}

/*Запись в output file*/
void write_file(char *string, int number)
{
	FILE *output;
	int count = count_letter(string, number);
	output = fopen("output.txt", "w");
	fprintf(output, "%d", count);
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
	write_file(string, count);
	return 0;
}