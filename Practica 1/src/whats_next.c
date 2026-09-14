#include "main.h"

/*
Tenemos que identificar el patron(es) de la secuencia de 3 numeros

si es aritmetica si su secuencia es con sumar algo (AP)
si es geometrica si su secuacia es con multiplicar algo (GP)

buscamos que tienen en comun el numero con el siguiente
    5,7,9,11,13

    2,4,8,16,32

    7-5 = 2
    7/5= 1

*/

Secuencia* detectar_patron(int secuencia[], int len) {
    Secuencia* posible = (Secuencia*)malloc(sizeof(Secuencia));
    if (!posible) return NULL;

    posible->tipo = NINGUNO;
    posible->regla = 0.0;

    if (len < 3) {
        return posible;  
    }

    bool es_aritmetica = true;
    bool es_geometrica = true;

    int dif = secuencia[1] - secuencia[0];

    bool hay_cero = false;
    for (int i = 0; i < len; i++) {
        if (secuencia[i] == 0) hay_cero = true;
    }
    if (hay_cero) {
        es_geometrica = false;   
    }

    for (int i = 2; i < len; i++) {
        if (secuencia[i] - secuencia[i-1] != dif) {
            es_aritmetica = false;
        }
        if (es_geometrica) {
            if (secuencia[i] * secuencia[i-2] != secuencia[i-1] * secuencia[i-1]) {
                es_geometrica = false;
            }
        }
    }

    if (es_aritmetica && es_geometrica) {
        posible->tipo = AMBOS;
        posible->regla = dif;
    } else if (es_aritmetica) {
        posible->tipo = ARITMETICO;
        posible->regla = dif;
    } else if (es_geometrica) {
        posible->tipo = GEOMETRICO;
        if (secuencia[0] != 0) {
            posible->regla = (double)secuencia[1] / secuencia[0];
        } else {
            posible->regla = 0.0;
        }
    }

    return posible;
}

int ctr_wh(){
    int n;
    printf("Ingrese la longitud\n");
    if (scanf("%d", &n) != 1) return 0;

    int *secuencia = (int*)malloc(n * sizeof(int));
    if (!secuencia) return 1;

    printf("Ingrese los numeros\n");
    for (int i = 0; i < n; i++) {
        setbuf(stdin,NULL);
        scanf("%d", &secuencia[i]);
    }

    Secuencia* res = detectar_patron(secuencia, n);
    if (res) {
        switch (res->tipo) {
            case ARITMETICO: 
                printf("Aritmetica, diferencia = %.2f\n", res->regla); 
                break;
            case GEOMETRICO: 
                printf("Geometrica, razon = %.2f\n", res->regla); 
                break;
            case AMBOS:      
                printf("Ambos, regla = %.2f\n", res->regla); 
                break;
            default:         
                printf("Ninguno\n"); 
                break;
        }
        free(res);
    }

    free(secuencia);
    return 0;
}