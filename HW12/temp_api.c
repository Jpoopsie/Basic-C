#include "temp_api.h"

void AverageMonthly(DataTemperature sensor[], int a, int month)
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < a; i++)
	{
		if (sensor[i].month == month)
		{
			sum += sensor[i].temperature;
			count++;
		}
	}
	if (count > 0)
	{
		float average = (float)sum / count;
		printf("The average temperature for month %d is %.2f\n", month, average);
	}
	else
	{
		printf("No data available for month %d\n", month);
	}
}

void print_help(void)
{
	printf("\nProgram information:\n");
	printf("-h for help.\n");
	printf("-f <filename.csv> for loading the specified file.\n");
	printf("-m <month number> to display statistics for the specified month.\n");
}