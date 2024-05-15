/*
По убыванию и по возрастанию
Считать массив из 10 элементов и отсортировать первую половину по возрастанию, а вторую – по убыванию.*/

#include <stdio.h>

void array(int *arr)
{
	int tmp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 5; i < 10; i++)
	{
		for (int j = 5; j < 10; j++)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int i = 0, arr[10], number;
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