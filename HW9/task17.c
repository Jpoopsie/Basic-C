/*
Переставить цифры
Переставить цифры в числе так, что бы получилось максимальное число.*/

#include <stdio.h>

void max_array(int number, int size)
{
	int arr[size], i = 0, tmp;
	while (number > 0)
	{
		arr[i++] = number % 10;
		number /= 10;
	}
	for (int a = 0; a < size; a++)
	{
		for (int b = a + 1; b < size; b++)
		{
			if (arr[a] < arr[b])
			{
				tmp = arr[a];
				arr[a] = arr[b];
				arr[b] = tmp;
			}
		}
	}
	for (int a = 0; a < size; a++)
		printf("%d", arr[a]);
}

int main(void)
{
	int number, size = 0;
	scanf("%d", &number);
	int tmp = number;
	while (tmp > 0)
	{
		size++;
		tmp /= 10;
	}
	max_array(number, size);
	return 0;
}