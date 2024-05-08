/*Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.*/

#include <stdio.h>

void reverce(int number)
{
	if(number == 0)
		printf("%d", number);
	while (number > 0)
	{
		printf("%d", number % 10);
		number /= 10;
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	reverce(number);
	return 0;
}