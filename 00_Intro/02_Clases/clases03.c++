#include <stdio.h>
#include <iostream>

using namespace std;

class Cuenta {

public:
    string titular;
    string numCuenta;
    float saldo;

    Cuenta(): titular(""), numCuenta(""), saldo(0) {

    }

    Cuenta(string tit, string cuenta, float dinero) {
        titular = tit;
        numCuenta = cuenta;
        saldo = dinero;
    }

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

    Cuenta& operator<< (Cuenta& aux) {
        saldo += aux.saldo;
        aux.saldo = 0;
        return *this;
    }


    Cuenta& operator<< (int num) {
        saldo += num;
        return *this;
    }

    bool operator> (Cuenta& aux) {
        if (saldo > aux.saldo) {
            return true;
        }
        return false;
    }

};

Cuenta& operator<< (int num, Cuenta& aux) {
    aux.saldo -= num;
    return aux;
}

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

    Cuenta c1("Marcos", "001", 1234);
    Cuenta c2("Marta", "002", 5656);

    mostrar(c1);
    mostrar(c2);

    c1<<c2;

    mostrar(c1);
    mostrar(c2);

    100 << c1;
    mostrar(c1);

    c2 << 1000;
    mostrar(c2);

    if (c1 > c2)
        cout << "Marcos tiene más dinero que Marta" << endl;

    return 0;
}
