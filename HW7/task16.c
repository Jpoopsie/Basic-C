/*
Факториал
Составить функцию вычисления N!. Использовать ее при вычислении факториала
int factorial(int n)*/

#include <stdio.h>

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
	scanf("%d", &n);
	printf("%llu", factorial(n));
	return 0;
}