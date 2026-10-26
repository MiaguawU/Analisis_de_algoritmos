#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int* multiplicar(const int *X, int lenX, const int *Y, int lenY, int *lenRes);
int* decimal_a_binario(const char *dec, int *lenBin);
char* binario_a_decimal(const int *bin, int lenBin);
int* sumar(const int *a, int la, const int *b, int lb, int *lenRes);
int* restar(const int *a, int la, const int *b, int lb, int *lenRes);
int* desplazar(const int *a, int la, int k, int *lenRes);

#endif