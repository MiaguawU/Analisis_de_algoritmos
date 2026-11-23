#include "main.h"

/*
gcc -c archivo.c
gcc *.o -o pr6
.\pr6*/

static bool comparar_matrices(int n, int *A, int *B){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(A[i * n + j] != B[i * n + j]) return false;
        }
    }
    return true;
}

int main(){
    int exponente;
    int n;

    printf("Introduzca el exponente (la matriz sera de 2^exponente x 2^exponente): ");
    fflush(stdout);
    if(scanf("%d", &exponente) != 1){
        printf("Error al leer el exponente\n");
        return 1;
    }

    if(exponente < 1 || exponente > 14){
        printf("El exponente debe estar entre 1 y 14\n");
        return 1;
    }

    n = 1 << exponente;

    if(!abrir_archivo()) return 1;

    srand(12345);

    int *A, *B;
    int *C_puro, *C_wino, *C_trad;
    if(!gen_matriz(n, &A)) return 1;
    if(!gen_matriz(n, &B)) return 1;
    if(!crear_matriz(n, &C_puro)) return 1;
    if(!crear_matriz(n, &C_wino)) return 1;
    if(!crear_matriz(n, &C_trad)) return 1;

    if (n <= 8) {
        imprimir("MATRIZ A (Tamano %d x %d)\n\n", n, n);
        imprimir_matriz(n, A);
        imprimir("\nMATRIZ B (Tamano %d x %d)\n\n", n, n);
        imprimir_matriz(n, B);
    }

    clock_t ini_p = clock();
    bool ok_p = strassen_puro(n, n, A, 0, 0, n, B, 0, 0, n, C_puro, 0, 0);
    clock_t fin_p = clock();
    double t_p = (double)(fin_p - ini_p) / CLOCKS_PER_SEC;
    imprimir("\nTiempo de ejecucion (Strassen puro):    %f segundos\n", t_p);

    clock_t ini_w = clock();
    bool ok_w = strassen_winograd_hibrido(n, n, A, 0, 0, n, B, 0, 0, n, C_wino, 0, 0);
    clock_t fin_w = clock();
    double t_w = (double)(fin_w - ini_w) / CLOCKS_PER_SEC;
    imprimir("\nTiempo de ejecucion (Strassen-Winograd): %f segundos\n", t_w);

    clock_t ini_t = clock();
    bool ok_t = multiplicacion_tradicional(n, A, B, C_trad);
    clock_t fin_t = clock();
    double t_t = (double)(fin_t - ini_t) / CLOCKS_PER_SEC;
    imprimir("\nTiempo de ejecucion (Tradicional):      %f segundos\n", t_t);

    if(ok_p && ok_w && ok_t){
        bool iguales = comparar_matrices(n, C_puro, C_wino) &&
                       comparar_matrices(n, C_puro, C_trad);
        imprimir("\nResultados coinciden: %s\n", iguales ? "SI" : "NO");
    }

    if (n <= 8) {
        if(ok_p){
            imprimir("\nMATRIZ RESULTADO C (Strassen puro)\n\n");
            imprimir_matriz(n, C_puro);
        }
        if(ok_w){
            imprimir("\nMATRIZ RESULTADO C (Strassen-Winograd)\n\n");
            imprimir_matriz(n, C_wino);
        }
        if(ok_t){
            imprimir("\nMATRIZ RESULTADO C (Tradicional)\n\n");
            imprimir_matriz(n, C_trad);
        }
    }

    imprimir("\n=Tiempos\n");
    imprimir("Tamano de la matriz: %d x %d\n", n, n);
    imprimir("Strassen puro:      %f s\n", t_p);
    imprimir("Strassen-Winograd:  %f s\n", t_w);
    imprimir("Tradicional:        %f s\n", t_t);
    imprimir("====================================================\n");

    liberar_matriz(A);
    liberar_matriz(B);
    liberar_matriz(C_puro);
    liberar_matriz(C_wino);
    liberar_matriz(C_trad);
    cerrar_archivo();
    
    return 0;
}