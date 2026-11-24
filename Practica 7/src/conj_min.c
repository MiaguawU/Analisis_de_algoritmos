#include "main.h"

bool subcon_min(int *arr, int n) {
    if (n < 1 || arr == NULL){
        printf("Error: No se puede hacer un subconjunto");
        return ERROR;
    } 
        
    int total = 0;
    for (int i = 0; i < n; i++) 
        total += arr[i];

    if (!quick_sort(n, arr, true)){
        printf("Error al realizar el ordenanamiento");
        return ERROR;
    } 
        
    int total_sub = 0;
    int k = 0;
    int i = n - 1;

    while (i >= 0 && 2 * total_sub <= total) {
        total_sub += arr[i];
        k++;
        i--;
    }

    int total_rest = total - total_sub;
    int j;
    printf("Conjunto solucion optimo: { ");
    for (j = n - 1; j >= n - k; j--) {
        printf("%d", arr[j]);
        if (j > n - k) 
            printf(", ");
    }
    printf(" }\n");
    printf("Suma del subconjunto: %d\n\n", total_sub);
    printf("Total %d elementos\n", k);
    
    printf("Conjunto de elementos restantes: { ");
    for (j = 0; j < n - k; j++) {
        printf("%d", arr[j]);
        if (j < n - k - 1) 
            printf(", ");
    }
    printf(" }\n");
    printf("Suma del resto:       %d\n", total_rest);

    return true;
}