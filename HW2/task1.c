#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	char hex[] = "0123456789ABCDEF";
	char save_dec[100];
	int i, n, k, z;
	k = 0;
	z = 0;
	printf("Введите число в десятичной системе счисления: ");
	scanf("%d", &i);
	while (i != 0)
	{
		n = i % 16;
		i = i/16;
		save_dec[k] = hex[n];
		k++;
		z++;
	}
	printf("Ваше число в шестнадцатеричной системе счисления: ");
	for( int a = z-1;	a >= 0; a--)
	{
		printf("%c", save_dec[a]);
	}
	return 0;
}