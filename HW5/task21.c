/*Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.*/

#include <stdio.h>

char *up_number(int number)
{
	int tmp;
	while (number > 0)
	{
		tmp = number % 10;
		number /= 10;
		if (tmp < number % 10)
			return "NO";
		if(tmp == number % 10)
			return "NO";
	}
	return "YES";
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%s", up_number(number));
	return 0;
}