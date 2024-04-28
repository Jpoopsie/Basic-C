#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "temp_api.h"
#include <unistd.h>

#define MAXCHAR 100000

int main(int argc, char *argv[])
{

	int k, m = 0, p = 0, y = 0, i = 0, r = 0;
	char dir[100], *s;
	FILE *fp;

	sensor tarr[MAXCHAR];

	// opterr=0;

	while ((p = getopt(argc, argv, "hf:m:y:")) != -1)
	{

		switch (p)
		{
		case 'h':
			printhelp();
			return 0;
			break;
		case 'f':
			strcpy(dir, optarg);
			break;
		case 'm':
			m = atoi(optarg);
			if (m < 1 || m > 12)
			{
				printf("incorrect argument value: %s \n", argv[optind - 1]);
				printf("Try -m 1..12\n");
				m = 0;
			}
			break;
		case 'y':
			y = atoi(optarg);
			if (y < 1 || m > 65535)
			{
				printf("incorrect argument value: %s \n", argv[optind - 1]);
				printf("Try -y 1..65535\n");
				y = 0;
			}
			break;
		case '?':
			printf("Unknown argument: %s \n", argv[optind - 1]);
			printf("Try -h for help\n");
			// return 0;
		}
	}
	/////////////////////////////////////////////////////////////////////

	fp = fopen(dir, "r");

	if (fp == NULL)
	{
		printf("error open file\n");
		return 1;
	}

	while (!feof(fp))
	{

		r = fscanf(fp, "%d;%d;%d;%d;%d;%d", &tarr[i].year, &tarr[i].month,
				   &tarr[i].day, &tarr[i].hour, &tarr[i].min, &tarr[i].temperature);

		if (r < 6)
		{
			fgets(s, 100, fp);
			printf("Error in line number %d\n %s", i + 1, s);
		}
		else
			i++;
	}

	fclose(fp);

	//////////////////////////////////////////////////////////////////////
	k = i;
	// k = sizeof(tarr)/sizeof(tarr[0]) ;

	printf("\n");
	printf("statistic for");
	if (m)
		printf(" %d month ", m);
	if (y)
		printf(" %d year", y);
	printf("\n");

	printf("Tmax %d \n", maxtemp(m, y, k, tarr));
	printf("Tmin %d \n", mintemp(m, y, k, tarr));
	printf("Tavg %.2f \n", avgtemp(m, y, k, tarr));

	sortdate(k, tarr);

	// system("PAUSE");
	return 0;
}