/*Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.*/

#include <stdio.h>

void square_number(int a, int b)
{
	int sum = 0, mult;
	for (; a <= b; a++)
	{
		mult = a * a;
		sum += mult;
	}
	printf("%d", sum);
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	square_number(a, b);
	return 0;
}