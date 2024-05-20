/*
Больше по модулю
Составить функцию которая определяет в массиве, состоящем из положительных и отрицательных чисел, сколько элементов превосходят по модулю максимальный элемент.
Прототип функции int count_bigger_abs(int n, int a[])
*/

#include <stdio.h>

int count_bigger_abs(int n, int a[])
{
	int arr[n], max, count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
			arr[i] = a[i] * (-1);
		else
			arr[i] = a[i];
	}
	max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			count++;
	}
	return count;
}

int main(void)
{
	int arr[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	printf("%d", count_bigger_abs(10, arr));
	return 0;
}