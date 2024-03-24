/*Два максимума
Считать массив из 10 элементов и найти в нем два максимальных элемента и напечатать их сумму.
Формат входных данных
10 целых чисел через пробел.
Формат результата
Сумма двух максимальных элементов.
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0
Результат работы
18
Входные данные
-1 -2 -3 -4 -5 -6 -7 -8 -9 0
Результат работы
-1*/

#include <stdio.h>

#define SIZE 10

void array(int arr[], int n)
{
	int max = arr[0], max1 = arr[1];
	for(int i = 2; i < n; i++)
	{
		if(arr[i] > max)
		{
			max1 = max;
			max = arr[i];
		}
		else if(arr[i] > max1)
			max1 = arr[i];
	}
	printf("%d", max + max1);
}

int main()
{
	int arr[SIZE];
	for(int i = 0; i < SIZE; i++)
		scanf("%d", &arr[i]);
	array(arr, SIZE);
	return 0;
}