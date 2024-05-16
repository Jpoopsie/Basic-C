/*Поменять местами
Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
Прототип функции void change_max_min(int size, int a[])*/

#include <stdio.h>

void change_max_min(int size, int a[])
{
	int min = a[0], max = a[0], temp, temp1, temp2;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (min > a[i])
			{
				min = a[i];
				temp = i;
			}
			if (max < a[i])
			{
				max = a[i];
				temp1 = i;
			}
		}
	}
	temp2 = a[temp];
	a[temp] = max;
	a[temp1] = min;
	// for (int i = 0; i < size; i++)
	// 	printf("%d ", a[i]);
}

int main(void)
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int size = 10;
	change_max_min(size, arr);
	return 0;
}