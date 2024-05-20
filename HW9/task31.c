/*
Больше среднего
Определить количество положительных элементов квадратной матрицы, превышающих по величине среднее арифметическое всех элементов главной диагонали.
Реализовать функцию среднее арифметическое главной диагонали.*/

#include <stdio.h>

void above_average(int (*arr)[5])
{
	int sum = 0, squad, count = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i; j <= i; j++)
			sum += arr[i][j];
	}
	squad = sum / 5;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (squad < arr[i][j])
				count++;
		}
	}
	printf("%d", count);
}

int main(void)
{
	int arr[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);
	}
	above_average(arr);
	return 0;
}