#include "main.h"

/*
gcc -c archivo.c
gcc *.o -o pr2
.\pr2

CON TXT:
crear archivo entrada.txt poner datos

gcc pr2.c -o pr2; .\pr2; code resultado.txt
*/
int main(){
    if(!ctr_perm()){
        printf("ERROR");
    }
    return 0;
}