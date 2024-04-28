#include "temp_api.h"

unsigned long CountInMonth(DataTemperature sensor[], int month)
{
	unsigned long count = 0;
	for (unsigned long i = 0; i < 600000; i++)
	{
		if (sensor[i].month == month)
			count++;
	}
	return count;
}

float AverageMonthly(DataTemperature sensor[], int month)
{
	long long sum = 0;
	unsigned long count = 0;
	for (unsigned long i = 0; i < 600000; i++)
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
	int min = 99;
	for (unsigned long i = 0; i < 600000; i++)
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
	int max = -99;
	for (unsigned long i = 0; i < 600000; i++)
	{
		if (sensor[i].month == month)
		{
			if (sensor[i].temperature > max)
				max = sensor[i].temperature;
		}
	}
	return max;
}

float AverageYear(DataTemperature sensor[])
{
	long long sum = 0;
	unsigned long count = 0;
	for (unsigned long i = 0; i < 600000; i++)
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
		return average;
	}
	else
	{
		printf("No data available for year.\n");
	}
}

int MinTempYear(DataTemperature sensor[])
{
	int min = 99;
	for (unsigned long i = 0; i < 600000; i++)
	{
		if (sensor[i].temperature < min)
			min = sensor[i].temperature;
	}
	return min;
}

int MaxTempYear(DataTemperature sensor[])
{
	int max = -99;
	for (unsigned long i = 0; i < 600000; i++)
	{
		if (sensor[i].temperature > max)
			max = sensor[i].temperature;
	}
	return max;
}

void print_help(void)
{
	printf("\nProgram information:\n");
	printf("-h for help.\n");
	printf("-f <filename.csv> for loading the specified file.\n");
	printf("-m <month number> to display statistics for the specified month.\n");
}