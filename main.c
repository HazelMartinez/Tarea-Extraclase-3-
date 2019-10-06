#include <stdio.h>
#include "selection_sort.c"
#include "inserion_sort.c"
#include "bubble_sort.c"
#include "Benchmark.c"
int main (int argc,const char* argv[])
{
    int dmin = -30;
    int dmax = 10000;
    int nstart = 3;
    double nfac = 1.2;
    double nd;
    int *data;
    int *dup;

    printf("# Ingrese el número del algoritmo que desea utilizar\n"
           "# 1 - Bubble Sort\n"
           "# 2 - Selection Sort\n"
           "# 3 - Insertion Sort\n"
           "# => ");
    char operator;
    scanf("%c", &operator);

    printf("################################################\n"
           "# Ingrese la cantidad de valores que desea comprobar\n"
           "# Ejemplo: 10000\n"
           "# => ");
    int nmax;
    scanf("%d", &nmax);

    fflush(stdout);
    data = random_array(dmin, dmax, nmax);

    dup = malloc(nmax * sizeof(int));
    if (NULL == dup) {
        printf("error malloc");
        return EXIT_FAILURE;
    }

    printf("################################################\n"
           "#\n"
           "# Columna 1: N\n"
           "# Columna 2: T [ms]\n"
           "#\n");

    for (nd = nstart; nd <= nmax; nd *= nfac) {
        int nn;
        double tstart, tstop;

        nn = nd;

        printf("%8d", nn);
        fflush(stdout);

        memcpy(dup, data, nn * sizeof(int));

        tstart = clockms();
        if (tstart == 42.42) {
            return EXIT_FAILURE;
        }

        if(operator == '1'){bubble_sort(dup, nn);}
        if(operator== '2'){selectionSort(dup, nn);}
        if(operator == '3'){insertion_sort(dup, nn);}

        tstop = clockms();
        if (tstop == 42.42) {
            return EXIT_FAILURE;
        }

        printf("  %8g\n", tstop - tstart);
    }
    free(data);
    free(dup);
}
