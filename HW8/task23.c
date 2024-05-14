/*
Все нечетные
Дана последовательность целых чисел через пробел, завершающаяся числом 0.
Выведите все нечетные числа из этой последовательности, сохраняя их порядок.*/

#include <stdio.h>

int recurs(int number)
{
	return number;
}

int main(void)
{
	int number;
	while (scanf("%d", &number))
	{
		if (number == 0)
			break;
		if (number % 2 == 1 || number % 2 == -1)
			printf("%d ", recurs(number));
	}
	return 0;
}