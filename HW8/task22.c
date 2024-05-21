/*
Монотонная последовательность
Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
Выведите первые n членов этой последовательности. Только один цикл for.*/

#include <stdio.h>

void generate_sequence(int n)
{
	int current_number = 1;
	int count = 1;
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", current_number);
		if (count == current_number)
		{
			current_number++;
			count = 1;
		}
		else
			count++;
	}
}

int main(void)
{
	int number;
	scanf("%d", &number);
	generate_sequence(number);
	return 0;
}