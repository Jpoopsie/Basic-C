/*Ввести целое число и определить, верно ли, что в его записи есть  две одинаковые цифры, НЕ обязательно стоящие рядом.*/

#include <stdio.h>

char *two_number(int number)
{
	int dupl, tmp;
	while (number > 0)
	{
		dupl = number;
		while (dupl > 0)
		{
			dupl /= 10;
			tmp = number % 10;
			if (tmp == dupl % 10)
				return "YES";
		}
		number /= 10;
	}
	return "NO";
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%s", two_number(number));
	return 0;
}