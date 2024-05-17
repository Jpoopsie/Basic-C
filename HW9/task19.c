/*Упаковать 0 и 1
Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей по следующему принципу:
например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1] преобразуется в [4,7,2,4]
(т.к. начинается с нуля, то сразу записывается количество элементов первой серии); а массив [1,1,1,0,0,0,0,0,0,0] преобразуется в [0,3,7]
(т.к. первая серия - это единицы, то первый элемент преобразованного массива 0).
Необходимо реализовать только одну функцию, всю программу загружать не надо. Прототип функции: int compression(int a[], int b[], int N)*/

#include <stdio.h>

int compression(int a[], int b[], int N)
{
	int count = 0, index = 0;
	if (a[0] == 1)
	{
		for (int i = 0; i < N; i++)
		{
			if (i == 0 || a[i] != a[i - 1])
			{
				b[index++] = count;
				count = 0;
			}
			count++;
		}
		b[index++] = count;
		return index;
	}
	else
	{
		count = 1;
		for (int i = 0; i < N - 1; i++)
		{
			if (a[i] == a[i + 1])
				count++;
			else
			{
				b[index++] = count;
				count = 1;
			}
		}
		b[index++] = count;
		return index;
	}
}

int main(void)
{
	int array[10000], count = 0, number;
	while (scanf("%d", &number))
	{
		array[count++] = number;
		if (count == 100)
			break;
	}
	int a[count], b[count];
	for (int i = 0; i < count; i++)
		a[i] = array[i];
	printf("%d", compression(a, b, count));
	return 0;
}