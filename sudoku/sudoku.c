#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h> /* required for randomize() and random() */
#include <windows.h>

struct stack
{
    int length;
} _stack;

typedef struct
{
    int x;
} mystack;

struct sudoku
{
    int size;
    int seq[9];
} puzzle;

struct sudoku *p = &puzzle;

void test (struct stack *s)
{
    /* don't pass around an array */
    s->length=48;
}
/*
void stack1 ()
{
	_stack.length=88;
	printf("\n%d\n", _stack.length);
	struct stack *s=&_stack;
	s->length=42;
	test(s);
	printf("\n%d\n", s->length);
}

void stack2 ()
{
	mystack s;
	s.x=99;
	printf("\n\%d\n", s.x);
	mystack *p=&s;
	p->x=6;
	printf("\n\%d\n", p->x);

	/ i'm lost
	typedef struct stack *st;
	st v;
	v->length=222;
	printf("\n\%d\n", v->length);
	/
}
*/
void test2 ()
{
    struct sudoku *p5=&puzzle;

    p5->size=4;

    printf("\nsize: %d\n", p5->size);
}

/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;

        for (i = 0; i < n; i++)
        {
            /*size_t j = rand() % (n - i) + i + 1;*/
            //size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            // rand_max for better distribution

			size_t j = rand() % n;

			//printf("%d\n", j);
            int tmp = array[j];
            array[j] = array[i];
            array[i] = tmp;
        }
    }
}

typedef struct soduku
{
    int x;
    double y;
    char *z;
} Soduku;

int create_soduku(struct soduku *s)
{
    /*malloc here for new data, fake it now*/
    Soduku t;
    Soduku *ptr_s = &t;
    s=ptr_s;
    return 0;
}

struct soduku * create_soduku2()
{
    /*malloc here for new data, fake it now*/
    Soduku t;
    Soduku *ptr_s = &t;
    return ptr_s;
}

unsigned hash_time()
{
	/* Whatever you use, it's also a good idea to "exclusive OR"
	that value with your process ID. This covers the situation
	where you run your program many times in rapid succession.*/

    time_t now = time ( 0 );
    unsigned char *p = (unsigned char *)&now;
    unsigned seed = 0;
    size_t i;
    for ( i = 0; i < sizeof now; i++ )
        seed = seed * ( UCHAR_MAX + 2U ) + p[i];

    return seed;
}

int testme()
{
    /* Simple "srand()" seed: just use "time()" */
    unsigned int iseed = (unsigned int)time(NULL);
    srand (iseed);

    /* Now generate 5 pseudo-random numbers */
    int i;
    for (i=0; i<10; i++)
    {
    	int x = (rand() % 9) + 1;

        printf ("rand[%d]= %d\n", i, x);
    }
    return(0);
}

int main (int ac, char **av)
{
	//return testme();

	//char ch = getc(stdin);
	//printf("%c\n", ch);

    Soduku *ptr = NULL;
    create_soduku(ptr);

    Soduku *r = create_soduku2();
    /*randomize(r);*/

    /*printf("sizeof: %d\n", (int) sizeof(s));*/
    printf("sizeof: %d\n", (int) sizeof(*ptr));
    printf("sizeof: %d\n", (int) sizeof(ptr));
    printf("sizeof: %d\n", (int) sizeof(*r));

    int i;
    srand( hash_time() );

    for (i=0; i<9; i++)
        p->seq[i]=i+1;

    for (i=0; i<9; i++)
        printf("%d ", p->seq[i]);
    printf("\n");

    int *arr = &p->seq[0];
    shuffle(arr, 9);

    for (i=0; i<9; i++)
        printf("%d ", p->seq[i]);
    printf("\n");

    arr = &p->seq[0];
    for (i=0; i<9; i++)
        printf("%d ", *arr++);
    printf("\n");

    return(0);
}
