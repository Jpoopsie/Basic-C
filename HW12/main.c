#include <stdio.h>
#include <getopt.h>
#include "temp_api.h"

int main(int argc, char *argv[])
{
	DataTemperature sensor[10] = {0};
	int opt = 0, i = 0;
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
			break;
		case 'f':
			if (optarg == NULL)
			{
				printf("Error: No filename provided.\n");
				return 1;
			}
			FILE *file = fopen(optarg, "r");
			if (file == NULL)
			{
				printf("Error: Could not open file %s.\n", optarg);
				return 1;
			}
			int i = 0;
			while (i < 100 && fscanf(file, "%d,%d,%d", &sensor[i].year, &sensor[i].month, &sensor[i].temperature) == 3)
			{
				i++;
			}
			fclose(file);
			for (int j = 0; j < i; j++)
			{
				printf("%d,%d,%d\n", sensor[j].year, sensor[j].month, sensor[j].temperature);
			}
			break;
		default:
			printf("Error: Invalid option.\n");
			return 1;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		printf("%d,%d,%d\n", sensor[i].year, sensor[i].month, sensor[i].temperature);
	}
}
