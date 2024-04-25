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

void AverageMonthly(DataTemperature sensor[], int month);

void MinTempMonthly(DataTemperature sensor[], int month);

void MaxTempMonthly(DataTemperature sensor[], int month);

void AverageYear(DataTemperature sensor[]);

void MinTempYear(DataTemperature sensor[]);

void MaxTempYear(DataTemperature sensor[]);

void print_help(void);