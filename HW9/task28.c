/*Сумма в интервале
Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
Прототип функции int sum_between_ab(int from, int to, int size, int a[])*/

#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[])
{
	int sum = 0;
	if (from < to)
	{
		for (int i = 0; i < size; i++)
		{
			if (a[i] >= from && a[i] <= to)
				sum += a[i];
		}
	}
	if (from > to)
	{
		for (int i = 0; i < size; i++)
		{
			if (a[i] >= to && a[i] <= from)
				sum += a[i];
		}
	}
	return sum;
}

int main(void)
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int from = 4, to = 6;
	printf("%d", sum_between_ab(from, to, 10, arr));
	return 0;
}