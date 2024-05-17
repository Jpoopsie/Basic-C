/*
Упаковать строку
Дана строка состоящая из маленьких латинских букв 'a'..'z'.
В конце строки точка. Необходимо заменить повторяющиеся буквы на <буква><количество повторений>*/

#include <stdio.h>

void string(char *str, int size)
{
	int count = 1, k = 0, revers = 1, tmp;
	char text[2000];
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size + 1; j++)
		{
			if (str[i] == str[j])
				count++;
			else
			{
				text[k++] = str[i];
				if (count < 10)
					text[k++] = count + '0';
				if (count >= 10)
				{
					while (count > 0)
					{
						tmp = count % 10;
						count /= 10;
						revers = revers * 10 + tmp;
					}
					while (revers > 1)
					{
						text[k++] = revers % 10 + '0';
						revers /= 10;
					}
				}
				count = 1;
				i = j - 1;
				break;
			}
		}
	}
	for (int i = 0; i < k; i++)
		printf("%c", text[i]);
}

int main(void)
{
	char str[1000], ch;
	int s = 0;
	while (scanf("%c", &ch))
	{
		if (ch == '.')
			break;
		str[s++] = ch;
	}
	string(str, s);
	return 0;
}