/*
Сумма минимальна
Дан целочисленный массив из 30 элементов. Элементы массива могут принимать произвольные целые значения помещающиеся в int.
Необходимо создать функцию, которая находит и выводит в порядке возрастания номера двух элементов массива, сумма которых минимальна.*/

#include <stdio.h>

void sum_min(int arr[])
{
	int tmp = 0, tmp1 = 1, min = arr[0], min1 = arr[0] + arr[1];
	for (int i = 0; i < 30; i++)
	{
		if (i != tmp1)
		{
			if (arr[i] < min)
			{
				min = arr[i];
				tmp = i;
			}
		}
	}
	for (int i = 1; i < 30; i++)
	{
		if (i != tmp)
		{
			if (arr[tmp] + arr[i] <= min1)
			{
				min1 = arr[tmp] + arr[i];
				tmp1 = i;
			}
		}
	}
	if (tmp < tmp1)
		printf("%d %d", tmp, tmp1);
	if (tmp > tmp1)
		printf("%d %d", tmp1, tmp);
}

int main(void)
{
	int arr[30];
	for (int i = 0; i < 30; i++)
		scanf("%d", &arr[i]);
	sum_min(arr);
	return 0;
}