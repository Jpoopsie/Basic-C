/*
Вычислить sin
Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)
float sinus(float x)*/

#include <stdio.h>
#include <stdlib.h>

float sinus(float x)
{
	x = x / 180 * 3.1415926;
	float q = x, s = 0, i = 1;
	while (1)
	{
		s = s + q;
		q = q * (-1) * (x * x) / ((2 * i + 1) * (2 * i));
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
	printf("%.3f", sinus(x));
	return 0;
}
