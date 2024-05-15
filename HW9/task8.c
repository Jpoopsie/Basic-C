/*
Отсортировать по последней цифре
Считать массив из 10 элементов и отсортировать его по последней цифре.*/

#include <stdio.h>

void array(int *arr)
{
	int tmp;
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < i; k++)
		{
			if (arr[i] % 10 < arr[k] % 10)
			{
				tmp = arr[i];
				arr[i] = arr[k];
				arr[k] = tmp;
			}
		}
	}
}

int main(void)
{
	int arr[10], i = 0, number;
	while (scanf("%d", &number))
	{
		arr[i++] = number;
		if (i == 10)
			break;
	}
	array(arr);
	for (int k = 0; k < i; k++)
		printf("%d ", arr[k]);
	return 0;
}