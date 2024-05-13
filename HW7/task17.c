/*
Простые множители
Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа.
void print_simple(int n)*/

#include <stdio.h>

void print_simple(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d ", i);
			n /= i;
			print_simple(n);
			break;
		}
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	print_simple(number);
	return 0;
}