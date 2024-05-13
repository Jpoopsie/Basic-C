/*
Скобки
Проверить строку состоящую из скобок "(" и ")" на корректность.*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[1000];
	int stack[1000];
	int top = -1;
	int count = 0;
	scanf("%s", str);
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			stack[++top] = '(';
			count++;
		}
		else if (str[i] == ')')
		{
			if (top == -1 || stack[top] != '(')
			{
				printf("NO\n");
				return 0;
			}
			stack[top--] = '\0';
			count--;
		}
	}
	if (top != -1 || count != 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}