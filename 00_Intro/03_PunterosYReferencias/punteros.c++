#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {

    int i;
    i = 9;

    int *p;
    p = &i;

    cout << "La variable i esta en " << &i << endl;
    cout <<  "La variable p apunta a " << p << endl;
    cout << "La variable p esta en " << &p << endl;
    cout << "La variable i vale " << i << endl;

    cout << "Ahora hago *p = 10:" << endl;
    *p = 10;

    cout << "El valor de i es " << *p << endl;
    cout << "El valor de i es " << i << endl;

    return 0;
}
