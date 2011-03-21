#include <stdio.h>

#include "conv.h"

void usage() 
{
    fprintf( stderr, 
        "Usage:\n"
        "  conv rad <degrees>\n"
        "  conv deg <radians>\n");
    
    exit(0);
}

int main(int ac, char** av)
{
   
    if (ac==3) 
    {
        
        if (strcmp("rad", av[1]) == 0) 
        {
            printf("%.3f radians\n", conv_deg_to_rad(atof(av[2])));
            exit(0);
        }

        if (strcmp("deg", av[1]) == 0) 
        {
            printf("%.3f degrees\n", conv_rad_to_deg(atof(av[2])));
            exit(0);
        }    
   
    }

    usage();
        
    return(0);
}
