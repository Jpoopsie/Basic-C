/*D11 ДЗ 3
Количество 1
Дано натуральное число N. Посчитать количество «1» в двоичной записи числа. 
Данные на входе: 	Натуральное число 
Данные на выходе: 	Целое число - количество единиц в двоичной записи числа. 

Пример №1
Данные на входе: 	5 
Данные на выходе: 	2 

Пример №2
Данные на входе: 	255 
Данные на выходе: 	8 */

#include <stdio.h>
#include <locale.h>

int counter(unsigned n) 
{
	static int count;
	int k;
	if(n > 0)
	{
		k = n % 2;
		if(k == 1)
			count++;
		counter(n / 2);
	}
	return count;
}

int main()
{
	unsigned n;
	setlocale(LC_ALL, ".UTF-8");
	printf("Введите натурально число: ");
	scanf("%u", &n);
	printf("%d", counter(n));
	return 0;
}