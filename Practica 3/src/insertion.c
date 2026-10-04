#include "main.h"

bool insertion_sort(int n, int *arr) {
    int i, j, aux;
    for (i = 1; i < n; i++) {
        aux = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > aux) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = aux;
    }
    return true;
}