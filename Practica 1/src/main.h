#ifndef main_h
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define   MAX_K          100
#define   MAX_N          15000
#define   MAX_DIf_DIG    5000

typedef enum { 
    NINGUNO, 
    ARITMETICO, 
    GEOMETRICO, 
    AMBOS 
}Tipo_Patron;

typedef struct Secuencia{
    Tipo_Patron tipo;
    double regla;
}Secuencia;

bool ctr_cifrado();
int ctr_wh();
int ctr_palitos();

#endif