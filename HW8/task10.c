/*Циклический сдвиг массива вправо на 4
Считать массив из 12 элементов и выполнить циклический сдвиг ВПРАВО на 4 элемента.
Input format
12 целых чисел через пробел
Output format
12 целых чисел через пробел
*/

#include <stdio.h>

#define SIZE 12


void array(int arr[], int n)
{
	for(int i = 0; i < n - 4; i++) 
	{
		arr[i] = arr[i + 4];
		printf("%d ", arr[i]);
	}
}

int main(void)
{
	int arr[SIZE];
	for(int i = 0; i < SIZE; i++)
		scanf("%d", &arr[i]);
	array(arr, SIZE);
	return 0;
}