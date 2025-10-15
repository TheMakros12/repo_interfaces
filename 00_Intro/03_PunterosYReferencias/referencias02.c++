#include <stdio.h>
#include <iostream>

using namespace std;

void haz_negativo(int &num) {

    if (num > 0)
        num = -num;

}

int main(int argc, char *argv[]) {

    int i;
    i = 9;

    cout << "El valor de i es " << i << endl;
    haz_negativo(i);
    cout << "El valor de i es " << i << endl;

    int j = 22;

    cout << "El valor de j es " << j << endl;
    haz_negativo(j);
    cout << "El valor de j es " << j << endl;


}
