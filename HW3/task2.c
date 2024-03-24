#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c, d;
	scanf("%d %d %d", &a, &b, &c);
	d = a + b + c;
	printf("%d+%d+%d=%d\n", a, b, c, d);
	d = a * b * c;
	printf("%d*%d*%d=%d\n", a, b, c, d);
	return 0;
}