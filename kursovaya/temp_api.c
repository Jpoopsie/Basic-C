#include "temp_api.h"

int CountInMonth(DataTemperature sensor[], int month)
{
	int count = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (sensor[i].month == month)
			count++;
	}
	return count;
}

float AverageMonthly(DataTemperature sensor[], int month)
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < 1000; i++)
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
		return average;
	}
	else
	{
		printf("No data available for month %d\n", month);
	}
}

int MinTempMonthly(DataTemperature sensor[], int month)
{
	int min = 10000;
	for (int i = 0; i < 1000; i++)
	{
		if (sensor[i].month == month)
		{
			if (sensor[i].temperature < min)
				min = sensor[i].temperature;
		}
	}
	return min;
}

int MaxTempMonthly(DataTemperature sensor[], int month)
{
	int max = -10000;
	for (int i = 0; i < 1000; i++)
	{
		if (sensor[i].month == month)
		{
			if (sensor[i].temperature > max)
				max = sensor[i].temperature;
		}
	}
	return max;
}

void AverageYear(DataTemperature sensor[])
{
	int sum = 0;
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		if (sensor[i].year == 2021)
		{
			sum += sensor[i].temperature;
			count++;
		}
	}
	if (count > 0)
	{
		float average = (float)sum / count;
		printf("The average temperature for year is %.2f degrees Celsius\n", average);
	}
	else
	{
		printf("No data available for year.\n");
	}
}

void MinTempYear(DataTemperature sensor[])
{
	int min = 10000;
	for (int i = 0; i < 100; i++)
	{
		if (sensor[i].temperature < min)
			min = sensor[i].temperature;
	}
	printf("The minimal temperature for year is %d degrees Celsius\n", min);
}

void MaxTempYear(DataTemperature sensor[])
{
	int max = -10000;
	for (int i = 0; i < 100; i++)
	{
		if (sensor[i].temperature > max)
			max = sensor[i].temperature;
	}
	printf("The maximum temperature for year is %d degrees Celsius\n", max);
}

void print_help(void)
{
	printf("\nProgram information:\n");
	printf("-h for help.\n");
	printf("-f <filename.csv> for loading the specified file.\n");
	printf("-m <month number> to display statistics for the specified month.\n");
}