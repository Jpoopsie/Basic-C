/*
Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.*/

#include <stdio.h>

int count_one(int number)
{
	static int count = 0, tmp;
	if (number > 0)
	{
		tmp = number % 2;
		if (tmp == 1)
			count++;
		number = number / 2;
		return count_one(number);
	}
	else
		return count;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d", count_one(number));
	return 0;
}