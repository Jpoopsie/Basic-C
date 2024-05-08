/*Напечатать сумму максимума и минимума.*/

#include <stdio.h>

int main(void)
{
	int a, b, c, d, e;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	int max = a;
	int min = a;
	if (b > max)
		max = b;
	if (b < min)
		min = b;
	if (c > max)
		max = c;
	if (c < min)
		min = c;
	if (d > max)
		max = d;
	if (d < min)
		min = d;
	if (e > max)
		max = e;
	if (e < min)
		min = e;
	printf("%d\n", max + min);
	return 0;
}