#include <stdio.h>
#include <locale.h>


int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c, d;
	printf("Введите 3-х значное число: ");
	scanf("%d", &a);
	b = a / 100;
	c = (a % 100) / 10;
	d = a % 10;
	if ((b > c) && (b > d)) printf ("Наибольшее число: %d\n", b);
	else if ((c > b) && (c > d)) printf ("Наибольшее число: %d\n", c);
	else printf("Наибольшее число: %d\n", d);
	return 0;
}