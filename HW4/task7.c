#include <locale.h>
#include <stdio.h>

int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c, d, e, i;
	printf("Введите 5 целых числа через пробел: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	if ((a >= b) && (a >= c) && (a >= d) && (a >= e)) i = a;
	else if ((b > a) && (b > c) && (b > d) && (b > e)) i = b;
	else if ((c > a) && (c > b) && (c > d) && (c > e)) i = c;
	else if ((d > a) && (d > b) && (d > c) && (d > e)) i = d;
	else i = e;
	printf("Максимальное число: %d\n", i);
	return 0;
}