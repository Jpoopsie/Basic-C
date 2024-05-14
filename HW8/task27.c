/*
Написать рекурсивную функцию и используя ее решить задачу. Напечатать цифры введенного натурального числа в порядке следования(слева направо)
через пробел.
void print_digits(int n)*/

#include <stdio.h>

void print_digits(int n)
{
	if (n > 0)
	{
		print_digits(n / 10);
		printf("%d ", n % 10);
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	print_digits(number);
	return 0;
}