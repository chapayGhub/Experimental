/* fread example: read a complete file */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/times.h>

int copy_file (char *src, char *des)
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

  struct tms before, after;

    times(&before);

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

  /* the whole file is now loaded in the memory buffer. */

  FILE * outfile;
  outfile = fopen( des, "wb" );
  fwrite(buffer, 1, lSize, outfile);
    fflush(outfile);

  fclose(outfile);

  // terminate
  fclose (pFile);
  free (buffer);

    times(&after);
  printf("done...\n");
       printf("User time: %ld seconds\n", after.tms_utime -
          before.tms_utime);
      printf("System time: %ld seconds\n", after.tms_stime -
        before.tms_stime);

  return 0;
}

int main(int argc, char **argv)
{
    copy_file(argv[1], argv[2]);
    return(0);
}
