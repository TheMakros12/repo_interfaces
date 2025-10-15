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

    Cuenta c;

    c.titular = "Marcos";
    c.numCuenta = "1234";
    c.saldo = 1234.56;

    mostrar(c);

    c.ingresar(1000);

    mostrar(c);

    if (c.reintegrar(500)) {
        cout << "Has podido sacar 500 eurillos."  << endl;
    } else {
        cout << "Eres un muerto de hambre y no tienes pasta."  << endl;
    }

    mostrar(c);

    operacionIngreso(&c);

    mostrar(c);

    return 0;
}
