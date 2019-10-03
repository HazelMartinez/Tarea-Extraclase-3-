//
// Created by hazel on 3/10/19.
//

#include "SelectionSortTest.h"
#include<stdio.h>


void shellSort(int array[],int dim);
void printArray(int array[],int dim);
int main()
{

    int  array []= {10,9,7,2,-3};
    int d = 5;
    printArray(array,d);
    selectionSort(array,d);
    printArray(array,d);

}


/* FUNCTION TO SORT USING THE SELECTION SORT ALGORITHM */

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

/* FUNCTION TO PRINT THE ARRAY */

void printArray(int array[],int dim){
    int i;
    for(i = 0; i<dim;i++){
        printf(" %d ",array[i]);
    }
    printf("\n");
}