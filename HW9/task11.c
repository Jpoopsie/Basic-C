/*
Более одного раза
Считать массив из 10 элементов и выделить в другой массив все числа, которые встречаются более одного раза.
В результирующем массиве эти числа не должны повторяться.*/

#include <stdio.h>

void array(int *arr)
{
	int arr2[10], k = 0, count = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j])
			{
				for (int s = 0; s < 10; s++)
				{
					if (arr[i] != arr2[s])
						count++;
				}
				if (count == 10)
					arr2[k++] = arr[i];
				count = 0;
			}
		}
	}
	for (int i = 0; i < k; i++)
		printf("%d ", arr2[i]);
}

int main(void)
{
	int number, i = 0, arr[10];
	while (scanf("%d", &number))
	{
		arr[i++] = number;
		if (i == 10)
			break;
	}
	array(arr);
	return 0;
}