#include <stdio.h>
#include <iostream>

using namespace std;

void hazNegativo(int *pNum) {
    if (*pNum > 0) {
        *pNum = -(*pNum);
    }
}

int *maximo(int *pA, int *pB) {
    if (*pA > *pB)
       return pA;

    return pB;
}

int *calcularDiferencia(int *a, int *b, int dif, int *maxDif, int *pDif) {

    int *max;
    int *min;

    if (*a > *b) {
        max = a;
        min = b;
    } else
        max = b;
        min = a;

    int difActual = *max - *min;
    *pDif = difActual;

    if (difActual < *maxDif) return maxDif;

    if (difActual > *maxDif) {
        int bRestar = difActual - *maxDif;
        *b = *b - difActual;
    }

    return maxDif;

}

int main(int argc, char *argv[]) {

    int a = 5;
    int b = 10;

    int diferencia;
    int maximaDiferencia = 3;


    (*(calcularDiferencia(&a,&b,diferencia, &maximaDiferencia, &diferencia)));
    cout << "La diferencia era de " << diferencia << endl;

    return 0;

}
