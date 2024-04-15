/*Последний номер символа
В файле input.txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. Результат записать в файл output.txt
Формат входных данных
Строка не более 1000 символов
Формат результата
Целые числа через пробел - номера символа, который совпадает с последним символом строки.
Примеры
Входные данные в файле input.txt
aabbcdb
Результат работы в файле output.txt
2 3*/

#include <stdio.h>

#define SIZE 1000

int main(void)
{
	FILE *input, *output;
	char ch, str[1000], last;
	int i = 0, count = 0;
	input = fopen("input.txt", "r");
	while((ch = fgetc(input)) != EOF)
		str[i++] = ch;
	fclose(input);
	last = str[count - 1];
	output = fopen("output.txt", "w");
	for(int a = 0; a < count - 1; a++)
	{
		if(last == str[a])
			fprintf(output, "%d ", a);
	}
	fclose(output);	
	return 0;
}