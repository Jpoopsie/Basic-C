/*
Сумма цифр четна
Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу*/

#include <stdio.h>

void sum_odd(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum = sum + number % 10;
		number /= 10;
	}
	if (sum % 2 == 0)
		printf("YES\n");
	else
		printf("NO\n");
}

int main(void)
{
	int number;
	scanf("%d", &number);
	sum_odd(number);
	return 0;
}