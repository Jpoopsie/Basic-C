/*
Сумма цифр числа
Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
int sum_digits(int n)*/

#include <stdio.h>

int sum_digits(int n)
{
	static int sum = 0;
	if (n < 0)
		return 0;
	else if (n == 0)
		return sum;
	else
	{
		sum += n % 10;
		sum_digits(n / 10);
	}
	return sum;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d\n", sum_digits(number));
	return 0;
}