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