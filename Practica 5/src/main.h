#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//operaciones
int* multiplicar(const int *X, int lenX, const int *Y, int lenY, int *lenRes);
int* sumar(const int *a, int la, const int *b, int lb, int *lenRes);
int* restar(const int *a, int la, const int *b, int lb, int *lenRes);
//conversion
int* decimal_a_binario(const char *dec, int *lenBin);
char* binario_a_decimal(const int *bin, int lenBin);
//manejo de arreglos
int* desplazar(const int *a, int la, int k, int *lenRes);
void liberar_memoria(int *a, int*b, int*c, int*d, int*e, int*f, int*g, int*h,int*i, int*j, int*k, int*l, int*m,int*n, int*o, int*p);

#endif