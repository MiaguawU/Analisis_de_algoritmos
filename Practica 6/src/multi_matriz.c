#include "main.h"

void calcular_offsets(int ai, int aj, int bi, int bj, int ci, int cj, int m,
                      int *filas, int *columnas) {
    filas[0] = ai;      filas[1] = ai;      filas[2] = ai + m;  filas[3] = ai + m;
    filas[4] = bi;      filas[5] = bi;      filas[6] = bi + m;  filas[7] = bi + m;
    filas[8] = ci;      filas[9] = ci;      filas[10]= ci + m;  filas[11]= ci + m;
    
    columnas[0] = aj;      columnas[1] = aj + m;  columnas[2] = aj;      columnas[3] = aj + m;
    columnas[4] = bj;      columnas[5] = bj + m;  columnas[6] = bj;      columnas[7] = bj + m;
    columnas[8] = cj;      columnas[9] = cj + m;  columnas[10]= cj;      columnas[11]= cj + m;
}

void suma_matriz(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[(ci + i) * NC + (cj + j)] = A[(ai + i) * NA + (aj + j)] + B[(bi + i) * NB + (bj + j)];
}

void resta_matriz(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[(ci + i) * NC + (cj + j)] = A[(ai + i) * NA + (aj + j)] - B[(bi + i) * NB + (bj + j)];
}

void suma_simple(int n, int N, int *A, int *B, int *C){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i * N + j] = A[i * N + j] + B[i * N + j];
}

void resta_simple(int n, int N, int *A, int *B, int *C){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            C[i * N + j] = A[i * N + j] - B[i * N + j];
}

void pegar_temporal(int m, int N, int *T, int *C, int ci, int cj){
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            C[(ci + i) * N + (cj + j)] = T[i * m + j];
}

void tradicional(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int suma = 0;
            for(int k = 0; k < n; k++){
                suma += A[(ai + i) * NA + (aj + k)] * B[(bi + k) * NB + (bj + j)];
            }
            C[(ci + i) * NC + (cj + j)] = suma;
        }
    }
}

bool multiplicacion_tradicional(int n, int *A, int *B, int *C){
    tradicional(n, n, A, 0, 0, n, B, 0, 0, n, C, 0, 0);
    return true;
}

bool strassen_puro(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj){
    if(n == 1){
        C[ci * NC + cj] = A[ai * NA + aj] * B[bi * NB + bj];
        return true;
    }

    int m = n / 2;
    int filas[12], columnas[12];
    calcular_offsets(ai, aj, bi, bj, ci, cj, m, filas, columnas);

    int a11i = filas[0], a11j = columnas[0]; int a12i = filas[1], a12j = columnas[1];
    int a21i = filas[2], a21j = columnas[2]; int a22i = filas[3], a22j = columnas[3];
    int b11i = filas[4], b11j = columnas[4]; int b12i = filas[5], b12j = columnas[5];
    int b21i = filas[6], b21j = columnas[6]; int b22i = filas[7], b22j = columnas[7];
    int c11i = filas[8], c11j = columnas[8]; int c12i = filas[9], c12j = columnas[9];
    int c21i = filas[10],c21j = columnas[10];int c22i = filas[11],c22j = columnas[11];

    // Temporales de tamaño m (rápido)
    int *S1, *S2, *S3, *S4, *S5, *S6, *S7, *S8, *S9, *S10;
    crear_matriz(m, &S1);  crear_matriz(m, &S2);
    crear_matriz(m, &S3);  crear_matriz(m, &S4);
    crear_matriz(m, &S5);  crear_matriz(m, &S6);
    crear_matriz(m, &S7);  crear_matriz(m, &S8);
    crear_matriz(m, &S9);  crear_matriz(m, &S10);

    resta_matriz(m, NB, B, b12i, b12j, NB, B, b22i, b22j, m, S1, 0, 0);   
    suma_matriz (m, NA, A, a11i, a11j, NA, A, a12i, a12j, m, S2, 0, 0);   
    suma_matriz (m, NA, A, a21i, a21j, NA, A, a22i, a22j, m, S3, 0, 0);   
    resta_matriz(m, NB, B, b21i, b21j, NB, B, b11i, b11j, m, S4, 0, 0);   
    suma_matriz (m, NA, A, a11i, a11j, NA, A, a22i, a22j, m, S5, 0, 0);   
    suma_matriz (m, NB, B, b11i, b11j, NB, B, b22i, b22j, m, S6, 0, 0);   
    resta_matriz(m, NA, A, a12i, a12j, NA, A, a22i, a22j, m, S7, 0, 0);   
    suma_matriz (m, NB, B, b21i, b21j, NB, B, b22i, b22j, m, S8, 0, 0);   
    resta_matriz(m, NA, A, a11i, a11j, NA, A, a21i, a21j, m, S9, 0, 0);   
    suma_matriz (m, NB, B, b11i, b11j, NB, B, b12i, b12j, m, S10, 0, 0);  

    int *P1, *P2, *P3, *P4, *P5, *P6, *P7;
    crear_matriz(m, &P1); crear_matriz(m, &P2);
    crear_matriz(m, &P3); crear_matriz(m, &P4);
    crear_matriz(m, &P5); crear_matriz(m, &P6);
    crear_matriz(m, &P7);

    // Llamadas recursivas especificando los anchos
    strassen_puro(m, NA, A, a11i, a11j, m, S1, 0, 0, m, P1, 0, 0);   
    strassen_puro(m, m, S2, 0, 0, NB, B, b22i, b22j, m, P2, 0, 0);   
    strassen_puro(m, m, S3, 0, 0, NB, B, b11i, b11j, m, P3, 0, 0);   
    strassen_puro(m, NA, A, a22i, a22j, m, S4, 0, 0, m, P4, 0, 0);   
    strassen_puro(m, m, S5, 0, 0, m, S6,  0, 0, m, P5, 0, 0);       
    strassen_puro(m, m, S7, 0, 0, m, S8,  0, 0, m, P6, 0, 0);       
    strassen_puro(m, m, S9, 0, 0, m, S10, 0, 0, m, P7, 0, 0);       

    int *tmp1, *tmp2;
    crear_matriz(m, &tmp1);
    crear_matriz(m, &tmp2);

    suma_simple (m, m, P5, P4, tmp1);
    resta_simple(m, m, tmp1, P2, tmp1);
    suma_simple (m, m, tmp1, P6, tmp2);
    pegar_temporal(m, NC, tmp2, C, c11i, c11j);

    suma_simple(m, m, P1, P2, tmp1);
    pegar_temporal(m, NC, tmp1, C, c12i, c12j);

    suma_simple(m, m, P3, P4, tmp1);
    pegar_temporal(m, NC, tmp1, C, c21i, c21j);

    suma_simple (m, m, P5, P1, tmp1);
    resta_simple(m, m, tmp1, P3, tmp1);
    resta_simple(m, m, tmp1, P7, tmp2);
    pegar_temporal(m, NC, tmp2, C, c22i, c22j);

    int *temporales[19] = {
        S1, S2, S3, S4, S5, S6, S7, S8, S9, S10,
        P1, P2, P3, P4, P5, P6, P7,
        tmp1, tmp2
    };
    liberar_arreglo(temporales, 19);

    return true;
}


bool strassen_winograd_hibrido(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj){
    if(n <= UMBRAL){
        tradicional(n, NA, A, ai, aj, NB, B, bi, bj, NC, C, ci, cj);
        return true;
    }

    int m = n / 2;
    int filas[12], columnas[12];
    calcular_offsets(ai, aj, bi, bj, ci, cj, m, filas, columnas);

    int a11i = filas[0], a11j = columnas[0]; int a12i = filas[1], a12j = columnas[1];
    int a21i = filas[2], a21j = columnas[2]; int a22i = filas[3], a22j = columnas[3];
    int b11i = filas[4], b11j = columnas[4]; int b12i = filas[5], b12j = columnas[5];
    int b21i = filas[6], b21j = columnas[6]; int b22i = filas[7], b22j = columnas[7];
    int c11i = filas[8], c11j = columnas[8]; int c12i = filas[9], c12j = columnas[9];
    int c21i = filas[10],c21j = columnas[10];int c22i = filas[11],c22j = columnas[11];

    int *S1, *S2, *S3, *S4, *S5, *S6, *S7, *S8, *S9, *S10;
    int *T1, *T2;
    crear_matriz(m, &S1);  crear_matriz(m, &S2);
    crear_matriz(m, &S3);  crear_matriz(m, &S4);
    crear_matriz(m, &S5);  crear_matriz(m, &S6);
    crear_matriz(m, &S7);  crear_matriz(m, &S8);
    crear_matriz(m, &S9);  crear_matriz(m, &S10);
    crear_matriz(m, &T1);  crear_matriz(m, &T2);

    resta_matriz(m, NB, B, b12i, b12j, NB, B, b22i, b22j, m, S1, 0, 0); 
    suma_matriz (m, NA, A, a11i, a11j, NA, A, a12i, a12j, m, S2, 0, 0); 
    suma_matriz (m, NA, A, a21i, a21j, NA, A, a22i, a22j, m, S3, 0, 0); 
    resta_matriz(m, NB, B, b21i, b21j, NB, B, b11i, b11j, m, S4, 0, 0); 
    suma_matriz (m, NA, A, a11i, a11j, NA, A, a22i, a22j, m, S5, 0, 0); 
    suma_matriz (m, NB, B, b11i, b11j, NB, B, b22i, b22j, m, S6, 0, 0); 
    resta_matriz(m, NA, A, a12i, a12j, NA, A, a22i, a22j, m, S7, 0, 0); 
    suma_matriz (m, NB, B, b21i, b21j, NB, B, b22i, b22j, m, S8, 0, 0); 
    resta_matriz(m, NA, A, a11i, a11j, NA, A, a21i, a21j, m, S9, 0, 0); 
    suma_matriz (m, NB, B, b11i, b11j, NB, B, b12i, b12j, m, S10, 0, 0);

    int *P1, *P2, *P3, *P4, *P5, *P6, *P7;
    crear_matriz(m, &P1); crear_matriz(m, &P2);
    crear_matriz(m, &P3); crear_matriz(m, &P4);
    crear_matriz(m, &P5); crear_matriz(m, &P6);
    crear_matriz(m, &P7);

    strassen_winograd_hibrido(m, NA, A, a11i, a11j, m, S1, 0, 0, m, P1, 0, 0);
    strassen_winograd_hibrido(m, m, S2, 0, 0, NB, B, b22i, b22j, m, P2, 0, 0);
    strassen_winograd_hibrido(m, m, S3, 0, 0, NB, B, b11i, b11j, m, P3, 0, 0);
    strassen_winograd_hibrido(m, NA, A, a22i, a22j, m, S4, 0, 0, m, P4, 0, 0);
    strassen_winograd_hibrido(m, m, S5, 0, 0, m, S6,  0, 0, m, P5, 0, 0);
    strassen_winograd_hibrido(m, m, S7, 0, 0, m, S8,  0, 0, m, P6, 0, 0);
    strassen_winograd_hibrido(m, m, S9, 0, 0, m, S10, 0, 0, m, P7, 0, 0);

    suma_simple (m, m, P1, P2, T1); 
    pegar_temporal(m, NC, T1, C, c12i, c12j);

    suma_simple (m, m, P3, P4, T1); 
    pegar_temporal(m, NC, T1, C, c21i, c21j);

    suma_simple (m, m, P5, P4, T1); 
    resta_simple(m, m, P6, P2, T2); 
    suma_simple (m, m, T1, T2, T1); 
    pegar_temporal(m, NC, T1, C, c11i, c11j);

    suma_simple (m, m, P5, P1, T1); 
    suma_simple (m, m, P3, P7, T2); 
    resta_simple(m, m, T1, T2, T1); 
    pegar_temporal(m, NC, T1, C, c22i, c22j);

    int *temporales[19] = {
        S1, S2, S3, S4, S5, S6, S7, S8, S9, S10,
        P1, P2, P3, P4, P5, P6, P7,
        T1, T2
    };
    liberar_arreglo(temporales, 19);

    return true;
} 