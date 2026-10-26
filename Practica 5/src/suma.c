#include "main.h"

int* sumar_bin(const int *a, int la, const int *b, int lb, int *lenRes) {
    int max;
    if (la > lb) {
        max = la;
    } else {
        max = lb;
    }
    max = max + 1;

    int *res = (int*)calloc(max, sizeof(int));
    int i = la - 1;
    int j = lb - 1;
    int k = max - 1;
    int acarreo = 0;

    while (i >= 0 || j >= 0 || acarreo) {
        int d1 = 0;
        if (i >= 0) {
            d1 = a[i];
            i--;
        }
        int d2 = 0;
        if (j >= 0) {
            d2 = b[j];
            j--;
        }
        int suma = d1 + d2 + acarreo;
        res[k] = suma % 2;
        acarreo = suma / 2;
        k--;
    }

    int inicio = k + 1;
    int len = max - inicio;
    int *final = (int*)malloc(len * sizeof(int));
    for (int p = 0; p < len; p++) {
        final[p] = res[inicio + p];
    }
    free(res);
    *lenRes = len;
    return final;
}

int* restar_bin(const int *a, int la, const int *b, int lb, int *lenRes) {
    int *res = (int*)malloc(la * sizeof(int));
    int i = la - 1;
    int j = lb - 1;
    int k = la - 1;
    int prestamo = 0;

    while (i >= 0) {
        int d1 = a[i] - prestamo;
        int d2 = 0;
        if (j >= 0) {
            d2 = b[j];
        }

        if (d1 < d2) {
            d1 = d1 + 2;
            prestamo = 1;
        } else {
            prestamo = 0;
        }

        res[k] = d1 - d2;
        i--;
        if (j >= 0) {
            j--;
        }
        k--;
    }

    // Quitar ceros a la izquierda
    int inicio = 0;
    while (inicio < la - 1 && res[inicio] == 0) {
        inicio++;
    }
    int len = la - inicio;
    if (len == 0) {
        len = 1;
    }
    int *final = (int*)malloc(len * sizeof(int));
    for (int p = 0; p < len; p++) {
        final[p] = res[inicio + p];
    }
    free(res);
    *lenRes = len;
    return final;
}