#include <stdio.h>

#include "distance.h"

void print_calculations()
{
	printf("%35s: %5.2f miles\n", "Chicago to Birmingham", calc_distance(42.0, -87.5, 33.5, -86.8));
	printf("%35s: %5.2f miles\n", "Prime Meridian to Intl Date Line", calc_distance(0.0, 0.0, 0, 180.0));
	printf("%35s: %5.2f miles\n", "1/2 Earth's circumference", 24901.55 / 2.0);
	printf("%35s: %5.2f miles\n", "Earth's circumference", 24901.55);
}

int main(int ac, char **av)
{
	print_calculations();
	return(0);
}