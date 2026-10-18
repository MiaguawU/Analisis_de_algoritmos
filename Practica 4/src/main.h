#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ERROR            false
#define MAX              2000000

#define ENTEROS_MAX      100000

typedef enum{
    Quick,
    QuickIter,
    QuickPivRand,
    QuickPivRandIter,
    QuickPeor,
    QuickPeorIter,
    QuickPeorPivRand,
    QuickPeorPivRandIter,
}Sorts;

//
bool abrir_archivos(int *n, int* accion);
void cerrar_archivos();

//arreglo
bool arr_rand(int *arr,const int *n, bool peor_caso);
bool gen_arr(int n,int **arr, bool peor_caso);

//metodos
bool quick_sort(int n, int *arr, bool aleatorio);
bool quick_sort2(int n, int *arr, bool aleatorio);

#endif