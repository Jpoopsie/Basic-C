/*
Возвести в степень
Написать рекурсивную функцию возведения целого числа n в степень p.
int recurs_power(int n, int p)*/

#include <stdio.h>

int recurs_power(int n, int p)
{
	if (p == 0)
		return 1;
	else
		return n * recurs_power(n, p - 1);
}

int main(void)
{
	int n, p;
	scanf("%d %d", &n, &p);
	printf("%d\n", recurs_power(n, p));
	return 0;
}