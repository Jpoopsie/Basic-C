/*
Проверка на простоту
Составить функцию логическую функцию, которая определяет, верно ли, что число простое. Используя функцию решить задачу.
int is_prime(int n)*/

#include <stdio.h>

int is_prime(int n)
{
}

int main(void)
{
	int number;
	scanf("%d", &number);
	if (is_prime(number) == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}