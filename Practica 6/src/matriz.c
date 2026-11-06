#include "main.h"

bool crear_matriz(int n, int **m){
    *m = (int*)calloc((size_t)n * n, sizeof(int));
    return (*m != NULL);
}

void liberar_matriz(int *m){
    free(m);
}

void liberar_arreglo(int **arreglo, int cantidad){
    if(arreglo == NULL) return;
    for(int i = 0; i < cantidad; i++){
        if(arreglo[i] != NULL){
            free(arreglo[i]);
            arreglo[i] = NULL;
        }
    }
}

bool gen_matriz(int n, int **m){
    if(!crear_matriz(n, m)) return ERROR;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            (*m)[i * n + j] = rand() % 3; 
            // (*m)[i * n + j] = 1; 
        }
    }
    return true;
}

void imprimir_matriz(int n, int *m){
    if(n > 32) return;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            imprimir("%4d", m[i * n + j]);
        }
        imprimir("\n");
    }
}