#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *input;
typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int temperature;
} DataTemperature;


void AverageMonthly(DataTemperature sensor[], int a, int month);

void StatisticsOfMonth(DataTemperature sensor[], int a, int month);

void print_help(void);