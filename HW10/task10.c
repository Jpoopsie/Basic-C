/*
Строка и цифры
Считать число N из файла input.txt.
Сформировать строку из N символов. N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0,
на нечетных позициях - заглавные буквы в порядке следования в английском алфавите.
Результат записать в файл output.txt*/

#include <stdio.h>

int find_number(char *ch, int count)
{
	int tmp, number = 0;
	for (int i = 0; i < count; i++)
	{
		tmp = ch[i] - '0';
		number = number * 10 + tmp;
	}
	return number;
}

void array(char *ch, int count)
{
	FILE *output;
	int number = find_number(ch, count), tmp = number, i = 0, z = 0, s = 2;
	char arr[number];
	printf("%d", number);
	while (tmp > 0)
	{
		if (tmp % 2 == 0)
		{
			arr[i++] = 'A' + z;
			z++;
		}
		else
		{
			arr[i++] = s + '0';
			s += 2;
			if (s == 10)
				s = 2;
		}
		tmp--;
	}
	output = fopen("output.txt", "w");
	for (int b = 0; b < number; b++)
		fprintf(output, "%c", arr[b]);
	fclose(output);
}

int main(void)
{
	FILE *input;
	int i = 0, count = 0;
	char c, ch[2];
	input = fopen("input.txt", "r");
	while ((c = fgetc(input)) != EOF && (c != '\n'))
	{
		ch[i++] = c;
		count++;
	}
	fclose(input);
	array(ch, count);
	return 0;
}