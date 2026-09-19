/*
    dado una cadena (strings), encontrar las permutaciones
    EJemplo:
     A,B,C
        ->
        A,B,C
        A,C,B
        B,A,C
        B,C,A
        C,A,B
        C,B,A

    A,B,C,D
        ->
        A,B,C,D
        A,B,D,C
        A,C,B,D
        A,C,D,B
        A,D,B,C
*/
#include "main.h"

int factorial(int n){
    int facto=1;
    for(int i=n; i>0;i--){
        facto*=i;
    }
    return facto;
}
bool swap(char cadena[], int a, int b){
    char aux= cadena[a];
    cadena[a]=cadena[b];
    cadena[b]=aux;
    return true;
}
int permutar(char cadena[], int n){
    int i, j;
    int cont=1;
    printf("\n\n\n");
    printf("%d-%s\n",cont,cadena);
    bool intercambio=false;
    for(i=1;i<factorial(n) ;i++){
        cont++;
        for(j=n-1; j>1; j--){
            if((i) %  factorial(j)==0){ 
                if(i ==18 || (i-18)%24==0){//intercambiar en funcion de factorial n con el ultimo
                    //n-j=3 o j%3 si es 4 da 1 si 5 da 2
                    if(!swap(cadena, n-2, n-1-j)){
                        return ERROR;
                    }
                }
                else{
                    if(!swap(cadena, n-1, n-1-j)){
                        return ERROR;
                    }
                }
                printf("%d-%s\n",cont,cadena);
                intercambio=true;
                break;
            }
        }
        if(!intercambio){
            //cambiamos solo las ultimas
            if(!swap(cadena, n-1, n-2)){
                    return ERROR;
            }
            printf("%d-%s\n",cont,cadena);
        }
        intercambio=false;
        
    }
    return factorial(n);
} 
bool ctr_perm(){
    int len;
    printf("Introdusca la longitud\n");
    scanf("%d", &len);
    if(len<1){
        printf("ERROR: no se puede generar permutaciones con ea longitud\n");
        return false;
    }

    char cadena[len+1];

    printf("Intrusca la cadena\n");
    setbuf(stdin,NULL);
    fgets(cadena,len+1,stdin);
    *(cadena + strcspn(cadena, "\n")) = '\0';

    if(permutar(cadena, len)==ERROR){
        printf("ERROR al permutar\n");
        return false;
    }

    printf("\n");
    return true;
}


