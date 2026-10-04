#include "main.h"

bool bubble_sort(int n, int *arr) {
    int i, j, aux, fin = n - 1, ultimo = 0;

    while (fin > 0) {
        ultimo = 0;
        for (j = 0; j < fin; j++) {
            if (arr[j] > arr[j + 1]) {
                int aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                ultimo = j;
            }
        }
        fin = ultimo;
    }
    return true;
}
