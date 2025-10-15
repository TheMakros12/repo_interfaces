#include <stdio.h>
#include <iostream>

using namespace std;

class Cuenta {

public:
    string titular;
    string numCuenta;
    float saldo;

void ingresar(int ingreso) {
    saldo = saldo + ingreso;
}

bool reintegrar(float reintegro) {

    if (reintegro > saldo) {
        return false;
    }

    saldo = saldo - reintegro;
    return true;

}

};

void mostrar(Cuenta cuenta) {

    cout << "Titular de la cuenta: " << cuenta.titular << endl;
    cout <<"Número de cuenta: " << cuenta.numCuenta << endl;
    cout << "Saldo: " << cuenta.saldo << "€" << endl;
    cout << endl;

}

void operacionIngreso(Cuenta *cu) {

    float cantidadAIngresar;
    cout << "Cuanto dinero quieres ingresar?" << endl;
    cin >> cantidadAIngresar;
    cu->ingresar(cantidadAIngresar);

}

int main(int argc, char *argv[]) {

    Cuenta c1, c2;

    c1.titular = "Marcos" ; c1.numCuenta = "001"; c1.saldo = 123456.0;
    c2.titular = "Marta" ; c2.numCuenta = "002"; c2.saldo = 123.0;

    mostrar(c1);
    mostrar(c2);

    c2 = c1;

    cout << "c2 = c1 y el resultado es..." << endl;

    mostrar(c1);
    mostrar(c2);

    c2.ingresar(1000);

    cout << "c2.ingresar(1000)" << endl;

    mostrar(c1);
    mostrar(c2);


    return 0;
}
