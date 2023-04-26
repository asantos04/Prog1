#include <iostream>
#include "print_array.h"

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) {
    int i = 0, j = 0, k = 0; // valores de referência para os elementos dos arrays

    while (i < na && j < nb) { // enquanto houverem elementos para comparar em ambas os arrays
        if (a[i] < b[j]) {  //comparar os elementos das posições correspondentes e adicionar a *c* (pode-se comparar desta forma pois se encontram baralhados de forma ascendente, logo c também será em forma ascendente)
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < na) { // se *a* for maior que *b*, adicionar os restantes elementos de *a* a *c*
        c[k++] = a[i++];
    }

    while (j < nb) { // se *b* for maior que *a*, adicionar os restantes elementos de *b* a *c*
        c[k++] = b[j++];
    }
}









