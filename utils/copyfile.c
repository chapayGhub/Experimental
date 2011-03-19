#include "fileutils.h"

void usage()
{
	fprintf(stderr, "Usage: <destfile> <srcfile>\n");
	exit(0);
}

int main(int ac, char **av)
{
	if(ac < 3)
		usage();

	char *des = av[1];
	char *src = av[2];

	copy_file(des, src);
	return(0);
}
