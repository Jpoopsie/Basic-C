/*
Модуль числа
Составить функцию, модуль числа и привести пример ее использования.*/

#include <stdio.h>

int modul(int number)
{
	if(number < 0)
		return -number;
	return number;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%d", modul(number));
	return 0;
}