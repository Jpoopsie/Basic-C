/*
В прямом порядке
Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.
void print_num(int num)*/

#include <stdio.h>

void print_num(int num)
{
	if (num == 0)
		return;
	else
	{
		print_num(num / 10);
		int digit = num % 10;
		printf("%d ", digit);
	}
}
int main(void)
{
	int number;
	scanf("%d", &number);
	if (number == 0)
		printf("0");
	if (number != 0)
		print_num(number);
	return 0;
}