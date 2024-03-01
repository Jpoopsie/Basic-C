#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c, d;
	printf("Введите 3 числа через пробел: ");
	scanf("%d %d %d", &a, &b, &c);
	d = a - b - c;
	printf("Разность чисел равна: %d", d);
	return 0;
}