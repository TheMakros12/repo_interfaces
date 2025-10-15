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
	cout << "Introduce la cantidad a ingresar " ;
	cin >> cantidad;
	
	(*c).saldo += cantidad;
}

bool retirar(Cuenta &c) {
	float cantidad;
	cout << "Introduce la cantidad a ingresar " ;
	cin >> cantidad;

	return c.reintegrar(cantidad);

}



void inicializarCuentas( Cuenta * cts /*Cuenta cts[10]*/) {

	string  nombres[5] = {"juan", "perico","andres", "fulano","vengano"};
	int i=0;
	while (i < 5 ) {
		stringstream ss;
		ss << 100 + i;
		string numCuenta = ss.str();
		float saldo = 100*i + 100;
		cts[i].saldo = saldo;
		cts[i].titular = nombres[i];
		cts[i].numCuenta = numCuenta;

		i++;
	}
}


void mostrarCuentas( Cuenta  cuentas[]){

	for (int i=0; i< 10; i++)
		cout << cuentas[i].titular << "\t";
	cout << endl;
	for (int i=0; i< 10; i++)
		cout << cuentas[i].numCuenta << "\t";
	cout << endl;
	for (int i=0; i< 10; i++)
		cout << cuentas[i].saldo << "\t";
	cout << endl;

}

int main (int argc, char * argv[]) {

	/* JAVA
	Cuenta cuentas[] ;
	cuentas = new Cuenta[10];
	*/

	Cuenta cuentas[10];

	/*
	cuentas[0]
	cuentas[0].ingresar(100)
	float saldo = cuentas[4].saldo;
	*/

	inicializarCuentas(cuentas) ;

	mostrarCuentas(cuentas);

	ingresar( &(cuentas[3]) );

	retirar(cuentas[4]);
	mostrarCuentas(cuentas);
}







