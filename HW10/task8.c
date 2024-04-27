/*Числа в массив
В файле input.txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести массив по возрастанию в файл output.txt.
Формат входных данных
Строка из английских букв, цифр и знаков препинания
Формат результата
Последовательность целых чисел отсортированная по возрастанию
Примеры
Входные данные в файле input.txt
data 48 call 9 read13 blank0a
Результат работы в файле output.txt
0 9 13 48*/

#include <stdio.h>

#define SIZE 1000

int main(void)
{
	FILE *input, *output;
	int numbers[SIZE] = {0};
	int i = 0;
	input = fopen("input.txt", "r");
	output = fopen("output.txt", "w");
	while (fscanf(input, "%d", &numbers[i]) != EOF)
		i++;
	printf("%d", fscanf(input, "%d", &numbers[1]));
	for (int j = 0; j < 100; j++)
		printf("%d %%", numbers[j]);
	fclose(input);
	fclose(output);
	return 0;
}