/*
Найти наибольшее
Дана последовательность ненулевых целых чисел, завершающаяся числом 0. Ноль в последовательность не входит.
Определите наибольшее значение числа в этой последовательности. Для решения задачи необходимо написать рекурсивную функцию вида:
int max_find(int max)*/

#include <stdio.h>

int max_find(int max)
{
	static int number = -20000000;
	if (number < max)
		number = max;
	return number;
}

int main(void)
{
	int number, c;
	while (scanf("%d", &number))
	{
		if (number == 0)
			break;
		c = max_find(number);
	}
	printf("%d", c);
	return 0;
}