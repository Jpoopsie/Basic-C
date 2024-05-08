/*Организовать ввод натурального числа с клавиатуры.
Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.*/

#include <stdio.h>

void min_max(int number)
{
	int max = number % 10, min = number % 10;
	while (number > 0)
	{
		if (number % 10 > max)
			max = number % 10;
		if (number % 10 < min)
			min = number % 10;
		number /= 10;
	}
	printf("%d %d", min, max);
}

int main(void)
{
	int number;
	scanf("%d", &number);
	min_max(number);
	return 0;
}