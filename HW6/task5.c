/*C11 ДЗ
НОД
Составить функцию, которая определяет наибольший общий делитель двух натуральных и привести пример ее использования.
int nod(int a, int b)
Данные на входе: 	Два целых положительных числа
Данные на выходе: 	Одно целое число - наибольший общий делитель.

Пример №1
Данные на входе: 	14 21
Данные на выходе: 	7 */

#include <stdio.h>

int nod(int a, int b)
{
	int k = 0;
	if (a == b)
		return a;
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
			k = a;
		}
		else
		{
			b = b - a;
			k = b;
		}
	}
	return k;
}

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d", nod(a, b));
	return 0;
}