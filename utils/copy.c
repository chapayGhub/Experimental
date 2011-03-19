#include "fileutils.h"

void usage() {
	fprintf(stderr, "Usage: %s <destfile> <srcfile>\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	if(argc < 3)
		usage();
	
	copy_file(argv[1], argv[2]);

	return(0);
}
