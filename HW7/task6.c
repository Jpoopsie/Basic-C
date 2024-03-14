/*D16 Практик 3
Точная степень двойки
Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
int is2pow(int n)
Данные на входе: 	Одно натуральное число. 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 	8 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 	7 
Данные на выходе: 	NO */

#include <stdio.h>
#include <locale.h>

int is2pow(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else if (n % 2 != 0)
		return 0;
	else
		return is2pow(n / 2);
}

int main()
{
	int n;
	setlocale(LC_ALL, ".UTF-8");
	printf("Введите одно натуральное число:  ");
	scanf("%d", &n);
	is2pow(n) ? printf ("YES") : printf("NO");
	return 0;
}