/*Цифры по возрастанию
Написать функцию и программу демонстрирующую работу данной функции. Вывести в порядке возрастания цифры, входящие в десятичную запись натурального числа N, не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в числе.
Формат входных данных
Натуральное число не более 1000 цифр
Формат результата
Цифры входящие в число через пробел в порядке возрастания. От самой младшей цифры до самой старшей и количество.
Примеры
Входные данные
54321
Результат работы
1 1
2 1
3 1
4 1
5 1
Входные данные
22443344
Результат работы
2 2
3 2
4 4*/

#include <stdio.h>


void array(int size, int b)
{
	int arr[size], j = 0;
	while(b > 0)
	{
		arr[j] = b % 10;
		b = b / 10;
		j++;
	}
	for(int i = 0; i < size - 1;  i++)
	{
		for(int j = 0; j < size - 1- i; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for(int i = 0; i < size; i++)
		{
			int count = 1;
			for(int s = i + 1; s < size; s++)
			{
				if(arr[s] == arr[i-1])
					continue;
				if(arr[i] == arr[s])
					count++;
				else
					break;
			}
			printf("%d %d\n", arr[i], count);
		}
	}

int main(void)
{
	int number, i = 0, k = 0;
	scanf("%d", &number);
	k = number;
	while(number > 0)
	{	
		number =  number / 10;
		i++;
	}
	array(i, k);
}