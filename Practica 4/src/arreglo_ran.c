#include "main.h"

bool arr_rand(int *arr, const int *n) {
    srand(time(NULL));

    if (*n < 1 || *n >= MAX) {
        printf("Numero invalido\n");
        return false;
    }

    for (int i = 0; i < *n; i++) {
        arr[i]=(rand() % (2*ENTEROS_MAX +1)) - ENTEROS_MAX;
    }

    return true;
}

bool gen_arr(int n,int **arr){
    *arr=(int *)malloc(n*sizeof(int));
    if(*arr==NULL){
        printf("ERROR al generar memoria de arreglo\n");
        return ERROR;
    }

    if(!arr_rand(*arr,&n)){
        printf("ERROR al general array\n");
        return ERROR;
    }
    return true;
}