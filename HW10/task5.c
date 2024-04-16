/*Заменить a на b
В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.
Формат входных данных
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Формат результата
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
aabbccddABCD
Результат работы в файле output.txt
bbaaccddBACD*/

#include <stdio.h>

#define LEN 1000

int main(void)
{
	char str[LEN] = {0}, ch;
	int i = 0;
	FILE *input, *output;
	input = fopen("input.txt", "r");
	while((ch = fgetc(input)) != EOF && (ch != '\n'))
		str[i++] = ch;
	fclose(input);
	output = fopen("output.txt", "w");
	for(i = 0; str[i] != '\0'; i++)
	if(str[i] == 'a')
		str[i] = 'b';
	else if(str[i] == 'A')
		str[i] = 'B';
	else if(str[i] == 'b')
		str[i] = 'a';
	else if(str[i] == 'B')
		str[i] = 'A';
	fprintf(output, "%s", str);
	fclose(output);
	return 0;
}