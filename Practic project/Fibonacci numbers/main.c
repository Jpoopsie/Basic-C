#include <stdio.h>

void fibonacci(int number)
{
	long long int tmp = 0, a = 1, b = 1;
	printf("%lld ", a);
	for (int i = 1; i < number; i++)
	{
		printf("%lld ", a);
		tmp = a;
		a = a + b;
		b = tmp;
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	fibonacci(number);
	return 0;
}