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
