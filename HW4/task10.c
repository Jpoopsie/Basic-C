#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "ru_RU.UTF-8");
	int a;
	printf("Введите номер месяца: ");
	scanf( "%d", &a);
	switch (a)
	{
		case 1: printf("Winter"); break;
		case 2: printf("Winter"); break;
		case 3: printf("Spring"); break;
		case 4: printf("Spring"); break;
		case 5: printf("Spring"); break;
		case 6: printf("Summer"); break;
		case 7: printf("Summer"); break;
		case 8: printf("Summer"); break;
		case 9: printf("Autumn"); break;
		case 10: printf("Autumn"); break;
		case 11: printf("Autumn"); break;
		case 12: printf("Winter"); break;
		default: return 1; break;
	}
	return 0;
}