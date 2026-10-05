#include "main.h"

bool leer_entradas(int **n, int **accion, char *seguir, bool primera)
{
    char buffer[50];

    if (!primera) {
        printf("Desea continuar\n");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            *seguir = buffer[0];
            printf("Letra: %c\n", *seguir);
        } else {
            printf("Error al leer continuar\n");
            return ERROR;
        }
    }

    printf("Introduzca la longitud\n");

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        **n = atoi(buffer);
        printf("%d\n", **n);
        (**n) -= 1;
    } else {
        printf("Error al leer la longitud\n");
        return ERROR;
    }

    printf("Introduzca la opcion\n");

    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        **accion = atoi(buffer);
        printf("%d\n", **accion);
        (**accion) -= 1;
    } else {
        printf("Error al leer la opcion\n");
        return ERROR;
    }

    return true;
}

bool abrir_archivos(int *n, int* accion){
    freopen("entrada.txt", "r", stdin);   
    freopen("resultado.txt", "w", stdout); 

    if (stdin == NULL || stdout == NULL) {
        printf("Error al abrir los archivos\n");
        return ERROR;
    }

    if(!leer_entradas(&n,&accion, NULL, true)){
        printf("Error al leer las entrada\n");
        return ERROR;
    }
    return true;
}

void cerrar_archivos(){
    fclose(stdin);
    fclose(stdout);
}