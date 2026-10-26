#include "main.h"

int* multiplicar(const int *X, int lenX, const int *Y, int lenY, int *lenRes) {
    // Caso base: n = 1 bit
    if (lenX == 1 && lenY == 1) {
        int *res = (int*)malloc(sizeof(int));
        res[0] = X[0] * Y[0];
        *lenRes = 1;
        return res;
    }

    int n;
    if (lenX > lenY) {
        n = lenX;
    } else {
        n = lenY;
    }
    if (n % 2 != 0) {
        n++;
    }

    // Rellenar con ceros a la izquierda
    int *xp = (int*)calloc(n, sizeof(int));
    int *yp = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < lenX; i++) {
        xp[n - lenX + i] = X[i];
    }
    for (int i = 0; i < lenY; i++) {
        yp[n - lenY + i] = Y[i];
    }

    int mitad = n / 2;
    int lenL = n - mitad;
    int lenR = mitad;

    int *xL = (int*)malloc(lenL * sizeof(int));
    int *xR = (int*)malloc(lenR * sizeof(int));
    int *yL = (int*)malloc(lenL * sizeof(int));
    int *yR = (int*)malloc(lenR * sizeof(int));

    for (int i = 0; i < lenL; i++) {
        xL[i] = xp[i];
        yL[i] = yp[i];
    }
    for (int i = 0; i < lenR; i++) {
        xR[i] = xp[lenL + i];
        yR[i] = yp[lenL + i];
    }

    int lenP1;
    int *P1 = multiplicar(xL, lenL, yL, lenL, &lenP1);

    int lenP2;
    int *P2 = multiplicar(xR, lenR, yR, lenR, &lenP2);

    int lenSumX, lenSumY;
    int *sumX = sumar_bin(xL, lenL, xR, lenR, &lenSumX);
    int *sumY = sumar_bin(yL, lenL, yR, lenR, &lenSumY);
    int lenP3;
    int *P3 = multiplicar(sumX, lenSumX, sumY, lenSumY, &lenP3);

    int lenTemp, lenCentral;
    int *temp = restar_bin(P3, lenP3, P1, lenP1, &lenTemp);
    int *central = restar_bin(temp, lenTemp, P2, lenP2, &lenCentral);

    int lenP1_des, lenCentral_des, lenRes1, lenFinal;

    int *P1_des = desplazar_bin(P1, lenP1, n, &lenP1_des);
    int *central_des = desplazar_bin(central, lenCentral, mitad, &lenCentral_des);

    int *res1 = sumar_bin(P1_des, lenP1_des, central_des, lenCentral_des, &lenRes1);
    int *resultado = sumar_bin(res1, lenRes1, P2, lenP2, &lenFinal);

    /*free(xp);
    free(yp);
    free(xL);
    free(xR);
    free(yL);
    free(yR);
    free(P1);
    free(P2);
    free(sumX);
    free(sumY);
    free(P3);
    free(temp);
    free(central);
    free(P1_des);
    free(central_des);
    free(res1);*/
    liberar_memoria(xp,yp,xL,xR,yL,yR,P1,P2,sumX,sumY,P3,temp,central,P1_des,central_des,res1);

    *lenRes = lenFinal;
    return resultado;
}