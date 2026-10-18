#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ERROR            false
#define MAX              2000000

#define ENTEROS_MAX      10000

typedef enum{
    Primero,
    Ultimo,
    Azar
}Opcion;

//
bool abrir_archivos(int *n, int* accion);
void cerrar_archivos();
//leer entradas
bool leer_entradas(int **n, int **accion, char* seguir, bool primera);

//arreglo
bool arr_rand(int *arr,const int *n);
bool gen_arr(int n,int **arr);

//metodos
bool quick_sort(int A[], int *p, int *r, Opcion *o);

#endif