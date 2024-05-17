/*Сумма в интервале
Составить функцию которая возвращает сумму элементов в заданном отрезке [from, to] для массива.
Прототип функции int sum_between_ab(int from, int to, int size, int a[])*/

#include <stdio.h>

int sum_between_ab(int from, int to, int size, int a[])
{
	int sum = 0;
	for (int i = from; i <= to; i++)
		sum += a[i];
	return sum;
}

int main(void)
{
	int from, to, arr[12] = {4, 6, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	scanf("%d %d", &from, &to);
	printf("%d", sum_between_ab(from, to, 12, arr));
	return 0;
}