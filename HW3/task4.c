#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	float a, b, c, d;
	printf("Введите 3 числа через пробел: ");
	scanf("%f %f %f", &a, &b, &c);
	d = (a + b + c) / 3;
	printf("Среднее арифметическое равно: %.2f", d);
	return 0;
}