#include <stdio.h>

int main()
{
	int a;
	scanf( "%d", &a);
	switch (a)
	{
		case 1:
		case 2: printf("winter"); break;
		case 3: printf("spring"); break;
		case 4: printf("spring"); break;
		case 5: printf("spring"); break;
		case 6: printf("summer"); break;
		case 7: printf("summer"); break;
		case 8: printf("summer"); break;
		case 9: printf("autumn"); break;
		case 10: printf("autumn"); break;
		case 11: printf("autumn"); break;
		case 12: printf("winter"); break;
		default: return 1; break;
	}
	return 0;
}