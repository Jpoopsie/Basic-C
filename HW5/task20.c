/*Ввести целое число и определить, верно ли, что все его цифры четные.*/

#include <stdio.h>

char *even_number(int number)
{
	while(number > 0)
	{
		if(number % 10 % 2 != 0)
			return "NO";
		number /= 10;
	}
	return "YES";
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%s", even_number(number));
	return 0;
}