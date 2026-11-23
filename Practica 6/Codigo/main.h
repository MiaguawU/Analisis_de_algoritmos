#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ERROR            false
#define UMBRAL           64      

//manejo de archivos
bool abrir_archivo();
void cerrar_archivo();
void imprimir(const char *formato, ...);

//manejo memoria matriz
bool crear_matriz(int n, int **m);
void liberar_matriz(int *m);
void liberar_arreglo(int **arreglo, int cantidad);
bool gen_matriz(int n, int **m);
void imprimir_matriz(int n, int *m);

//operaciones
void calcular_offsets(int ai, int aj, int bi, int bj, int ci, int cj, int m, int *filas, int *columnas);
void suma_matriz(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj);
void resta_matriz(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj);
void suma_simple(int n, int N, int *A, int *B, int *C);
void resta_simple(int n, int N, int *A, int *B, int *C);
void pegar_temporal(int m, int N, int *T, int *C, int ci, int cj);
void tradicional(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj);

//metodos
bool multiplicacion_tradicional(int n, int *A, int *B, int *C);
bool strassen_puro(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj);
bool strassen_winograd_hibrido(int n, int NA, int *A, int ai, int aj, int NB, int *B, int bi, int bj, int NC, int *C, int ci, int cj);

#endif