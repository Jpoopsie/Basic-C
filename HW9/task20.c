/*Поменять местами
Составить только функцию которая в массиве находит максимальный из отрицательных элементов и меняет его местами с последним элементом массива.
Гарантируется, что в массиве только один такой элемент или же такой элемент отсутствует.
Если отрицательных элементов нет - массив не менять.
Прототип функции: void swap_negmax_last(int size, int a[])*/

#include <stdio.h>

void swap_negmax_last(int size, int a[])
{
	int max = 0, arr[10], k = 0;

	/*Проверяю есть ли отрицательные числа в массиве*/
	for (int i = 0; i < size; i++)
	{
		if (max < a[i])
			max = 0;
		else
		{
			max = a[i];
			break;
		}
	}

	/*Если они есть решаю задачу*/
	if (max != 0)
	{
		for (int i = 0; i < size; i++) // Отрицательные в отдельный массив
		{
			if (a[i] < 0)
				arr[k++] = a[i];
		}
		for (int i = 0; i < k; i++) // Ищу максимальный из отрицательных
		{
			for (int j = 0; j < k; j++)
			{
				if (max < arr[j])
					max = arr[j];
			}
			break;
		}
		for (int i = 0; i < size; i++) // Меняю местами
		{
			if (a[i] == max)
			{
				a[i] = a[size - 1];
				a[size - 1] = max;
			}
		}
		// for (int i = 0; i < size; i++) // Вывожу в консоль
		// 	printf("%d ", a[i]);
		// printf("\n");
	}

	/*Отрицательных чисел нет, вывожу обычный массив*/
	// else if (max == 0)
	// {
	// 	for (int i = 0; i < size; i++)
	// 		printf("%d ", a[i]);
	// 	printf("\n");
	// }
}

int main(void)
{
	int arr[10] = {-131, -460, 206, 62, 179, -180, 354, 289, 239, 275}, size = 10;
	swap_negmax_last(size, arr);
	return 0;
}