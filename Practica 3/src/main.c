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
    clock_t ini =clock();
    switch (accion)
    {
    case Bubble:
        printf("BUBBLE-SORT\n");
        ok = bubble_sort(n, arr);
        break;
    case Insertion:
        printf("INSERTION-SORT\n");
        ok= insertion_sort(n, arr);
        break;
    case Selection:
        printf("SELECTION-SORT\n");
        ok = selection_sort(n, arr);
        break;
    case Merge:
        printf("MERGE-SORT\n");
        ok=ctr_mer(n,arr);
        break;
    
    default:
        printf("Eliga una opcion válida\n");
        break;
    }

    clock_t fin =clock();
    double tiempo = (double)(fin-ini) / CLOCKS_PER_SEC;
    printf("\nTiempo de ejecución: %f segundos\n", tiempo);
    
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