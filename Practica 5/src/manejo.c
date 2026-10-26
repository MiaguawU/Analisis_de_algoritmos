#include "main.h"

int* desplazar_bin(const int *a, int la, int k, int *lenRes) {
    int *res = (int*)malloc((la + k) * sizeof(int));
    for (int i = 0; i < la; i++) {
        res[i] = a[i];
    }
    for (int i = 0; i < k; i++) {
        res[la + i] = 0;
    }
    *lenRes = la + k;
    return res;
}

void liberar_memoria(int *a, int*b, int*c, int*d, int*e, int*f, int*g, int*h,int*i, int*j, int*k, int*l, int*m,int*n, int*o, int*p){
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(g);
    free(h);
    free(i);
    free(j);
    free(l);
    free(m);
    free(n);
    free(o);
    free(p);    
}