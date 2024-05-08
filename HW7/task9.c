/*
Возвести в степень
Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.*/

#include <stdio.h>

int power(int n, int p)
{
	int k = 1;
	if(p == 0)
		return 1;
	for (int i = 0; i < p; i++)
		k *= n;
	return k;
}

int main(void)
{
	int n, p;
	scanf("%d %d", &n, &p);
	printf("%d", power(n, p));
	return 0;
}