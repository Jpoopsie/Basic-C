/*
Найти число пи до n-й цифры после запятой
Введите число, и программа начнет генерировать число пи.
Поставьте определенный предел, до которого программа должна дойти.
*/
#include <stdio.h>

int main(void)
{
	FILE *input;
	long long a, size = 0;
	char array[1000000], ch;
	scanf("%lld", &a);
	if (a > 1000001)
	{
		printf("The number must be no more than 1000000");
		return 1;
	}
	input = fopen("Pi.txt", "r");
	while ((ch = fgetc(input)) != EOF)
	{
		array[size++] = ch;
		a--;
		if (a == -1)
			break;
	}
	for (int i = 0; i < size; i++)
		printf("%c", array[i]);
	return 0;
}