/*
Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.*/

#include <stdio.h>

void shift_array(int *arr, int a, int b)
{
	while (a < b)
	{
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
		a++;
		b--;
	}
}

int main(void)
{
	int number, arr[12], i = 0;
	while (scanf("%d", &number) == 1)
	{
		arr[i++] = number;
		if (i == 12)
			break;
	}
	shift_array(arr, 0, i - 1);
	shift_array(arr, 0, 3);
	shift_array(arr, 4, i - 1);
	for (int k = 0; k < i; k++)
		printf("%d ", arr[k]);
	return 0;
}