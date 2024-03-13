/*C9 Практ 2
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)

Данные на входе: 	Целое положительное число не больше 20 
Данные на выходе: 	Целое положительное число 

Пример №1
Данные на входе: 	5 
Данные на выходе: 	120 */

#include <stdio.h>
#include <locale.h>

unsigned long long int factorial(int n)
{
	unsigned long long int k = 1;
	for (int i = 1; i <= n; i++)
	{
		k *= i;
	}
	return k;
}

int main()
{
	int n;
	setlocale(LC_ALL, ".UTF-8");
	printf("Введите целое положительное число не больше 20: ");
	scanf("%d", &n);
	printf("%llu", factorial(n));
	return 0;
}