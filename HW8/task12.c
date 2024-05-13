/*
Сумма чисел от 1 до N
Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N*/

#include <stdio.h>

int recurs(int number)
{
	static int i = 1, tmp;
	if (number > 0)
	{
		tmp += i;
		i++;
		number--;
		return recurs(number);
	}
	else
		return tmp;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d", recurs(number));
	return 0;
}