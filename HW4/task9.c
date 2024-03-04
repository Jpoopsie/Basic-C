#include <stdio.h>
#include <locale.h>

int main ()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c;
	printf("Введите 3 целых числа через пробел: ");
	scanf("%d%d%d", &a, &b, &c);
	if((a < b) && (b < c)) printf("YES");
	else printf("NO");
	return 0;
}