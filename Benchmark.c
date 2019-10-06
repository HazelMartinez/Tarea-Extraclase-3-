//
// Created by bryan on 2/10/19.
//

#include "Benchmark.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/time.h>

/***************************************************
Declaraciones de funciones de utilidad utilizadas en el punto de referencia. Son
definido después de la función principal. No necesitas entender cómo
funcionan, solo utilícelos en sus puntos de referencia copiando y pegando.
***************************************************/

/* Devuelve un entero aleatorio en el rango especificado. */
static int random_int (int minval, int maxval);

/* Devuelve una matriz recién asignada con enteros aleatorios len del
rango especificado. La matriz devuelta debe liberarse al final de
el programa. */
static int * random_array (int minval, int maxval, size_t len);

/* Devuelve la hora actual en milisegundos en formato doble. El primero
cuando se llama a esta función, restablece una referencia interna y
devuelve cero A partir de entonces, devuelve el número de milisegundos.
desde ese reinicio. */
static double clockms (void);

/***************************************************
Implementaciones de las funciones de utilidad para crear datos aleatorios y
medir el tiempo de ejecución
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
        *ii = random_int (0, maxval);
    }

    return arr;
}

double clockms (void)
{
    static struct timeval t0 = { 0, 0 };
    struct timeval t1;

    if (0 == t0.tv_sec) {
        if (0 != gettimeofday (&t0, NULL)) {
            printf("error obtener hora del día");
            return 42.42;
        }
    }
    if (0 != gettimeofday (&t1, NULL)) {
        printf("error obtener hora del día");
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
