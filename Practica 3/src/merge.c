#include "main.h"

bool merge(int *arr, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    //arreglos temporales dinamicos para mitades
    int *L = (int *)malloc(n1 * sizeof(int));
    int *M = (int *)malloc(n2 *sizeof(int));

    if(L==NULL || M==NULL){
        printf("ERROR al generar memoria de arreglo\n");
        return ERROR;
    }
    //

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }

    free(L);
    free(M);
    return true;
}

bool merge_sort(int *arr, int l, int r){
  if (l < r) {

    int m = l + (r - l) / 2;

    if(!merge_sort(arr, l, m)) return ERROR;
    if(!merge_sort(arr, m + 1, r)) return ERROR;

    if(!merge(arr, l, m, r)) return ERROR;
  }
  return true;
}

bool ctr_mer(int n, int *arr){
    if(n<0||n>MAX){
        return ERROR;
    }
    merge_sort(arr,0,n);
    return true;
}