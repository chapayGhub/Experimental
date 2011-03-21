#ifndef _DISTANCE_H_
#define _DISTANCE_H_

typedef struct coordinate
{
	/* name of location */
	char *description;

	/* latitude; N=+, S=-; i.e., 42 deg N is +42 */
	float lat;

	/* longitude; E=+, W=- */
	float lon;

} coordinate;

extern float calc_distance(coordinate src, coordinate des);

#endif
