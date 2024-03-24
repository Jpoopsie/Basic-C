/*Найти минимум
Ввести c клавиатуры массив из 5 элементов, найти минимальный из них.
Формат входных данных
5 целых чисел через пробел
Формат результата
Одно единственное целое число
Примеры
Входные данные
4 15 3 10 14
Результат работы
3
Входные данные
1 2 3 4 -5
Результат работы
-5*/

#include <stdio.h>

#define SIZE 5

void array(int arr[], int n)
{
	int k = arr[0];
	for(int i = 0; i < n; i++)
	{
		k >= arr[i] ? k = arr[i] : k; 
	}
	printf("%d", k);
}

int main()
{
	int arr[SIZE];
	for(int i = 0; i < SIZE; i++)
		scanf("%d", &arr[i]);
	array(arr, SIZE);
	return 0;
}