/*
Цифры по порядку
Вывести в порядке следования цифры, входящие в десятичную запись натурального числа N.*/

#include <stdio.h>

void numbers_up(int number, int size)
{
	int tmp, arr[size], a = 0;
	while (number > 0)
	{
		tmp = number % 10;
		number /= 10;
		arr[a++] = tmp;
	}
	for (int i = a - 1; i >= 0; i--)
		printf("%d ", arr[i]);
}

int main(void)
{
	int number, count;
	scanf("%d", &number);
	int tmp = number;
	while (tmp > 0)
	{
		count++;
		tmp /= 10;
	}
	numbers_up(number, count);
	return 0;
}