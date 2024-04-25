#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include "temp_api.h"

int main(int argc, char *argv[])
{

	/* ===================================================================================================================================== */

	/*Вывод справки*/

	DataTemperature *sensor = NULL;
	sensor = malloc(600000 * sizeof(DataTemperature));
	int opt = 0, month = 0, size = 0;
	char data[100];
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
	unsigned long count = 0;
	while (fgets(data, sizeof(data), input) != NULL)
	{
		// printf("Data: %s", data);
		if (sscanf(data, "%d;%d;%d;%d;%d;%d", &sensor[count].year, &sensor[count].month, &sensor[count].day, &sensor[count].hour,
				   &sensor[count].minute, &sensor[count].temperature) != 6)
		{
			// printf("Error reading data: %s", data);
			continue;
		}
		count++;
		// printf("%ld\n", count);
	}
	fclose(input);

	/* ===================================================================================================================================== */

	/*Вывод данных*/

	if (month > 0 && month <= 12)
	{
		printf("#  YEAR  MONTH  NuValue  ErValue  MonthAvg  MonthMax  MonthMin\n");
		printf("1  2021    %d    %5ld       -     %6.2f      %4d     %4d\n",
			   month, CountInMonth(sensor, month), AverageMonthly(sensor, month), MaxTempMonthly(sensor, month), MinTempMonthly(sensor, month));
	}
	if (month == 0)
	{
		printf("#  YEAR  MONTH  NuValue  ErValue  MonthAvg  MonthMax  MonthMin\n");
		printf("1  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   1, CountInMonth(sensor, 1), AverageMonthly(sensor, 1), MaxTempMonthly(sensor, 1), MinTempMonthly(sensor, 1));
		printf("2  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   2, CountInMonth(sensor, 2), AverageMonthly(sensor, 2), MaxTempMonthly(sensor, 2), MinTempMonthly(sensor, 2));
		printf("3  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   3, CountInMonth(sensor, 3), AverageMonthly(sensor, 3), MaxTempMonthly(sensor, 3), MinTempMonthly(sensor, 3));
		printf("4  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   4, CountInMonth(sensor, 4), AverageMonthly(sensor, 4), MaxTempMonthly(sensor, 4), MinTempMonthly(sensor, 4));
		printf("5  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   5, CountInMonth(sensor, 5), AverageMonthly(sensor, 5), MaxTempMonthly(sensor, 5), MinTempMonthly(sensor, 5));
		printf("6  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   6, CountInMonth(sensor, 6), AverageMonthly(sensor, 6), MaxTempMonthly(sensor, 6), MinTempMonthly(sensor, 6));
		printf("7  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   7, CountInMonth(sensor, 7), AverageMonthly(sensor, 7), MaxTempMonthly(sensor, 7), MinTempMonthly(sensor, 7));
		printf("8  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   8, CountInMonth(sensor, 8), AverageMonthly(sensor, 8), MaxTempMonthly(sensor, 8), MinTempMonthly(sensor, 8));
		printf("9  2021    %d    %5ld       -      %6.2f    %4d      %4d\n",
			   9, CountInMonth(sensor, 9), AverageMonthly(sensor, 9), MaxTempMonthly(sensor, 9), MinTempMonthly(sensor, 9));
		printf("10 2021   %d    %5ld       -      %6.2f    %4d      %4d\n",
			   10, CountInMonth(sensor, 10), AverageMonthly(sensor, 10), MaxTempMonthly(sensor, 10), MinTempMonthly(sensor, 10));
		printf("11 2021   %d    %5ld       -      %6.2f    %4d      %4d\n",
			   11, CountInMonth(sensor, 11), AverageMonthly(sensor, 11), MaxTempMonthly(sensor, 11), MinTempMonthly(sensor, 11));
		printf("12 2021   %d    %5ld       -      %6.2f    %4d      %4d\n",
			   12, CountInMonth(sensor, 12), AverageMonthly(sensor, 12), MaxTempMonthly(sensor, 12), MinTempMonthly(sensor, 12));
	}
	printf("Year statistics: average is %.2f, max is %d, min is %d", AverageYear(sensor), MaxTempYear(sensor), MinTempYear(sensor));
	free(sensor);
	return 0;
}
