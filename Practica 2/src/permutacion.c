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
bool arr_fact(int arr[],int n){
    int facto=1;
    int cont=0;
    for(int i=2; i<=n;i++){
        facto*=i;
        arr[cont]=facto;
        cont++;
    }
    return true;
}
bool swap(char cadena[], int a, int b){
    char aux= cadena[a];
    cadena[a]=cadena[b];
    cadena[b]=aux;
    return true;
}
int permutar(char cadena[], int n, int factoriales[]){
    int i, j;
    int cont=1;
    printf("\n\n\n");
    printf("%d-%s\n",cont,cadena);
    bool intercambio=false;

    bool cambia= false;
    for(i=1;i<factoriales[n-2] ;i++){
        cont++;
        for(j=n-1; j>1; j--){
            if((i) %  factoriales[j-2]==0){ //pienso que el siguiente if en impares apartir del 3
                if(j%2!=0){//intercambiar en funcion de factorial n con el ultimo

                    for(int k=3; k<=j; k++){//si es 5, seria 5 y 4
                        if(i ==(k)*factoriales[j-2 ] || 
                            (i-(k)*factoriales[j-2 ])% factoriales[j-2 + 1]==0){
                                if(!swap(cadena, n- (k-1), n-1-j)){
                                    return ERROR;
                                }
                                cambia=true;
                        }
                    }
                    
                }
                /*else if(j%2!=0&&
                    (i ==(3)*factoriales[j-2 ] || 
                        (i-(3)*factoriales[j-2 ])% factoriales[j-2 + 1]==0)){//intercambiar en funcion de factorial n con el ultimo
                    //n-j=3 o j%3 si es 4 da 1 si 5 da 2
                    if(!swap(cadena, n-2, n-1-j)){
                        return ERROR;
                    }
                    cambia=true;
                }*/
                if(!cambia){
                    if(!swap(cadena, n-1, n-1-j)){
                        return ERROR;
                    }
                }
                printf("%d-%s\n",cont,cadena);
                intercambio=true;
                cambia=false;
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
    return factoriales[n-2];
} 
bool ctr_perm_consola(){
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

    int factoriales[len - 1];
    
    if (!arr_fact(factoriales, len)) {
        printf("ERROR: no se pudo obtener el factorial\n");
        return false;
    }

    if(permutar(cadena, len, factoriales)==ERROR){
        printf("ERROR al permutar\n");
        return false;
    }

    printf("\n");
    return true;
}
bool ctr_perm(){
    freopen("entrada.txt", "r", stdin);   
    freopen("resultado.txt", "w", stdout); 

    if (stdin == NULL || stdout == NULL) {
        printf("Error al abrir los archivos\n");
        return 1;
    }

    char buffer[50];
    int len;

    printf("Introdusca la longitud\n");
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        len = atoi(buffer);
    } else {
        printf("Error al leer la longitud\n");
        return 1;
    }

    if (len < 2 || len > 15) {
        printf("ERROR: no se puede generar permutaciones con esa longitud\n");
        return false;
    }

    char cadena[len + 1];
    int factoriales[len - 1];
    
    if (!arr_fact(factoriales, len)) {
        printf("ERROR: no se pudo obtener el factorial\n");
        return false;
    }

    printf("Intrusca la cadena\n");
    fgets(cadena, len + 1, stdin);
    *(cadena + strcspn(cadena, "\n")) = '\0';

    if(permutar(cadena, len, factoriales)==ERROR){
        printf("ERROR al permutar\n");
        return false;
    }

    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return true;
}


