#include "main.h"

void swap(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particion(int *arr, int ini, int fin, bool aleatorio) {
       
    if(aleatorio && fin > ini){
        int piv = ini + rand() % (fin - ini + 1);
        swap(&arr[piv], &arr[fin]);
    }
    
    int pivote = arr[fin];
    int i = ini - 1;

    for (int j = ini; j < fin; j++) {
        if (arr[j] <= pivote) {
            i++;
            if(i != j )
                swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[fin]);

    return i + 1;
}

bool quick_sort(int n, int *arr, bool aleatorio) {
    if (n < 1 || arr == NULL) return ERROR;

    int piv = particion(arr, 0, n-1, aleatorio);
    
    quick_sort(n - piv - 1, arr + piv + 1, aleatorio);
    quick_sort(piv, arr, aleatorio);              
      
    return true;
}

bool quick_sort2(int n, int *arr, bool aleatorio) {
    if (n < 1 || arr == NULL) return true;

    while (n > 1) {
        int piv = particion(arr, 0, n - 1, aleatorio);

        if (piv < n - piv - 1) {
            quick_sort2(piv, arr, aleatorio);                    
            arr += piv + 1;                          
            n   -= piv + 1;
        } else {
            quick_sort2(n - piv - 1, arr + piv + 1, aleatorio);  
            n = piv;                                 
        }
    }
    return true;
}