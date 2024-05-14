/*
Точная степень двойки
Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
int is2pow(int n)*/

#include <stdio.h>

#include <stdio.h>

int is2pow(int n)
{
	if(n == 0 || n == 1)
		return 1;
	else if (n % 2 != 0)
		return 0;
	else
		return is2pow(n / 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	is2pow(n) ? printf ("YES") : printf("NO");
	return 0;
}