/*
От 1 до N
Составить рекурсивную функцию, печать всех чисел от N до 1.*/

#include <stdio.h>

void recurs(int number)
{
	if (number > 0)
	{
		printf("%d ", number);
		recurs(number - 1);
	}
	else
		return;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	recurs(number);
	return 0;
}