/*
Сколько раз встречается символ a
Дана строка из английских символов, пробелов и знаков препинания. В конце строки символ точка. Необходимо реализовать рекурсивную функцию, которая считывает данную строку со стандартного потока ввода и возвращает целое число - количество символов 'a' в данной строке.
int acounter(void)
Используя данную функцию решить задачу.*/

#include <stdio.h>

int acounter(char current_char)
{
	if (current_char == '.')
		return 0;
	int count = 0;
	if (current_char == 'a')
		count += 1;
	int next_count = acounter(getchar());
	return count + next_count;
}

int main()
{
	int total_count = acounter(getchar());
	printf("%d", total_count);
	return 0;
}