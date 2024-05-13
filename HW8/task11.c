/*
От 1 до N
Составить рекурсивную функцию, печать всех чисел от 1 до N*/

#include <stdio.h>

void recurs(int number)
{
	static int i = 1;
	if (number > 0)
	{
		printf("%d ", i++);
		number--;
		recurs(number);
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	recurs(number);
	return 0;
}