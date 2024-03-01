#include <stdio.h>
#include <string.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "ru_RU.UTF-8");
	char hex[100];
	int i, num = 0, val;
	printf("Введите число в шестнадцатеричной системе счисления: ");
	scanf("%s", hex);

	for (i = strlen(hex) - 1; i >= 0; i--) 
	{
    	if (hex[i] >= '0' && hex[i] <= '9') 
		{
			val = hex[i] - '0';
    	} 
		else if (hex[i] >= 'A' && hex[i] <= 'F') 
		{
			val = hex[i] - 'A' + 10;
    	} 
		else if (hex[i] >= 'a' && hex[i] <= 'f') 
		{
			val = hex[i] - 'a' + 10;
    	}
		else if (hex[i] > 'f' || hex[i] > 'F')
		{
			printf("Введены некорректные символы.\nВозможно использовать только: A(a), B(b), C(c), D(d), E(e), F(f).");
			return 1;
		}
    	num += val * pow(16, strlen(hex) - 1 - i);
}
printf("Ваше число в десятичной системе счисления: %d\n", num);
return 0;
}