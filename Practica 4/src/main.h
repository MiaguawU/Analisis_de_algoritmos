#ifndef MAIN_H
#define MAIN_H

<<<<<<< HEAD
#include <stdbool.h>
=======
>>>>>>> ulises
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ERROR            false
#define MAX              2000000

<<<<<<< HEAD
#define ENTEROS_MAX      10000

typedef enum{
    Primero,
    Ultimo,
    Azar
}Opcion;
=======
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
>>>>>>> ulises

//
bool abrir_archivos(int *n, int* accion);
void cerrar_archivos();
<<<<<<< HEAD
//leer entradas
bool leer_entradas(int **n, int **accion, char* seguir, bool primera);

//arreglo
bool arr_rand(int *arr,const int *n);
bool gen_arr(int n,int **arr);

//metodos
bool quick_sort(int A[], int *p, int *r, Opcion *o);
=======

//arreglo
bool arr_rand(int *arr,const int *n, bool peor_caso);
bool gen_arr(int n,int **arr, bool peor_caso);

//metodos
bool quick_sort(int n, int *arr, bool aleatorio);
bool quick_sort2(int n, int *arr, bool aleatorio);
>>>>>>> ulises

#endif