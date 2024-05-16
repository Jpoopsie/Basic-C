/*
Только один раз
Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран.*/

#include <stdio.h>

void array(int *arr)
{
	int arr2[10], count = 1, k = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j])
				count++;
		}
		if (count == 1)
			arr2[k++] = arr[i];
		count = 1;
	}
	for (int i = 0; i < k; i++)
		printf("%d ", arr2[i]);
}

int main(void)
{
	int arr[10], number, i = 0;
	while (scanf("%d", &number))
	{
		arr[i++] = number;
		if (i == 10)
			break;
	}
	// for (i = 0; i < 10; i++)
	// 	printf("%d ", arr[i]);
	array(arr);
	return 0;
}