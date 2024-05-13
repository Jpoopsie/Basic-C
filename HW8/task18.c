/*
От A до B
Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.*/

#include <stdio.h>

void recurs(int A, int B)
{
	if (A < B + 1)
	{
		printf("%d ", A);
		if (A == B)
			return;
		recurs(A + 1, B);
	}
	else if (A + 1 > B)
	{
		recurs(A, B + 1);
		if (A == B)
			return;
		printf("%d ", B);
	}
	else
		return;
}

int main(void)
{
	int A, B;
	scanf("%d %d", &A, &B);
	recurs(A, B);
	return 0;
}