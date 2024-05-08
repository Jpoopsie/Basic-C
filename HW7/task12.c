/*
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.*/

#include <stdio.h>

int function(int number)
{
	int sum = 0;
	for (int i = 1; i <= number; i++)
		sum += i;
	return sum;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d", function(number));
	return 0;
}