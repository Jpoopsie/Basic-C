#include <stdio.h>
#include <locale.h>

int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b;
	printf("Введите 2 целых числа через пробел: ");
	scanf("%d %d", &a, &b);
	if  (a > b) printf("Above");
	else if  (a < b) printf("Less");
	else printf("Equal");
	return 0;
}