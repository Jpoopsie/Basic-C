/*
Цифры по возрастанию
Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу.
int grow_up(int n)*/

#include <stdio.h>

int grow_up(int n)
{
	int tmp;
	while(n > 0)
	{
		tmp = n % 10;
		n /= 10;
		if (n % 10 >= tmp)
			return 0;
	}
	return 1;
}

int main(void)
{
	int number;
	scanf("%d", &number);
	if (grow_up(number) == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}