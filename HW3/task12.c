/*На вход подается произвольное трехзначное число, напечать сумму цифр*/

#include <stdio.h>

int main(void)
{
	int in_num, ou_num = 0;
	scanf("%d", &in_num);
	while (in_num > 0)
	{
		ou_num = ou_num + in_num % 10;
		in_num /= 10;
	}
	printf("%d", ou_num);
	return 0;
}