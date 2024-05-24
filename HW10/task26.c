/*
Soundex
Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию.
На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код.
Если коды двух слов совпадают, то слова, как правило, звучат похоже.
Вам требуется реализовать этот алгоритм. Он работает так:
Первая буква слова сохраняется.
В остальной части слова:
буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:
1: b, f, p, v
2: c, g, j, k, q, s, x, z
3: d, t
4: l
5: m, n
6: r
Любая последовательность одинаковых цифр сокращается до одной такой цифры.
Итоговая строка обрезается до первых четырёх символов.
Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.
Примеры:
аmmonium → ammnm → a5555 → a5 → a500
implementation → implmnttn → i51455335 → i514535 → i514*/

#include <stdio.h>

/*Удаленин гласных букв*/
char *delete_vowel(char *string, int size, int *sizeArr)
{
	int arrSize = 0;
	char array[100];
	char deleteArr[8] = {"aehiouwy"};
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (string[i] != deleteArr[j])
			{
				for (int k = 0; k < size; k++)
					string[k] = string[k + 1];
				size--;
				j--;
			}
		}
	}
	for (int i = 0; i < size; i++)
		array[arrSize++] = string[i];
}

int main(void)
{
	int size = 0;
	char ch, string[20];
	while (scanf("%c", &ch))
	{
		if (ch == '\n')
			break;
		string[size++] = ch;
	}
	char *del = delete_vowel(string, size, 0);
	return 0;
}