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
    //1 quick normal, 2 quick peor caso, 3 quick pivote aleatorio
    if(!abrir_archivos(&n, &accion)) return ERROR;
    bool peor_caso = (accion == QuickPeor || accion == QuickPeorIter || accion == QuickPeorPivRand || accion == QuickPeorPivRandIter);

    //generar el arreglo 
    int *arr;
    if(!gen_arr(n,&arr, peor_caso)) return ERROR;
    
    bool ok;
    clock_t ini =clock();
    switch (accion)
    {
    case Quick:
        printf("QUICK SORT, pivote al último\n");
        ok = quick_sort(n, arr, false);
        break;
    case QuickIter:
        printf("QUICK SORT, pivote al último iterativo\n");
        ok = quick_sort2(n, arr, false);
        break;
    case QuickPivRand:
        printf("QUICK SORT, pivote aleatorio\n");
        ok = quick_sort(n, arr, true);
        break;
    case QuickPivRandIter:
        printf("QUICK SORT, pivote aleatorio e iterativo\n");
        ok = quick_sort2(n, arr, true);
        break;
    case QuickPeor:
        printf("QUICK SORT, peor de los casos\n");
        ok= quick_sort(n, arr, false);
        break;
     case QuickPeorIter:
        printf("QUICK SORT, peor de los casos, iterativo\n");
        ok= quick_sort2(n, arr, false);
        break;
    case QuickPeorPivRand:
        printf("QUICK SORT, peor de los casos, pivote aleatorio\n");
        ok = quick_sort(n, arr, true);
        break;
    case QuickPeorPivRandIter:
        printf("QUICK SORT, peor de los casos, pivote aleatorio e iterativo\n");
        ok = quick_sort2(n, arr, true);
        break;
    default:
        printf("Elija una opcion válida\n");
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