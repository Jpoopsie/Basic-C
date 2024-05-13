/*Сумма цифр равна произведению

Составить логическую функцию, которая определяет, верно ли, что в данном числе сумма цифр равна произведению.

int is_happy_number(int n)

Данные на входе: 	Целое не отрицательное число 
Данные на выходе: 	YES или NO 

Пример №1
Данные на входе: 	123 
Данные на выходе: 	YES 

Пример №2
Данные на входе: 	528 
Данные на выходе: 	NO*/

#include <stdio.h>
#include <locale.h>

void is_happy_number(int n)
{
	int k, sum = 0, mul = 1;
	while (n > 0)
	{
		k = n % 10;
		n /= 10;
		sum += k;
		mul *= k;
	}
	sum == mul ? printf("YES") : printf("NO");
}

int main()
{
	int n;
	scanf("%d", &n);
	is_happy_number(n);
	return 0;
}