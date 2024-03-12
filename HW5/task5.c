/*B8
Ровно одна цифра 9
Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9». 
Данные на входе:	Одно целое число 
Данные на выходе:	Одно слово: YES или NO  

Пример №1
Данные на входе:	193 
Данные на выходе:	YES 

Пример №2
Данные на входе:	1994 
Данные на выходе:	NO*/

#include <stdio.h>
#include <locale.h>

int main() 
{
	int a, numbers, count;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	printf("Введите одно целое число: ");
	scanf("%d", &a);
	while (a > 0) 
	{
		numbers = a % 10;
		a /= 10;
		if (numbers == 9)
			count++;
	}
	if (count == 1)
		printf ("YES");
	else
		printf("NO");
	return 0;
}