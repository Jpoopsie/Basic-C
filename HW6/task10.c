/*Числа Фибоначчи
Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
Числа Фибоначчи – это элементы числовой последовательности 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …,
в которой каждое последующее число равно сумме двух предыдущих.*/

#include <stdio.h>

void fibonacci(int number)
{
	int tmp = 0, a = 1, b = 1;
	printf("%d ", a);
	for (int i = 1; i < number; i++)
	{
		printf("%d ", a);
		tmp = a;
		a = a + b;
		b = tmp;
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	fibonacci(number);
	return 0;
}