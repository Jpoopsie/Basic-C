/*
Кратность прежде всего
В диапазоне натуральных чисел от 2 до N определить, сколько из них кратны любому из чисел в диапазоне от 2 до 9.*/

#include <stdio.h>

void multiplicity(int number)
{
	printf("2 %d\n", number / 2);
	printf("3 %d\n", number / 3);
	printf("4 %d\n", number / 4);
	printf("5 %d\n", number / 5);
	printf("6 %d\n", number / 6);
	printf("7 %d\n", number / 7);
	printf("8 %d\n", number / 8);
	printf("9 %d\n", number / 9);
}

int main(void)
{
	int number;
	scanf("%d", &number);
	multiplicity(number);
	return 0;
}