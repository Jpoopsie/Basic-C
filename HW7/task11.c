/*
Функция по формуле
Описать функцию вычисления f(x) по формуле:
f(x)= x*x при -2 ≤ x < 2;
x*x+4x+5 при x ≥ 2;
4 при x < -2.
Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.*/

#include <stdio.h>

int function(int k)
{
	if (k < -2)
		return 4;
	if (k >= 2)
		return (k * k) + (4 * k) + 5;
	if (-2 <= k && k < 2)
		return k * k;
	return k;
}

int main(void)
{
	int k, max;
	scanf("%d", &k);
	max = function(k);
	while (scanf("%d", &k) == 1)
	{
		if (k == 0)
			break;
		function(k) > max ? max = function(k) : max;
	}
	printf("%d", max);
	return 0;
}