#include "main.h"

/*
gcc -c archivo.c
gcc *.o -o pr3
.\pr3

CON TXT:
crear archivo entrada.txt poner datos

gcc pr3.c -o pr3; .\pr3; code resultado.txt
*/

bool main(){
    int n;
    int accion;
    //1, bubble, 2, insertion, 3, selection, 4, merge
    if(!abrir_archivos(&n, &accion)) return ERROR;
    
    //generar el arreglo 
    int *arr;
    if(!gen_arr(n,&arr)) return ERROR;
    
    bool ok;
    switch (accion)
    {
    case Bubble:
        printf("BUBBLE-SORT\n");
        break;
    case Insertion:
        printf("INSERTION-SORT\n");
        ok= insertion_sort(n, arr);
        break;
    case Selection:
        printf("SELECTION-SORT\n");
        break;
    case Merge:
        printf("MERGE-SORT\n");
        ok=ctr_mer(n,arr);
        break;
    
    default:
        printf("BUBBLE\n");
        break;
    }
    
    if(ok && n<=50){
        printf("\nArreglo ordenado: \n\n\n");

        for(int i=0;i< n;i++){
                printf("%d\n",*(arr+i));
        }
        printf("\n");}
    
    cerrar_archivos();
    free(arr);
    return true;
}