/*На вход подается произвольное трехзначное число, напечать произведение цифр*/

#include <stdio.h>

int main(void)
{
	int in_num, ou_num, i = 1;
	scanf("%d", &in_num);
	while (in_num > 0)
	{
		ou_num = in_num % 10;
		i *= ou_num;
		in_num /= 10;
	}
	printf("%d", i);
	return 0;
}