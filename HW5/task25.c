/*Дана последовательность ненулевых целых чисел, в конце последовательности число 0. Посчитать количество чисел.*/

#include <stdio.h>

int main()
{
	int num, count = 0;
	scanf("%d", &num);
	while (num != 0)
	{
		count++;
		scanf("%d", &num);
	}
	printf("%d", count);
	return 0;
}