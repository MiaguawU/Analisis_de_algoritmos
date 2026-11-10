#include "main.h"

<<<<<<< HEAD
bool arr_rand(int *arr, const int *n) {
    srand(time(NULL));

    if (*n < 1 || *n >= MAX) {
=======
bool arr_rand(int *arr, const int *n, bool peor_caso) {
    srand(time(NULL));

    if (*n < 1 || *n > MAX ) {
>>>>>>> ulises
        printf("Numero invalido\n");
        return false;
    }

<<<<<<< HEAD
    for (int i = 0; i < *n; i++) {
        arr[i]=(rand() % (2*ENTEROS_MAX +1)) - ENTEROS_MAX;
=======
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
>>>>>>> ulises
    }

    return true;
}

<<<<<<< HEAD
bool gen_arr(int n,int **arr){
    *arr=(int *)malloc(n*sizeof(int));
    if(*arr==NULL){
=======
bool gen_arr(int n, int **arr, bool peor_caso) {
    *arr = (int *)malloc(n * sizeof(int));
    if (*arr == NULL) {
>>>>>>> ulises
        printf("ERROR al generar memoria de arreglo\n");
        return ERROR;
    }

<<<<<<< HEAD
    if(!arr_rand(*arr,&n)){
        printf("ERROR al general array\n");
=======
    if (!arr_rand(*arr, &n, peor_caso)) {
        printf("ERROR al generar array\n");
        free(*arr);
        *arr = NULL;
>>>>>>> ulises
        return ERROR;
    }
    return true;
}