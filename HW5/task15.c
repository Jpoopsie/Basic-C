/*Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.*/

#include <stdio.h>

int main(void)
{
	int number, count = 0;
	scanf("%d", &number);
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	if (count == 3)
		printf("YES");
	else
		printf("NO");
}