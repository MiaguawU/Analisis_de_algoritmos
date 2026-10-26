#include "main.h"

int* decimal_a_binario(const char *dec, int *lenBin) {
    int len = strlen(dec);
    
    if (len == 0) {
        int *bin = (int*)malloc(sizeof(int));
        bin[0] = 0;
        *lenBin = 1;
        return bin;
    }

    int *digitos = (int*)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        digitos[i] = dec[i] - '0';
    }

    int *bin = (int*)calloc(len * 4 + 2, sizeof(int));
    int pos = 0;
    int quedan = 1;

    while (quedan) {
        int resto = 0;
        quedan = 0;
        for (int i = 0; i < len; i++) {
            int actual = resto * 10 + digitos[i];
            digitos[i] = actual / 2;
            resto = actual % 2;
            if (digitos[i] != 0) {
                quedan = 1;
            }
        }
        bin[pos] = resto;
        pos++;
    }

    if (pos == 0) {
        bin[pos] = 0;
        pos++;
    }

    for (int i = 0; i < pos / 2; i++) {
        int tmp = bin[i];
        bin[i] = bin[pos - 1 - i];
        bin[pos - 1 - i] = tmp;
    }

    free(digitos);
    *lenBin = pos;
    return bin;
}

char* binario_a_decimal(const int *bin, int lenBin) {
    int maxDec = lenBin + 1;
    int *dec = (int*)calloc(maxDec, sizeof(int));
    int lenDec = 1;
    dec[0] = 0;

    for (int i = 0; i < lenBin; i++) {
        // Multiplicar el decimal por 2
        int acarreo = 0;
        for (int j = 0; j < lenDec; j++) {
            int val = dec[j] * 2 + acarreo;
            dec[j] = val % 10;
            acarreo = val / 10;
        }
        while (acarreo) {
            if (lenDec >= maxDec) {
                maxDec = maxDec * 2;
                dec = (int*)realloc(dec, maxDec * sizeof(int));
            }
            dec[lenDec] = acarreo % 10;
            lenDec++;
            acarreo /= 10;
        }

        // Sumar el bit actual (0 o 1)
        if (bin[i] == 1) {
            int j = 0;
            int acarreo2 = 1;
            while (acarreo2) {
                if (j >= lenDec) {
                    if (lenDec >= maxDec) {
                        maxDec = maxDec * 2;
                        dec = (int*)realloc(dec, maxDec * sizeof(int));
                    }
                    dec[lenDec] = 0;
                    lenDec++;
                }
                int val = dec[j] + acarreo2;
                dec[j] = val % 10;
                acarreo2 = val / 10;
                j++;
            }
        }
    }

    char *res = (char*)malloc(lenDec + 1);
    for (int i = 0; i < lenDec; i++) {
        res[i] = dec[lenDec - 1 - i] + '0';
    }
    res[lenDec] = '\0';

    free(dec);
    return res;
}

int* sumar_bin(const int *a, int la, const int *b, int lb, int *lenRes) {
    int max;
    if (la > lb) {
        max = la;
    } else {
        max = lb;
    }
    max = max + 1;

    int *res = (int*)calloc(max, sizeof(int));
    int i = la - 1;
    int j = lb - 1;
    int k = max - 1;
    int acarreo = 0;

    while (i >= 0 || j >= 0 || acarreo) {
        int d1 = 0;
        if (i >= 0) {
            d1 = a[i];
            i--;
        }
        int d2 = 0;
        if (j >= 0) {
            d2 = b[j];
            j--;
        }
        int suma = d1 + d2 + acarreo;
        res[k] = suma % 2;
        acarreo = suma / 2;
        k--;
    }

    int inicio = k + 1;
    int len = max - inicio;
    int *final = (int*)malloc(len * sizeof(int));
    for (int p = 0; p < len; p++) {
        final[p] = res[inicio + p];
    }
    free(res);
    *lenRes = len;
    return final;
}

int* restar_bin(const int *a, int la, const int *b, int lb, int *lenRes) {
    int *res = (int*)malloc(la * sizeof(int));
    int i = la - 1;
    int j = lb - 1;
    int k = la - 1;
    int prestamo = 0;

    while (i >= 0) {
        int d1 = a[i] - prestamo;
        int d2 = 0;
        if (j >= 0) {
            d2 = b[j];
        }

        if (d1 < d2) {
            d1 = d1 + 2;
            prestamo = 1;
        } else {
            prestamo = 0;
        }

        res[k] = d1 - d2;
        i--;
        if (j >= 0) {
            j--;
        }
        k--;
    }

    // Quitar ceros a la izquierda
    int inicio = 0;
    while (inicio < la - 1 && res[inicio] == 0) {
        inicio++;
    }
    int len = la - inicio;
    if (len == 0) {
        len = 1;
    }
    int *final = (int*)malloc(len * sizeof(int));
    for (int p = 0; p < len; p++) {
        final[p] = res[inicio + p];
    }
    free(res);
    *lenRes = len;
    return final;
}

int* desplazar_bin(const int *a, int la, int k, int *lenRes) {
    int *res = (int*)malloc((la + k) * sizeof(int));
    for (int i = 0; i < la; i++) {
        res[i] = a[i];
    }
    for (int i = 0; i < k; i++) {
        res[la + i] = 0;
    }
    *lenRes = la + k;
    return res;
}

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

    free(xp);
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
    free(res1);

    *lenRes = lenFinal;
    return resultado;
}