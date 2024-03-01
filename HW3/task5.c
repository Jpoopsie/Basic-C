#include <stdio.h>
#include <locale.h>

int main() 
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a;
	int b = 1;
	printf("Введите трёхзначное число: ");
	scanf("%3d", &a);
	while (a > 0) 
	{
    b *= a % 10;
    a /= 10;
	}

printf("Произведение числа равно: %d\n", b);
return 0;
}