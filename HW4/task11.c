#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
		printf("NO");
	else
		printf("YES");
	return 0;
}