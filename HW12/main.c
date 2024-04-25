#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "temp_api.h"

int main(int argc, char *argv[])
{
	/* ===================================================================================================================================== */

	/*Вывод справки*/

	DataTemperature sensor[1000] = {0};
	int opt = 0, month = 0, a = 0;
	char data[1000];
	int size = 0;
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
			strncpy(data, optarg, sizeof(data));
			size = strlen(data);
			break;
		case 'm':
			month = atoi(optarg);
			if (1 > month || month > 12)
			{
				printf("The number cannot be less than 1 and greater than 12.");
				return 1;
			}
		default:
			break;
		}
	}

	/* ===================================================================================================================================== */

	/*Чтение из файла*/

	FILE *input;
	char ch;
	input = fopen(data, "r");
	if (input == NULL)
	{
		printf("Error openning file.\n");
		return 1;
	}
	int count = 0;
	while (fgets(data, sizeof(data), input) != NULL)
	{
		// printf("Data: %s", data);
		if (sscanf(data, "%d;%d;%d;%d;%d;%d", &sensor[count].year, &sensor[count].month, &sensor[count].day, &sensor[count].hour,
				   &sensor[count].minute, &sensor[count].temperature) != 6)
		{
			printf("Error reading data: %s", data);
			continue;
		}
		count++;
	}
	fclose(input);

	/* ===================================================================================================================================== */

	/*Вывод данных*/

	if (month > 0 && month <= 12)
	{
		AverageMonthly(sensor, month);
		MinTempMonthly(sensor, month);
		MaxTempMonthly(sensor, month);
	}
	if (month == 0)
	{
		AverageYear(sensor);
		MinTempYear(sensor);
		MaxTempYear(sensor);
	}
	return 0;
}
