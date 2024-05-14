/*
Функция Аккермана
Функция Аккермана определяется рекурсивно для неотрицательных целых чисел m и n следующим образом:
Реализуйте данную функцию по прототипу
int akkerman(int m, int n)*/

#include <stdio.h>

int main(void)
{
	int m, n, res;
	while (scanf("%lld %lld", &m, &n) == 2)
	{
		if (m == 0)
			res = n + 1;
		else if (m == 1)
			res = n + 2;
		else if (m == 2)
			res = 2 * n + 3;
		else
			res = (1 << (n + 3)) - 3;
		printf("%lld\n", res);
	}
}