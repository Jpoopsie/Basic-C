#include <stdio.h>
#include <locale.h>

int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int x1, x2, y1, y2;
	float k, b;
	printf("Введите 4 целых числа через пробел: ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	k = (float)(y2 - y1) / (float)(x2 - x1);
	b = y1 - k * x1;
	printf("%.2f\n", k);
	printf("%.2f", b);
	return 0;
}