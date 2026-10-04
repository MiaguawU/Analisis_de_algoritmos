#include "main.h"

bool insertion_sort(int n, int *arr) {
    int i,j;
    for (i=1;i<n;i++) {
        j=i;
        while (j>0 && arr[j]<arr[j-1]) {
            int aux=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=aux;
            j--;
        }
    }
    return true;
}