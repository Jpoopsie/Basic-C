/*
В обратном порядке
Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.*/

#include <stdio.h>

void recurs(int number)
{
	int tmp = 0;
	if (number == 0)
		printf("%d ", tmp);
	if (number > 0)
	{
		tmp = number % 10;
		number /= 10;
		printf("%d ", tmp);
		if (number != 0)
			recurs(number);
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	recurs(number);
	return 0;
}