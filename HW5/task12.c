/*Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.*/

#include <stdio.h>

void square_cube(int i)
{
	for(int j = 1; j <= i; j++)
	{
		printf("%d %d %d\n", j, j*j, j*j*j);
	}
}

int main(void)
{
	int i;
	scanf("%d", &i);
	square_cube(i);
	return 0;
}