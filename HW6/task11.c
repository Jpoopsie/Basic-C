/*Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.*/

#include <stdio.h>

void ten(int number)
{
	int tmp, sum = 0;
	while (number > 0)
	{
		tmp = number % 10;
		sum += tmp;
		number /= 10;
	}
	if (sum == 10)
		printf("YES");
	else
		printf("NO");
}

int main(void)
{
	int number;
	scanf("%d", &number);
	ten(number);
	return 0;
}