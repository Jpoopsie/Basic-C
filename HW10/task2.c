/*Cao заменить на Ling
В файле input.txt дано предложение. Необходимо заменить все имена «Cao» на «Ling» и записать результат в файл output.txt.
Формат входных данных
Строка из английский букв, знаков препинания и пробелов. Не более 1000 символов.
Формат результата
Строка из английский букв, знаков препинания и пробелов.
Примеры
Входные данные в файле input.txt
Cao, Cao, Cao and Cao!!!
Результат работы в файле output.txt
Ling, Ling, Ling and Ling!!!*/

#include <stdio.h>

int main()
{
	FILE *input, *output;
	char c, ch[1000];
	int len = 0, count = 1;
	input = fopen("input.txt", "r");
	while((c = fgetc(input)) != EOF)
	{
		ch[len++] = c;
		count++;
	}
	fclose(input);
	for(int i = 0; i < count; i++)
	{
		if(ch[i] == 'C' && ch[i + 1] == 'a' && ch[i + 2] == 'o')
		{
			ch[i] = 'L';
			ch[i + 1] = 'i';
			ch[i + 2] = 'n';
			ch[i + 3] = 'g';
			ch[i + 4] = ' ';
		}
	}
	output = fopen("output.txt", "w");
	for(int i = 0; i < count; i++)
		fputc(ch[i], output);
	fclose(output);
	return 0;
}