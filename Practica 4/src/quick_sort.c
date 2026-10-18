#include "main.h"

void swap(int A[], int *a, int *b) {
    int aux = A[*a];
    A[*a] = A[*b];
    A[*b] = aux;
}

int particion_rand(int A[], int *p, int *r) {
    int aleatorio = *p +rand()%(*r-*p +1);

    swap(A, &aleatorio, r);

    int x = A[*r];
    int i = *p -1;

    for (int j=*p; j<*r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A, &i, &j);
        }
    }

    i++;
    swap(A, &i, r);
    return i;
}

int particion_pri(int A[], int *p, int *r) {
    int x = A[*p];
    int i = *p;

    for (int j = *p + 1; j <= *r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A, &i, &j);
        }
    }

    swap(A, p, &i);
    return i;
}

int particion_fin(int A[], int *p, int *r) {
    int x = A[*r];
    int i = *p - 1;

    for (int j = *p; j < *r; j++) {
        if (A[j] <= x) {
            i++;
            swap(A, &i, &j);
        }
    }

    i++;
    swap(A, &i, r);
    return i;
}

bool quick_sort(int A[], int *p, int *r, Opcion *o) {
    if (*p < *r) {
        int q;

        if (*o == Primero)
            q = particion_pri(A, p, r);
        else if (*o == Ultimo)
            q = particion_fin(A, p, r);
        else
            q = particion_rand(A, p, r);

        int finIzq = q - 1;
        int inicioDer = q + 1;

        quick_sort(A, p, &finIzq, o);
        quick_sort(A, &inicioDer, r, o);
    }

    return true;
}