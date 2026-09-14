#include "main.h"
/*
comando gcc *.o -o pr1
gcc -c archivo.c
.\pr1
*/

int main(){
    printf("Practica 1\n\n");
    
    bool continuar=false;
    do{
        printf("Ingrese la opcion deseada:\n");
        printf("1- Sticks\n");
        printf("2- Whats next?\n");
        printf("3- Cryptograpy\n");

        int opcion;
        setbuf(stdin,NULL);
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                printf("Sticks:\n");
                
                if(ctr_palitos()!=0){
                    printf("Hubo un error\n");
                }
                break;
            case 2:
                printf("Whats next?:\n");
                
                if(ctr_wh()!=0){
                    printf("Hubo un error\n");
                }
                break;
            case 3:
                printf("Cryptograpy:\n");
                if(!ctr_cifrado()){
                    printf("Hubo un error\n");
                }
                break;
            default:
                printf("Sticks:\n");
                
                if(ctr_palitos()!=0){
                    printf("Hubo un error\n");
                }
                break;
        }
        char desicion;
        printf("Continuar? Y/N\n");
        setbuf(stdin,NULL);
        scanf(" %c",&desicion);
        if(desicion=='N'|| desicion=='n'){
            continuar=false;
        }
        else{
            continuar=true;
        }

    }while(continuar);
    return 0;
}