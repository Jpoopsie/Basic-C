/*
Четные и нечетные
Дан целочисленный массив из 10 элементов. Необходимо определить количество четных и нечетных чисел. Если количество чётных чисел больше, чем количество нечётных, заменить каждое нечетное число на произведение нечетных цифр в его десятичной записи.
Если количество нечётных чисел больше или равно количеству чётных, заменить каждое чётное число на произведение чётных цифр в его десятичной записи.*/

#include <stdio.h>

void odd_even(int arr[])
{
	int counto = 0, counte = 0, a[10], mult, tmp;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 2 == 0)
			counte++;
		else
			counto++;
	}
	if (counte > counto)
	{
		for (int i = 0; i < 10; i++)
		{
			mult = 1;
			if (arr[i] % 2 != 0)
			{
				while (arr[i] > 0)
				{
					tmp = arr[i] % 10;
					if (tmp % 2 == 1)
						mult *= tmp;
					arr[i] /= 10;
				}
				a[i] = mult;
			}
			else
				a[i] = arr[i];
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			mult = 1;
			if (arr[i] % 2 == 0)
			{
				while (arr[i] > 0)
				{
					tmp = arr[i] % 10;
					if (tmp % 2 == 0)
						mult *= tmp;
					arr[i] /= 10;
				}
				a[i] = mult;
			}
			else
				a[i] = arr[i];
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", a[i]);
}

int main(void)
{
	int arr[10];
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	odd_even(arr);
	return 0;
}