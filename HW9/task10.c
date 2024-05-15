/*
Вторая с конца ноль
Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль.*/

#include <stdio.h>
#include <stdlib.h>

void array(int *arr)
{
	int arr2[10], k = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] / 10 % 10 == 0)
			arr2[k++] = arr[i];
	}
	for (int j = 0; j < k; j++)
		printf("%d ", arr2[j]);
}

int main(void)
{
	int number, i = 0, arr[10];
	while (scanf("%d", &number))
	{
		arr[i++] = number;
		if (i == 10)
			break;
	}
	array(arr);
	return 0;
}