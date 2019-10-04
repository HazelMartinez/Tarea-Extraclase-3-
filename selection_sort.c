//
// Created by hazel on 3/10/19.
//

#include "selection_sort.h"
#include "selection_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/time.h>


/***************************************************
  Selection  sort implementation
***************************************************/

void selectionSort(int * array, int dim){
    int i;
    int j;
    int minPos;								//position of the min  element
    for(i = 0; i <dim - 1 ; i++){
        minPos = i;

        // loop to find min element
        for (j = i + 1; j < dim ; j++){
            if(array[j]<array[minPos]){
                minPos = j;
            }
        }
        if (minPos != i){
            int change = array[i];
            array[i] = array[minPos];
            array[minPos] = change;
        }
    }
}



/***************************************************
  Declarations of utility functions used in the benchmark. They are
  defined after the main function. You do not need to understand how
  they work, just use them in your benchmarks by copy-pasting.
***************************************************/

/* Returns a random integer in the specified range. */
static int random_int (int minval, int maxval);

/* Returns a freshly allocated array with len random integers from the
   specified range. The returned array has to be freed at the end of
   the program. */
static int * random_array (int minval, int maxval, size_t len);

/* Returns the current time as milliseconds in double format. The first
   time this function is called, it resets an internal reference and
   returns zero. From then on it returns the number of milliseconds
   since that reset. */
static double clockms (void);


/***************************************************
  The main benchmark code begins here.
***************************************************/


/***************************************************
  Implementations of the utility functions to create random data and
  measure execution time.
  YOU DO NOT NEED TO UNDERSTAND THESE FUNCTIONS! Just copy-paste them
  as needed when you create new benchmark programs.
***************************************************/


int random_int (int minval, int maxval)
{
    int LO = -100, HI =100;
    int r = LO + rand() % (HI - LO);

    return r;
}


int * random_array (int minval, int maxval, size_t len)
{
    int * arr;
    int * ii;

    arr = malloc (len * sizeof(int));
    if (NULL == arr) {
        printf("error malloc");
    }

    for (ii = arr; len > 0; ++ii, --len) {
        *ii = random_int (minval, maxval);
    }

    return arr;
}


double clockms (void)
{
    static struct timeval t0 = { 0, 0 };
    struct timeval t1;

    if (0 == t0.tv_sec) {
        if (0 != gettimeofday (&t0, NULL)) {
            printf("error gettimeofday");
            return 42.42;
        }
    }
    if (0 != gettimeofday (&t1, NULL)) {
        printf("error gettimeofday");
        return 42.42;
    }

    return 1e3 * (t1.tv_sec - t0.tv_sec) + 1e-3 * (t1.tv_usec - t0.tv_usec);
}





void printArray(int * array ,int dim){
    int i;
    for(i = 0; i<dim;i++){
        printf(" %d ",array[i]);
    }
    printf("\n");
}