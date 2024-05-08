/*Ввести целое число и определить, верно ли, что в его записи есть  две одинаковые цифры, стоящие рядом.*/

#include <stdio.h>

char *two_numbers(int number)
{
	int count;
	while (number > 0)
	{
		count = number % 10;
		number /= 10;
		if (number % 10 == count)
		{
			return "YES";
			break;
		}
	}
	return "NO";
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%s", two_numbers(number));
	return 0;
}