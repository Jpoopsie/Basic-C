/*C5 ДЗ 
Сумма от 1 до N
Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования. 

Пример №1
Данные на входе: 	Одно целое положительное число N 
Данные на выходе: 	Целое число - сумма чисел от 1 до N 

Пример №2
Данные на входе: 	100 
Данные на выходе: 	5050 */

#include <stdio.h>
#include <locale.h>

int  sum_of_numbers(int n)
{
	int k;
	for(int i = 1; i <= n; i++)
	{
		k += i;
	}
	return k;
}

int main()
{
	int n;
	setlocale(LC_ALL, ".UTF-8");
	printf("Введите одно целое положительное число: ");
	scanf("%d", &n);
	printf("%d", sum_of_numbers(n));
	return 0;
}