/*Дано трехзначное число, напечатать макисмальную цифру*/

#include <stdio.h>

int main(void)
{
	int innum, max = 0, number;
	scanf("%d", &innum);
	while (innum > 0)
	{
		number = innum % 10;
		if (number > max)
			max = number;
		innum = innum / 10;
	}
	printf("%d", max);
	return 0;
}