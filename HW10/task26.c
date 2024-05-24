#include <stdio.h>

void print_star_triangle(int number)
{
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= number - i; j++)
		{
			printf(" ");
		}
		for (int j = 1; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
}

int main()
{
	int number;
	printf("Enter the number of rows: ");
	scanf("%d", &number);

	print_star_triangle(number);

	return 0;
}