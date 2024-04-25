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

unsigned long CountInMonth(DataTemperature sensor[], int month);

float AverageMonthly(DataTemperature sensor[], int month);

int MinTempMonthly(DataTemperature sensor[], int month);

int MaxTempMonthly(DataTemperature sensor[], int month);

void AverageYear(DataTemperature sensor[]);

void MinTempYear(DataTemperature sensor[]);

void MaxTempYear(DataTemperature sensor[]);

void print_help(void);