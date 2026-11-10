#include "main.h"
#include <stdarg.h>

static FILE *archivo = NULL;

bool abrir_archivo(){
    archivo = fopen("resultado.txt", "w");
    if(archivo == NULL){
        printf("Error al abrir el archivo de salida\n");
        return ERROR;
    }
    return true;
}

void cerrar_archivo(){
    if(archivo != NULL){
        fclose(archivo);
        archivo = NULL;
    }
}

void imprimir(const char *formato, ...){
    va_list args;
    va_start(args, formato);
    vprintf(formato, args);
    va_end(args);

    if(archivo != NULL){
        va_start(args, formato);
        vfprintf(archivo, formato, args);
        va_end(args);
    }
}