/*
    Necesitamos la cantidad de rectangulos posibles formados por palitos de distintos
    tanañso y necesitamos saber el area maxima que se puede hacer o -1 si no hay

    piesno que si contamos los palitos repetidos, 
    primero lo de afuera, luego dentro
*/
#include "main.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particion(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if (arr[j] > pivote) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quick_sort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);
        quick_sort(arr, bajo, pi - 1);
        quick_sort(arr, pi + 1, alto);
    }
}

bool repartir(int *palos, int n, int idx, int sumas[4], int objetivos[4]) {
    if (idx == n) {
        return 
            sumas[0] == objetivos[0] && sumas[1] == objetivos[1] &&
            sumas[2] == objetivos[2] && sumas[3] == objetivos[3];
    }
    int palo = palos[idx];
    for (int i = 0; i < 4; i++) {
        if (sumas[i] + palo > objetivos[i]) continue;
        if (i > 0 && objetivos[i] == objetivos[i - 1] && sumas[i] == sumas[i - 1]) continue;
        sumas[i] += palo;
        if (repartir(palos, n, idx + 1, sumas, objetivos)) return true;
        sumas[i] -= palo;
    }
    return false;
}

bool puede_form(int *palos, int n, int A, int B) {
    int objetivos[4] = {A, A, B, B};
    int sumas[4] = {0, 0, 0, 0};
    return repartir(palos, n, 0, sumas, objetivos);
}

int palitos(int palos[], int len) {
    int suma = 0;
    for (int i = 0; i < len; i++) suma += palos[i];
    if (suma % 2 != 0) 
        return -1;

    int mitad = suma / 2;
    int maxA = mitad / 2;

    quick_sort(palos, 0, len - 1);
    if (palos[0] > mitad - 1) 
        return -1;
    for (int A = maxA; A >= 1; A--) {
        int B = mitad - A;
        if (A>B) continue;
        if (palos[0] > B) continue;

        if (puede_form(palos, len, A, B)) {
            return A * B;
        }
    }
    return -1;
}

int ctr_palitos(){
    int n;
    printf("Ingrese la longitud\n");
    if (scanf("%d", &n) != 1) 
        return 0;
    int *palos = (int*)malloc(n * sizeof(int));
    if (!palos) 
        return 1;
    printf("Ingrese los numeros\n");
    for (int i = 0; i < n; i++) {
        setbuf(stdin,NULL);
        scanf("%d", &palos[i]);
    }
    printf("Procesando\n");
    int res = palitos(palos, n);
    if(res==-1){
        printf("No se pudo encontrar el area maxima\n");
    }
    else
        printf("%d\n", res);
    free(palos);
    return 0;
}