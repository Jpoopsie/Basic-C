/*
Клетки
Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х цветов, например, черного и белого (см. рисунок).
Каждая клетка имеет координату, состоящую из буквы и цифры. Горизонтальное расположение клетки определяется буквой от A до H, а вертикальное – цифрой от 1 до 8.
Заметим, что клетка с координатой А1 имеет черный цвет. Требуется по заданной координате определить цвет клетки.*/

#include <stdio.h>

void cells(char ch, int number)
{
	int letter;
	if (ch == 'A' || ch == 'C' || ch == 'E' || ch == 'G')
		letter = 1;
	else if (ch == 'B' || ch == 'D' || ch == 'F' || ch == 'H')
		letter = 2;
	if (letter % 2 == 1 && number % 2 == 1)
		printf("BLACK\n");
	else if (letter % 2 == 1 && number % 2 == 0)
		printf("WHITE\n");
	else if (letter % 2 == 0 && number % 2 == 1)
		printf("WHITE\n");
	else
		printf("BLACK");
}

int main(void)
{
	char ch;
	int number;
	scanf("%c%d", &ch, &number);
	cells(ch, number);
	return 0;
}