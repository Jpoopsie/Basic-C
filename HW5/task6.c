/*Все цифры четные
Ввести целое число и определить, верно ли, что все его цифры четные. 
Данные на входе:	Одно целое число 
Данные на выходе:	YES или NO 

Пример №1
Данные на входе:	2684 
Данные на выходе:	YES 

Пример №2
Данные на входе:	2994 
Данные на выходе:	NO */

#include <stdio.h>
#include <locale.h>

int main()
{
	int a, b, numbers, count;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("Введите одно целое число: ");
	scanf("%d", &a);
	while(a > 0)
	{
		numbers = a % 10;
		a /= 10;
		b = numbers % 2;
		if (b == 1)
			count ++;
	}
	if (count >= 1)
		printf("NO");
	else
		printf("YES");
	return 0;
}