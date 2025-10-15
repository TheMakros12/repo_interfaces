#include <iostream>
#include <sstream>
#include <vector>

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



void inicializarCuentas(vector<Cuenta> &cts) {

	string  nombres[5] = {"juan", "perico", "andres", "fulano", "vengano"};
	int i=0;
	while (i < 5 ) {
		Cuenta nueva;
		stringstream ss;
		ss << 100 + i;
		string numCuenta = ss.str();
		float saldo = 100*i + 100;
		nueva.saldo = saldo;
		nueva.titular = nombres[i];
		nueva.numCuenta = numCuenta;

		cts.push_back(nueva);
		i++;
	}
}


void mostrarCuentas(vector<Cuenta> cts){

	for (int i=0; i< cts.size(); i++)
		cout << cts[i].titular << "\t";
	cout << endl;
	for (int i=0; i< cts.size(); i++)
		cout << cts[i].numCuenta << "\t";
	cout << endl;
	for (int i=0; i< cts.size(); i++)
		cout << cts[i].saldo << "\t";
	cout << endl;

}

int main (int argc, char * argv[]) {

	vector<Cuenta> cuentas;
	inicializarCuentas(cuentas) ;

	mostrarCuentas(cuentas);



}







