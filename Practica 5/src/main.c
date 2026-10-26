#include "main.h"

int main() {
    char num1[10000];
    char num2[10000];
    
    printf("Ingrese el primer numero: ");
    fflush(stdout);
    if (scanf("%9999s", num1) != 1) {
        printf("Error al leer el primer numero.\n");
        return 1;
    }
    
    printf("Ingrese el segundo numero: ");
    fflush(stdout);
    if (scanf("%9999s", num2) != 1) {
        printf("Error al leer el segundo numero.\n");
        return 1;
    }

    clock_t inicio = clock();

    // Convertir a binario (arreglos de enteros)
    int lenBin1, lenBin2;
    int *bin1 = decimal_a_binario(num1, &lenBin1);
    int *bin2 = decimal_a_binario(num2, &lenBin2);

    // Multiplicar en binario
    int lenResBin;
    int *resBin = multiplicar(bin1, lenBin1, bin2, lenBin2, &lenResBin);

    char *resDec = binario_a_decimal(resBin, lenResBin);

    clock_t fin = clock();

    printf("\nResultado: %s\n", resDec);
    printf("Tiempo: %f segundos\n", (double)(fin - inicio) / CLOCKS_PER_SEC);

    free(bin1);
    free(bin2);
    free(resBin);
    free(resDec);
    return 0;
}