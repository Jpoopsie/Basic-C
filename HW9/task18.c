/*
Пропущенное число
В последовательности записаны целые числа от M до N ( M меньше N, M больше или равно 1)в произвольном порядке, но одно из чисел пропущено (остальные встречаются ровно по одному разу). N не превосходит 1000.
Последовательность заканчивается числом 0. Определить пропущенное число.*/

#include <stdio.h>

void miss_number(int *arr, int size)
{
	int array[size], min = arr[0];

	/* Делаем массив под свой размер*/
	for (int i = 0; i < size; i++)
		array[i] = arr[i];

	/*Находим минимальное число в массиве*/
	for (int i = 0; i < size; i++)
	{
		if (array[i] < min)
			min = array[i];
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (min + 1 == array[j])
				min += 1;
		}
	}
	printf("%d", min + 1);
}

int main(void)
{
	int arr[1000], count = 0, number;
	while (scanf("%d", &number))
	{
		if (number == 0)
			break;
		arr[count++] = number;
	}
	miss_number(arr, count);
	return 0;
}