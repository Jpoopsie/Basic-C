/*
В заданном интервале
Составить функцию которая возвращает количество элементов на заданном отрезке [from, to] для массива.
Прототип функции int count_between(int from, int to, int size, int a[])
Например, на отрезке [4, 6] в массиве 1 2 3 4 5 6 7 8 9 10 функция вернет 3 значения*/

#include <stdio.h>

int count_between(int from, int to, int size, int a[])
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] >= from && a[i] <= to)
			count++;
	}
	return count;
}

int main(void)
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = 10, from = 4, to = 6;
	printf("%d ", count_between(from, to, size, arr));
	return 0;
}