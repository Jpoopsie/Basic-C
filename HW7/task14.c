/*
Перевести число N в систему счисления P
Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.*/

#include <stdio.h>

int convertBase(int N, int P)
{
	int result = 0, power = 1;
	while (N > 0)
	{
		int remainder = N % P;
		result += remainder * power;
		power *= P;
		N /= P;
	}
	return result;
}

int main()
{
	int N, P;
	scanf("%d %d", &N, &P);
	if (N < 0 || P < 2 || P > 9)
	{
		printf("Invalid input");
		return 1;
	}
	printf("%d", convertBase(N, P));
	return 0;
}