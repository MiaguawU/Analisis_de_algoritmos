#include "main.h"

bool abrir_archivos(int *n, int* accion){
    freopen("entrada.txt", "r", stdin);   
    freopen("resultado.txt", "w", stdout); 

    if (stdin == NULL || stdout == NULL) {
        printf("Error al abrir los archivos\n");
        return ERROR;
    }

    char buffer[50];

    printf("Introduzca la longitud\n");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        *n = atoi(buffer);
        printf("%d\n", *n);
        (*n)-=1;
    } else {
        printf("Error al leer la longitud\n");
        return ERROR;
    }

    printf("Introduzca la opcion\n");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        *accion = atoi(buffer);
        printf("%d\n", *accion);
        (*accion)-=1;
    } else {
        printf("Error al leer la opcion\n");
        return ERROR;
    }

    return true;
}

void cerrar_archivos(){
    fclose(stdin);
    fclose(stdout);
}