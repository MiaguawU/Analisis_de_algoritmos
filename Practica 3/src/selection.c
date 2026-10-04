#include "main.h"

bool selection_sort(int n, int *arr) {
    int i, j, ini = 0, fin = n - 1;

    while (ini < fin) {
        int min = ini;
        int max = ini;
        for (j = ini; j <= fin; j++) {
            if (arr[j] < arr[min]) 
                min = j;
            if (arr[j] > arr[max]) 
                max = j;
        }
        if (min != ini) {
            int aux = arr[ini];
            arr[ini] = arr[min];
            arr[min] = aux;
            if (max == ini) 
                max = min;
        }
        if (max != fin) {
            int aux = arr[fin];
            arr[fin] = arr[max];
            arr[max] = aux;
        }
        ini++;
        fin--;
    }
    return true;
}