/*Ввести целое число и найти сумму его цифр.*/

#include <stdio.h>

int sum_number(int number)
{
	int sum, count;
	while (number > 0)
	{
		count = number % 10;
		sum += count;
		number /= 10;
	}
	return sum;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d", sum_number(number));
	return 0;
}
