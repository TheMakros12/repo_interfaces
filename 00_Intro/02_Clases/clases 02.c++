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

    cout << "El titular de la cuenta es " << cuenta.titular << " con el número de ceunta " << cuenta.numCuenta  << " y un saldo de " << cuenta.saldo << "€" << endl;

}

void operacionIngreso(Cuenta *cu) {

    float cantidadAIngresar;
    cout << "Cuanto dinero quieres ingresar?" << endl;
    cin >> cantidadAIngresar;
    cu->ingresar(cantidadAIngresar);

}

int main(int argc, char *argv[]) {

    Cuenta c1, c2;

    c1.titular = "Marcos" ; c1.saldo = 1234.0; c1.numCuenta = 001;
    c1.titular = "Marta" ; c1.saldo = 1234.0; c1.numCuenta = 002;

    mostrar(c1);
    mostrar(c2);

    return 0;
}
