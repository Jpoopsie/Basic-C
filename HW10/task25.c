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
	while (sum != count)
	{
		k = n * 1 + 1;
		n++;
		sum += k;
	}
	return sum;
}

char *distributor(char *string, int size)
{
	int count = count_stone(string, size);
	if (count < 3 || count % 2 == 0)
		return "NO";
	else
	{
		char *stone = write_stone(count);
	}
}

int main(void)
{
	char ch, string[1000];
	int size = 0;
	while (scanf("%c", &ch))
	{
		if (ch == '\n')
			break;
		string[size++] = ch;
	}
	char *first = distributor(string, size);
	printf("%s\n", first);
	return 0;
}