//
// Created by hazel on 4/10/19.
//
#include "inserion_sort.h"
///
/// \param a
/// \param n
/// tomado de https://rosettacode.org/wiki/Sorting_algorithms/Insertion_sort

void insertion_sort(int *a, int n) {
    for(size_t i = 1; i < n; ++i) {
        int tmp = a[i];
        size_t j = i;
        while(j > 0 && tmp < a[j - 1]) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = tmp;
    }
}

