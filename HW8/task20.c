/*
Проверка на простоту
Дано натуральное число n ≥ 1. Проверьте, является ли оно простым. Программа должна вывести слово YES, если число простое или NO в противном случае. Необходимо составить рекурсивную функцию и использовать ее.
int is_prime(int n, int delitel)*/

#include <stdio.h>

int is_prime(int n, int delitel)
{
	if (n <= 1)
		return 0;
	else if (delitel * delitel > n)
		return 1;
	else if (n % delitel == 0)
		return 0;
	else
		return is_prime(n, delitel + 1);
}

int main(void)
{
	int number;
	scanf("%d", &number);
	if (is_prime(number, 2))
		printf("YES");
	else
		printf("NO");
	return 0;
}