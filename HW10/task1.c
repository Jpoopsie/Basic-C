/*Три раза
В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.
Формат входных данных
Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
Формат результата
Исходная строка 3 раза подряд, через запятую пробел и количество символов в ней.
Примеры
Входные данные в файле input.txt
aab
Результат работы в файле output.txt
aab, aab, aab 3*/

#include <stdio.h>

int main()
{
	FILE *input;
	FILE *output;
	char c, ch[100] = {0,};
	int i = 0;
	char count = 0;
	input = fopen("input.txt", "r");
	while((c = fgetc(input)) != EOF)
	{
		ch[i++] = c;
		count++;
	}
	fclose(input);
	output = fopen("output.txt", "w");
	for(int a = 0; a < 3; a++)
	{
		for(int b = 0; b < count; b++)
			fputc(ch[b], output);
		fputc(' ', output);
	}
	fprintf(output, "%d", count);
	fclose(output);
    return 0;
}