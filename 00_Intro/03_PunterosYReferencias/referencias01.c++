#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int i;
    i = 9;

    int &r = i;

    cout << "El valor de i es " << i << endl;
    r  =  20;
    cout << "El valor de i es " << i << endl;

}
