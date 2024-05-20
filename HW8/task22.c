/*
Монотонная последовательность
Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
Выведите первые n членов этой последовательности. Только один цикл for.*/

#include <stdio.h>

void generate_sequence(int n)
{
	static int count = 1;
	if (n > 0)
	{
		for (int i = 1; i <= count; i++)
		{
			printf("%d ", count);
		}
		count++;
		generate_sequence(n - count);
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	generate_sequence(number);
	return 0;
}