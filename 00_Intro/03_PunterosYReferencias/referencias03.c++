#include <stdio.h>
#include <iostream>

using namespace std;

void haz_negativo(int &num) {

    if (num > 0)
        num = -num;

}

int & maximo(int & num1, int & num2) {

    if (&num1 > &num2)
        return num1;

    return num2;

}

int * maximo2(int &num1, int &num2) {

    if (num1 > num2)
        return &num1;

    return &num2;

}

int &maximo3(int *num1, int *num2) {

    if (*num1 > *num2) {
        return *num1;
    }
    return *num2;

}

int main(int argc, char *argv[]) {

    int i = 2;
    int j = 12;

    (maximo3(&i, &j)) = 2000;

    cout << "El valor de i es " << i << endl;

}
