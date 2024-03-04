#include <stdio.h>
#include <locale.h>


int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c;
	printf("Введите 3 целых числа через пробел: ");
	scanf("%d %d %d", &a, &b, &c);
	if ((a > c) && (a > b)) printf ("Наибольшее число: %d\n", a);
	else if ((b > a) && (b > c)) printf ("Наибольшее число: %d\n", b);
	else printf("Наибольшее число: %d\n", c);
	return 0;
}