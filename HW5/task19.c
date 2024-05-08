/*Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9».*/

#include <stdio.h>

char *number_one(int number)
{
	int count = 0;
	while (number > 0)
	{
		if (number % 10 == 9)
			count++;
	number /= 10;
	}
	if (count == 1)
		return "YES";
	else
		return "NO";
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%s", number_one(number));
	return 0;
}