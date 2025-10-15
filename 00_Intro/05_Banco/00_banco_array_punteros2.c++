#include <iostream>
#include <sstream>

using namespace std;

class Cuenta {

 private:

 public:
	string titular;
	string numCuenta;
	float saldo;

	void ingresar(float cantidad) {
		saldo += cantidad;
	}

	bool reintegrar(float cantidad){
		if (cantidad > saldo ) return false;
		saldo -= cantidad;
		return true;
	}

};

void mostrar( Cuenta c) {
	cout << "La cuenta de " << c.titular << "con numero de cuenta "<< c.numCuenta<<
		" tiene " << c.saldo << " euros " << endl;

}

void ingresar(Cuenta *c) {
	float cantidad;
	cout << "Introduce la cantidad a ingresar: " ;
	cin >> cantidad;

	(*c).saldo += cantidad;
}

bool retirar(Cuenta *c) {
	float cantidad;
	cout << "Introduce la cantidad a retirar: " ;
	cin >> cantidad;

	return c->reintegrar(cantidad);

}



void inicializarCuentas(Cuenta * cts[10]) {

	string  nombres[5] = {"Marcos", "Marta", "David", "Josep", "Diego"};
	int i=0;
	while (i < 5 ) {
        Cuenta *pcu;
        pcu = new Cuenta;
        cts[i] = pcu;
		stringstream ss;
		ss << 100 + i;
		string numCuenta = ss.str();
		float saldo = (100 * i) + 100;
        cts[i]->saldo = saldo;
        cts[i]->titular = nombres[i];
        cts[i]->numCuenta = numCuenta;

		i++;
	}
}


void mostrarCuentas( Cuenta  *cuentas[10]){

	for (int i=0; i< 10; i++)
        if (cuentas[i] != NULL) cout << cuentas[i]->titular << "\t";
    cout << endl;
    for (int i=0; i< 10; i++)
        if (cuentas[i] != NULL) cout << cuentas[i]->numCuenta << "\t";
    cout << endl;
    for (int i=0; i< 10; i++)
        if (cuentas[i] != NULL) cout << cuentas[i]->saldo << "\t";
    cout << endl;

}

Cuenta *maximo1(Cuenta *cts[]) {

    float saldoMax = 0;
    Cuenta *max = NULL;
    for(int i = 0; i < 10; i++) {
        if ((cts[i] != NULL) && (cts[i]->saldo > saldoMax)) {
            saldoMax = cts[i]->saldo;
            max = cts[i];
        }
    }

    return max;

}

int maximo2(Cuenta *cts[]) {

    int j = 0;
    float saldoMax = 0;
    Cuenta *max = NULL;
    for(int i = 0; i < 10; i++) {
        if ((cts[i] != NULL) && (cts[i]->saldo > saldoMax)) {
            saldoMax = cts[i]->saldo;
            max = cts[i];
            j = i;
        }
    }

    return j;

}

void borrar(Cuenta *cts[], int posicion) {

    if (cts[posicion] != NULL)
        delete cts[posicion];

    cts[posicion] = NULL;


}

void crearCuenta(Cuenta *cts[]) {

    int posicionLibre = -1;
    for (int i = 0; i < sizeof(cts); i++) {
        if (cts[i] == NULL) {
            posicionLibre = i;
            break;
        }
    }
    if (posicionLibre == -1) {
        cout << "No hay espacio libre para crear la Cuenta" << endl;
    } else {

        string nuevoTitular, nuevoNumCuenta;
        float nuevoSaldo;
        Cuenta *nuevaCuenta = new Cuenta();

        cout << "Introduce el titular de la Cuenta: " << endl;
        cin >> nuevoTitular;
        nuevaCuenta->titular = nuevoTitular;

        cout << "Introduce el número de la Cuenta: " << endl;
        cin >> nuevoNumCuenta;
        nuevaCuenta->numCuenta = nuevoNumCuenta;

        cout << "Introduce el saldo de la Cuenta: " << endl;
        cin >> nuevoSaldo;
        nuevaCuenta->saldo = nuevoSaldo;

        cts[posicionLibre] = nuevaCuenta;
        cout << endl;
        cout << "Nueva Cuenta introducida en la posicion " << posicionLibre << endl;
    }


}

int main (int argc, char * argv[]) {

    Cuenta *cuentas[10];
    for (int i = 0; i < 10; i++) {
        cuentas[i] = NULL;
    }

    cout << "Cuentas Incializadas: " << endl;
    inicializarCuentas(cuentas);
    mostrarCuentas(cuentas);

    cout << endl;

    cout << "Ingresar y retirar 1: " << endl;
    ingresar(cuentas[3]);
    retirar(cuentas[4]);
    mostrarCuentas(cuentas);

    cout << endl;

    cout << "Ingresar y retirar 2: " << endl;
    cuentas[3]->ingresar(100);
    cuentas[4]->reintegrar(88);
    mostrarCuentas(cuentas);

    cout << endl;

    cout << "maximo1: " << endl;
    Cuenta *max = maximo1(cuentas);
    max->ingresar(1000);
    mostrarCuentas(cuentas);

    cout << endl;

    cout << "maximo2: " << endl;
    cuentas[maximo2(cuentas)]->ingresar(1000);
    mostrarCuentas(cuentas);

    cout << endl;

    cout << "Borrar: " << endl;
    borrar(cuentas,3);
    mostrarCuentas(cuentas);

    cout << endl;

    cout << "crearCuenta: " << endl;
    crearCuenta(cuentas);
    mostrarCuentas(cuentas);

}
