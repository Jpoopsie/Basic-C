/*
Вычислить cos
Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
cos(x) = 1 - x2/2! + x4/4! - x6/6! + ... (x в радианах)
float cosinus(float x)*/

#include <stdio.h>

float cosinus(float x)
{
	x = x / 180 * 3.1415926;
	float q = 1, s = 0, i = 1;
	while (1)
	{
		s = s + q;
		q = q * (-1) * (x * x) / ((2 * i) * (2 * i - 1));
		i++;
		if (q == 0)
			break;
	}
	return s;
}

int main()
{
	float x;
	scanf("%f", &x);
	printf("%.3f", cosinus(x));
	return 0;
}