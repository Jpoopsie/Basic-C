/*Инверсия каждой трети
Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.
Формат входных данных
12 целых чисел через пробел
Формат результата
12 целых чисел через пробел
Примеры
Входные данные
4 -5 3 10 -4 -6 8 -10 1 0 5 7
Результат работы
10 3 -5 4 -10 8 -6 -4 7 5 0 1
Входные данные
1 2 3 4 5 6 7 8 9 10 11 12
Результат работы
4 3 2 1 8 7 6 5 12 11 10 9*/

#include <stdio.h>

#define SIZE 12

void array(int arr[], int n)
{
	int first[4], second[4], third[4], a = 3, b = 3, c = 3;
	for(int i = 0;  i < 4; i++)
		first[a--] = arr[i];
	for(int i = 4; i < 8; i++)
		second[b--] = arr[i];
	for(int i = 8; i < n; i++)
		third[c--] = arr[i];
	for(int i = 0; i < 4; i++)
		printf("%d ", first[i]);
	for(int i = 0; i < 4; i++)
		printf("%d ", second[i]);
	for(int i = 0; i < 4; i++)
		printf("%d ", third[i]);
}

int main(void)
{
	int arr[SIZE];
	for(int i = 0; i < SIZE; i++)
		scanf("%d", &arr[i]);
	array(arr, SIZE);
	return 0;
}