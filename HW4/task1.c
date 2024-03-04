#include <stdio.h>
#include <locale.h>

int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b;
	printf("Введите 2 целых числа через пробел: ");
	scanf("%d %d", &a, &b);
	a > b ? printf("Ваши числа в порядке возрастания: %d %d", b, a) : printf("Ваши числа в порядке возрастания: %d %d", a, b);
	return 0;
}