/*Положительные и отрицательные
Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в одни помещать только положительные, во второй - только отрицательные.
Числа, равные нулю, игнорировать.
Вывести на экран все элементы обоих массивов.*/

#include <stdio.h>

void sort_array(int *arr)
{
	int arr2[10], arr3[10], a = 0, b = 0;
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > 0)
			arr2[a++] = arr[i];
		else if (arr[i] < 0)
			arr3[b++] = arr[i];
	}
	for (int i = 0; i < a; i++)
		printf("%d ", arr2[i]);
	for (int i = 0; i < b; i++)
		printf("%d ", arr3[i]);
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
	sort_array(arr);
	return 0;
}