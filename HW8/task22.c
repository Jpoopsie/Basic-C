/*Монотонная последовательность
Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
Выведите первые n членов этой последовательности. Только один цикл for.*/

#include <stdio.h>

void generate_sequence(int n)
{
	int count = 1;
	if (n > 0)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= count; j++)
				printf("%d ", i);
			count++;
		}
		printf("\n");
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	generate_sequence(number);
	return 0;
}