#include <stdio.h>
#include <getopt.h>
#include "temp_api.h"

void print_help();

int main(int argc, char *argv[])
{
	int opt;
	char *file_name = NULL;
	int month = 0;
	if (argc == 1)
	{
		print_help();
		return 0;
	}

	while ((opt = getopt(argc, argv, "hf:m:")) != -1)
	{
		switch (opt)
		{
		case 'h':
			print_help();
			return 0;
		case 'f':
			file_name = optarg;
			break;
		case 'm':
			month = atoi(optarg);
			break;
		default:
			print_help();
			return 0;
		}
	}
}