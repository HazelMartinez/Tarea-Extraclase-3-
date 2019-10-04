#include <stdio.h>
#include "selection_sort.c"
#include "inserion_sort.c"

int main (int argc,const char* argv[])
{

    //**********************************************Selection Sort******************************************************
    int dmin    =       0;
    int dmax    =    1000;
    int nstart  =      20;
    int nmax    =   50000;
    double nfac =       1.2;
    double nd;
    int * data;
    int * dup;

    /*
      Allocate one big random input data array. For varying the and
      making sure we always start with random input, we will use a
      duplicate (with just the first N entries) at each iteration.
    */

    printf ("# generating input data (this can take a while...)\n");
    fflush (stdout);
    data = random_array (dmin, dmax, nmax);

    dup = malloc (nmax * sizeof(int));
    if (NULL == dup) {
        printf("error malloc");
        return EXIT_FAILURE;

    }

    printf ("################################################\n"
            "#\n"
            "# merge sort runtime measurements\n"
            "#\n"
            "# column 1: N\n"
            "# column 2: T [ms]\n"
            "#\n");

    /*
      Main benchmarking loop.
      Note that we use a floating point "length" so that we can easily
      create a geometric series for N. This spaces the sampled array
      sizes more densely for small N, and for big N (where things
      usually take much longer) we don't take so many samples (otherwise
      running the benchmark takes a really long time).
    */

    for (nd = nstart; nd <= nmax; nd *= nfac) {
        int nn;
        double tstart, tstop;

        /*
          convert the floating point "length" to an integer
        */
        nn = nd;

        printf ("%8d", nn);
        fflush (stdout);

        /*
          use a fresh duplicate from the random input data
        */
        memcpy (dup, data, nn * sizeof(int));

        tstart = clockms ();
        if(tstart==42.42){
            return EXIT_FAILURE;
        }

        selectionSort(dup,nn);
        tstop = clockms ();
        if(tstop==42.42){
            return EXIT_FAILURE;
        }

        printf ("  %8g\n", tstop - tstart);
    }

    /*
      End of the program.
    */

    free (data);
    free (dup);

    //*****************************************************************************************************************
    printf ("*****************************************************************************************************************\n");

    printf ("inicio insertion sort\n");

    int a[] = {4, 65, 2, -31, 0, 99, 2, 83, 782, 1};
    int n = sizeof a / sizeof a[0];
    int i;
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    insertion_sort(a, n);
    for (i = 0; i < n; i++)
        printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    //return 0;

    return 0;

}