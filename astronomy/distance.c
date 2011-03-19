#include <stdio.h>

#include "distance.h"

void calculate()
{
	/* coordinates in latitude, logitude */

	coordinate src = 	{ "Chicago", 42.0, -87.5 };
	coordinate des = 	{ "Birmingham", 33.5, -86.8 };
	coordinate begin = 	{ "", 0.0, 0.0 };
	coordinate end = 	{ "", 0.0, -180.0 };

	printf("%35s: %5.2f miles\n", "Chicago to Birmingham*", calc_distance(src, des));
	printf("%35s: %5.2f miles\n", "Prime Meridian to Intl Date Line", calc_distance(begin, end));
	printf("%35s: %5.2f miles\n", "1/2 Earth's circumference", 24901.55 / 2.0);
	printf("%35s: %5.2f miles\n", "Earth's circumference", 24901.55);
	printf("%35s \n", "* that's too far :(");
}

int main(int ac, char **av)
{
	calculate();
	return(0);
}
