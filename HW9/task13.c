/*
Чаще других
Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего.
Гарантируется, что такое число ровно 1.*/

#include <stdio.h>

void max_repeat(int *arr)
{
	int count = 0, tmp = 0, number;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j])
				count++;
			if (count > tmp)
			{
				tmp = count;
				number = arr[i];
			}
		}
		count = 0;
	}
	printf("%d", number);
}

int main(void)
{
	int arr[10], number, i = 0;
	while (scanf("%d", &number))
	{
		arr[i++] = number;
		if (i == 10)
			break;
	}
	max_repeat(arr);
	return 0;
}