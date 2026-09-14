/*
La reina quiere que las casas no tengas numeros repetidos,como 898 o 1002
Asi que:
    Nos dara un rango de 1=< N =< M =<5000,
    Y nosotros le daremos el maximo de casas que se pueden poner entre esos num

Nosotros podriamos hacer que al saber el centecimo o el decimo o milesimo,
no repita ese mismo, se lo salte

si N=3201 y M= 4980
podemos hacer sumas

si sabemos que es 3000, nos saltamos el 300, 30 y 3
(para eos podria ser que i*1000 o i*100), de forma que siempre se salte los iguales

en el caso anterior podemos hacer una division, lo que quede casteado a int es la 
    cantidad por la que se multiplica, ejemplo (N%1000 == 3)? si, entonces, 
    evitamos 3 para esta milesima

pienso que algo asi, 

a= qb +r

si a = 3298 b=10

3298= 10(329) + 8

asi obtener el ultimo digito
*/
#include "main.h"

int son_dif_dig(int numero){
    bool hay_repetido=false;
    int n;
    while(!hay_repetido){
        n= numero%10;
    }
}

