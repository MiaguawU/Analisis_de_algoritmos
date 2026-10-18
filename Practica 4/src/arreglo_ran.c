#include "main.h"

bool arr_rand(int *arr, const int *n, bool peor_caso) {
    srand(time(NULL));

    if (*n < 1 || *n > MAX ) {
        printf("Numero invalido\n");
        return false;
    }

    if (peor_caso) {
        int rango = 2 * ENTEROS_MAX + 1;      
        int rep  = (*n) / rango + 1;         
        int k = 0;
        for (int v = -ENTEROS_MAX; v <= ENTEROS_MAX && k < *n; v++) {
            for (int r = 0; r < rep && k < *n; r++) {
                arr[k++] = v;
            }
        }
    } 
    else {
        for (int i = 0; i < *n; i++) {
            long r = ((long)rand() << 15) ^ rand();
            arr[i] = (int)(r % (2L * ENTEROS_MAX + 1)) - ENTEROS_MAX;
        }
    }

    return true;
}

bool gen_arr(int n, int **arr, bool peor_caso) {
    *arr = (int *)malloc(n * sizeof(int));
    if (*arr == NULL) {
        printf("ERROR al generar memoria de arreglo\n");
        return ERROR;
    }

    if (!arr_rand(*arr, &n, peor_caso)) {
        printf("ERROR al generar array\n");
        free(*arr);
        *arr = NULL;
        return ERROR;
    }
    return true;
}