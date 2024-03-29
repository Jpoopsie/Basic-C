/*От A до B
Составить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае. 

Данные на входе: 	Два целых числа через пробел. 
Данные на выходе: 	Последовательность целых чисел. 

Пример №1
Данные на входе: 	5 2 
Данные на выходе: 	5 4 3 2 

Пример №2
Данные на входе: 	2 7 
Данные на выходе: 	2 3 4 5 6 7 */

#include <stdio.h>
#include <locale.h>

void function (int a, int b)
{
	if(a < b)
	{
		printf("%d ", a++);
		function(a, b);
	}
	else if(a > b)
	{
		printf("%d ",  a--);
		function(a, b);
	}
	else
		printf("%d", a);
}

int main()
{
	int a, b;
	setlocale(LC_ALL, ".UTF-8");
	printf("Введите два целых числа через пробел: ");
	scanf("%d %d", &a, &b);
	function(a, b);
	return 0;
}