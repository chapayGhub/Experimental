#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#include <math.h>

typedef struct coordinates
{
	/* name of location */
	char *description;

	/* latitude; N=+, S=-; i.e., 42 deg N is +42 */
	float lat;

	/* longitude; E=+, W=- */
	float lon;

} coordinate;

/*
 * Calculate the approximate distance between two points on Earth.
 * http://www.meridianworlddata.com/Distance-calculation.asp
 * Parameters: latitude, longitude
 * Returns distance in miles.
 */
float calc_distance(coordinate src, coordinate des)
{
	float lat_delta = (src.lat - des.lat) * 69.1;
	float lon_delta = (src.lon - des.lon) * 69.1 * cos(src.lat / 57.3);
	return sqrt((lat_delta * lat_delta) + (lon_delta * lon_delta));
}

/*
	City			Latitude	Longitude
	Barrow			71 N		157 W
	Buenos Aires	34 S		58 W
	Cairo			30 N		31 E
	Calcutta		22.5 N		88 E
	Capetown		34 S		18 E
	Chicago			42 N		87.5 W
	Honolulu		21 N		158 W
	London			51.5 N		0.0 W
	Los Angeles		34 N		118 W
	Melatico City	19.5 N		99.5 W
	Moscow			56 N		37.5 E
	New York		41 N		75 W
	Paris			49 N		2E
	São Paulo		23.5 S		47 W
	Shanghai		31 N		121 E
	Sydney			34 S		151 E
	Tokyo			36 N		140 E
	Tromso			68.5N		17 E
	Birmingham		33.5		-86.8
*/

#endif
