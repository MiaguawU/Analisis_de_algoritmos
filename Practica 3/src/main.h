#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ERROR            false
#define MAX              2000000

#define ENTEROS_MAX      10000

typedef enum{
    Bubble,
    Insertion,
    Selection,
    Merge
}Sorts;

//
bool abrir_archivos(int *n, int* accion);
void cerrar_archivos();

//arreglo
bool arr_rand(int *arr,const int *n);
bool gen_arr(int n,int **arr);

//metodos
bool ctr_mer(int n, int *arr);
bool insertion_sort(int n, int *arr);
bool bubble_sort(int n, int *arr);
bool selection_sort(int n, int *arr);

#endif