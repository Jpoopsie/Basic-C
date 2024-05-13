/*
В двоичную систему
Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.*/

#include <stdio.h>

void two(int number)
{
	if (number > 0)
	{
		two(number / 2);
		int tmp = number % 2;
		printf("%d", tmp);
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	if (number == 0)
		printf("0");
	if (number != 0)
		two(number);
	return 0;
}