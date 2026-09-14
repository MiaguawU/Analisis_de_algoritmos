//obtenemos un arreglo de k numeros enteros menores a 15,000 y mayores a 0
//devolvemos en cada posicion con un numero n entero positivo
//un numero primo en la n-aba posicion de los primos
//devolvemos un arreglo dinamico con n primos, 
//tomar el maximo y con ese hacer el arreglo, significa recorrer 2k y 1n?
#include "main.h"

int* obtener_primos(int n) {
    int* primos = (int*)malloc(n * sizeof(int));
    if (primos == NULL) {
        return NULL;
    }
    if (n >= 1) 
        primos[0] = 2;
    int q = 1;
    for (int i =3;q< n; i += 2) {
        bool es_primo = true;
        for (int j=0;j< q; j++) {
            if (i%primos[j] == 0) {
                es_primo = false;
                break;
            }
            if (primos[j]*primos[j] > i) {
                break;
            }
        }
        if (es_primo) {
            primos[q] = i;
            q++;
        }
    }
    return primos;
}

int maximo(int arr[], int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

bool ctr_cifrado() {
    int k;
    printf("Ingrese la longitud\n");
    if (scanf("%d", &k) != 1) 
        return false;
    if (k <= 0) 
        return false;

    int mensaje[k];
    printf("Ingrese los numeros\n");
    for (int i = 0; i < k; i++) {
        setbuf(stdin,NULL);
        if (scanf("%d", &mensaje[i]) != 1) 
            return false;
        if (mensaje[i] <= 0 || mensaje[i] > MAX_N) 
            return false;
    }
    int max = maximo(mensaje, k);
    int* primos = obtener_primos(max);
    if (primos == NULL) 
        return false;
    printf("Resultado:\n");
    for (int i = 0; i < k; i++) {
        printf("%d\n", primos[mensaje[i] - 1]);
    }
    free(primos);
    return true;
}