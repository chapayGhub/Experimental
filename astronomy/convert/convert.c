#include <stdlib.h>
#include <math.h>

#include "convert.h"

/* conversion calcuations */

double conv_deg_to_rad(double deg) 
{
    /* 1 radian = 57.3 degrees */
    
    return deg * (M_PI / 180.0);
}

double conv_rad_to_deg(double rad) 
{
    return (180.0 * rad) / M_PI;
}

