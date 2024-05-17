/*
След матрицы
Составить функцию которая находит след матрицы в двумерном массиве.
Показать пример ее работы на матрице из 5 на 5 элементов.
След матрицы - это сумма элементов на главной диагонали.*/

#include <stdio.h>

void matrix(int (*arr)[5])
{
	int sum = 0;
	for (int i = 0; i <= 4; i++)
	{
		for (int j = i; j <= i; j++)
		{
			sum += arr[i][j];
		}
	}
	printf("%d", sum);
}

int main(void)
{
	int arr[5][5];
	for (int i = 0; i <= 4; i++)
	{
		for (int j = 0; j <= 4; j++)
		{
			scanf("%d ", &arr[i][j]);
		}
	}
	matrix(arr);
	return 0;
}