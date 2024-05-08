/*Проверить число на простоту.*/

#include <stdio.h>

char *is_prime(int number)
{
	if (number < 2)
		return "NO";
	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
			return "NO";
	}
	return "YES";
}

int main(void)
{
	int number;
	scanf("%d", &number);
	printf("%s", is_prime(number));
	return 0;
}