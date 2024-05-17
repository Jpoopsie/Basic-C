/*
Цифры по возрастанию
Написать функцию и программу демонстрирующую работу данной функции.
Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр.
Цифра пробел сколько раз данная цифра встречается в числе.*/

#include <stdio.h>

void up_number(int arr[], int size)
{
	int temp, count = 1;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size + 1; j++)
		{
			if (arr[i] == arr[j])
				count++;
			else
			{
				printf("%d %d", arr[i], count);
				printf("\n");
				count = 1;
				i = j - 1;
				break;
			}
		}
	}
}

int main(void)
{
	int arr[1000], count = 0;
	char string[1000];
	scanf("%s", string);
	for (int i = 0; i < 1000; i++)
	{
		if (string[i] == '\0')
			break;
		arr[i] = string[i] - '0';
		count++;
	}
	up_number(arr, count);
	return 0;
}