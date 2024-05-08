/*Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.*/

#include <stdio.h>

void square_number(int a, int b)
{
	for (; a <= b; a++)
		printf("%d ", a * a);
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	square_number(a, b);
	return 0;
}