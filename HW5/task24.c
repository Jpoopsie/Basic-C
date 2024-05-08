/*Посчитать количество четных и нечетных цифр числа.*/

#include <stdio.h>

void count_number(int number)
{
	int even = 0, odd = 0;

	while (number > 0)
	{
		if (number % 10 % 2 == 0)
			even++;
		else
			odd++;
		number /= 10;
	}
	printf("%d %d", even, odd);
}

	int main(void)
	{
		int number;
		scanf("%d", &number);
		count_number(number);
		return 0;
	}