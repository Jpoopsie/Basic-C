#include <stdio.h>
#include <locale.h>


int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c, d, e, i, z;
	printf("Введите 5 целых числа через пробел: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	if ((a >= b) && (a >= c) && (a >= d) && (a >= e)) i = a;
	else if ((b > a) && (b > c) && (b > d) && (b > e)) i = b;
	else if ((c > a) && (c > b) && (c > d) && (c > e)) i = c;
	else if ((d > a) && (d > b) && (d > c) && (d > e)) i = d;
	else if ((e > a) && (e > b) && (e > c) && (e > d)) i = e;

	if ((a <= b) && (a <= c) && (a <= d) && (a <= e)) z = a;
	else if ((b < a) && (b < c) && (b < d) && (b < e)) z = b;
	else if ((c < a) && (c < b) && (c < d) && (c < e)) z = c;
	else if ((d < a) && (d < b) && (d < c) && (d < e)) z = d;
	else if ((e < a) && (e < b) && (e < c) && (e < d)) z = e;
	printf("Сумма минимального и максимального числа: %d\n", i + z);
	return 0;
}