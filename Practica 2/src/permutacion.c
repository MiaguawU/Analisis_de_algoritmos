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
int agregar_comb(char* comb1, char** comb2, int inicio, int iteraciones, char** res){
    int i=inicio, j=0;
    //en este caso comb1 son las combinaciones de la primera parte y lo mismo con el 2
    //queremos que una comb tenga todas las comb2, ejemplo: AB + comb posibles
    while(j<iteraciones){
        strcpy(res[i],comb1);
        strcat(res[i],comb2[j]);
        i++;
        j++;
    }
    return i;
}
bool swap(char* cadena, int a, int b){
    char aux= cadena[a];
    cadena[a]=cadena[b];
    cadena[b]=aux;
    return true;
}
int permutar(char cadena[], int inicio, int final, char** res){
    int len= final-inicio;
    int fact=factorial(len);
    int i=0, j=0;

    if(len==2){
        
        res[0][0]=cadena[inicio];
        res[0][1]=cadena[inicio+1];
        res[0][2]='\0';

        res[1][0]=cadena[inicio+1];
        res[1][1]=cadena[inicio];
        res[1][2]='\0';
    }
    else if(len>4){
        //dividimos  para luego unir 
        int mid=len-2;
        int f2= factorial(mid);
        char mid1[2][3];
        char mid2[f2][mid +1];
        
        int index1=0;//primera parte AB + comb
        int index2=fact/len;// BA +combc
        
        char cad_moldeable[len];
        strcpy(cad_moldeable,cadena+inicio);

        while(i<fact/2 && index2<fact){
            if(permutar(cad_moldeable, 0, 2, mid1)<2 || 
                permutar(cad_moldeable, 2, len, mid2)<2){
                    return ERROR;
            }
            //ahora juntamos, y repetimos
            index1=agregar_comb(mid1[0], mid2,index1,f2,res);
            index2=agregar_comb(mid1[1], mid2,index2,f2,res);
            if(index1<0||index1>fact){
                return ERROR;
            }
            if(index2<0||index2>fact){
                return ERROR;
            }
            i++;
            strcpy(cad_moldeable,cadena+inicio);
            if(!swap(cad_moldeable, 1, 2)){
                return ERROR;
            }
            index2=(fact/len)*i;
        }

    }
    else{
        //strcpy(perm[i],  permutar(perm,cadena,len,i,j));
        //tomamos la letra en i y cat con las combinaciones de los que sigue
        char comb[fact/len][len +1];
        while(i<len && j<fact){
            strcpy(res[j],cadena[i]);//A
            if(permutar(cadena, 1, len, comb)<2){
                return ERROR;
            }
            j=agregar_comb(strcat(cadena[i],'\0'), comb, j, fact/len, res);
            if(j<0){
                return ERROR;
            }
            i++;
        }
    }

    return fact;
} 
bool ctr_perm(){
    int len;
    printf("Introdusca la longitud\n");
    scanf("%d", &len);
    if(len<1){
        printf("ERROR: no se puede generar permutaciones con ea longitud\n");
        return false;
    }

    int fact=factorial(len);
    char perm[fact][len+1];
    char cadena[len+1];

    printf("Intrusca la cadena\n");
    setbuf(stdin,NULL);
    fgets(cadena,len+1,stdin);
    *(cadena + strcspn(cadena, "\n")) = '\0';

    if(permutar(cadena,0,len,perm)==ERROR){
        printf("ERROR al permutar\n");
        return false;
    }

    for(int i=0; i<fact; i++){
        printf("%s, ",perm[i]);
    }
    printf("\n");
    return true;
}


