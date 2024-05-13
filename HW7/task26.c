/*
Перевести число N в систему счисления P
Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.*/

#include <stdio.h>

int convertBase(int N, int P)
{
	int result = 1, tmp, result1 = 0;
	while (N > 0)
	{
		tmp = N % P;
		N /= P;
		result = result * 10 + tmp;
	}
	while (result > 0)
	{
		tmp = result % 10;
		result /= 10;
		result1 = result1 * 10 + tmp;
	}
	return result1 / 10;
}

int main()
{
	int N, P;
	scanf("%d %d", &N, &P);
	printf("%d", convertBase(N, P));
	return 0;
}
