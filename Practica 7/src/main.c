#include "main.h"

int main(){
    int n;

    printf("Introduzca la longitud del arreglo: ");
    if (scanf("%d", &n) != 1) {
        printf("Error al leer la longitud\n");
        return 1;
    }

    if (n < 1 || n > MAX) {
        printf("Longitud invalida (1 a %d)\n", MAX);
        return 1;
    }

    int *arr;
    if (!gen_arr(n, &arr)) return 1;

    printf("\nArreglo generado: { ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) 
            printf(", ");
    }
    printf(" }\n\n");

    if (!subcon_min(arr, n)) {
        printf("Error al ejecutar el algoritmo\n");
        free(arr);
        return 1;
    }

    free(arr);
    return 0;
}