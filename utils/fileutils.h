#ifndef _FILEUTILS_H_
#define _FILEUTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*#include <sys/times.h>*/

/*
 * Very simple method to copy a file.
 * http://www.metalshell.com/
 */
void copy_file(char* dest, char* src)
{
	int src_file, dest_file;
	char buf[1024];
	int bytes;

	if((src_file = open(src, O_RDONLY)) == -1) {
		perror("open");
		exit(-1);
	}

	if((dest_file = open(dest, O_WRONLY | O_CREAT)) == -1) {
		perror("open");
		exit(-1);
	}

	while((bytes = read(src_file, buf, sizeof(buf))) > 0)
		write(dest_file, buf, bytes);

	close(src_file);
	close(dest_file);
}

/*
 * Fast copy file; read source into memory completely first.
 * Original author not known.
 */
int copy_filemem (char *src, char *des)
{
	if (!src | !des)
	{
		printf("nope\n");
		return(4);
	}

	FILE * pFile;
	long lSize;
	char * buffer;
	size_t result;

	/*struct tms before, after;*/

	/*times(&before);*/

	pFile = fopen ( src, "rb" );
	if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

	// obtain file size:
	fseek (pFile , 0 , SEEK_END);
	lSize = ftell (pFile);
	rewind (pFile);

	// allocate memory to contain the whole file:
	buffer = (char*) malloc ((sizeof(char)*lSize));
	if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}

	// copy the file into the buffer:
	result = fread (buffer,1,lSize,pFile);
	if (result != lSize) {fputs ("Reading error",stderr); exit (3);}

	printf("writing...\n");

	/* the whole file is now loaded in the memory buffer */
	FILE * outfile;
	outfile = fopen( des, "wb" );
	fwrite(buffer, 1, lSize, outfile);
	fflush(outfile);
	fclose(outfile);

	// terminate
	fclose (pFile);
	free (buffer);

	/*
	times(&after);
	printf("done...\n");
	printf("User time: %ld seconds\n", after.tms_utime -
	before.tms_utime);
	printf("System time: %ld seconds\n", after.tms_stime -
	before.tms_stime);
	*/

	return(0);
}

#endif
