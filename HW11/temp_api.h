#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int temperature;
} DataTemperature;

void StatisticsOfYear(DataTemperature sensor[], int a);

void StatisticsOfMonth(DataTemperature sensor[], int a, int month);