
#include <stdio.h>
#include <getopt.h>
#include <time.h>

void about_program(void)
{
	printf("This application creates a txt file.\n");
	printf("The person's login and password are written to the txt file.\n");
	printf("The programme checks if there is a person with the given login and password in the system.\n");
	printf("If the person with the given login is not registered, the programme offers to register.\n");
	printf("If you are registered but entered an incorrect password, you will get an error.\n");
}

void registrations(void)
{
	// FILE *input;
	int size = 0;
	char ch, string[1000], txt[4] = ".txt";
	while (scanf("%c", &ch))
	{
		if (ch == '\n')
			break;
		string[size++] = ch;
	}
	for (int i = 0; i < 4; i++)
		string[size++] = txt[i];
	for (int i = 0; i < size; i++)
		printf("%c", string[i]);
	// input = fopen(string, "w");
}

void distributor(char letter)
{
	if (letter == '1')
		registrations();
	if (letter == '3')
		about_program();
}

int main(void)
{
	char letter;
	printf("Select your action.\n");
	printf("1. Registrations.\n");
	printf("2. Login.\n");
	printf("3. About programm.\n\n");
	printf("Your choose: ");
	for (int i = 0; i < 1; i++)
		scanf("%c", &letter);
	distributor(letter);
	return 0;
}