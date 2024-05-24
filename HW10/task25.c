/*
Равносторонние треугольники
Cia очень любит равносторонние треугольники.
Он все время выкладывает их из камней.
Ling дал Cia камни и попросил его составить такой треугольник если это возможно.
Помогите Cia сложить треугольник используя все камни или напечатайте слов NO, если это невозможно.
Пример треугольников, которые составляет Cia:
 *
* *

  *
 * *
* * *

   *
  * *
 * * *
* * * *
Во входном файле input.txt записано некоторое количество символов * (камней).
Необходимо построить равносторонний треугольник используя все символы * и символ пробел, записать ответ в выходной файл output.txt.
Между соседними символами * строго один пробел.
Если треугольник невозможно составить, используя все камни, то необходимо записать единственное слово NO в файл output.txt.*/

#include <stdio.h>

/*Считаю количество камней*/
int count_stone(char *string, int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (string[i] == '*')
			count++;
	}
	return count;
}

/*Возвращаю на какой строке конец*/
int write_stone(int count)
{
	int n = 0, k = 1, sum = 0;
	if(count < 3)
		return 1;
	while (sum < count)
	{
		k = n * 1 + 1;
		n++;
		sum += k;
	}
	if (sum == count)
		return n;
	else
		return 1;
}

/*Распределяет ответ*/
int distributor(char *string, int size)
{
	int count = count_stone(string, size);
	int n = write_stone(count);
	return n;
}

void answer(char *string, int size)
{
	FILE *output;
	output = fopen("output.txt", "w");
	int number = distributor(string, size);
	if (number == 1)
		fprintf(output, "NO");
	else
	{
		for (int i = 1; i <= number; i++)
		{
			for (int j = 1; j <= number - i; j++)
				fprintf(output, " ");
			for (int j = 1; j <= i; j++)
				fprintf(output, "* ");
			fprintf(output, "\n");
		}
	}
	fclose(output);
}

int main(void)
{
	FILE *input;
	char ch, string[100000];
	int size = 0;
	input = fopen("input.txt", "r");
	// while (scanf("%c", &ch))
	// {
	// 	if (ch == '\n')
	// 		break;
	// 	string[size++] = ch;
	// }
	while ((ch = fgetc(input)) != EOF)
		string[size++] = ch;
	fclose(input);
	answer(string, size);
	return 0;
}