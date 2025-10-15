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

int main(int argc, char *argv[]) {

    int a = 9;
    int b = 10;

    int *max;
    max = maximo(&a,&b);

    *max = *max + 20;

    cout << "La variable b vale: " << b << endl;

    return 0;

}
