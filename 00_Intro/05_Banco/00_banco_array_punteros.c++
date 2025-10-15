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



void inicializarCuentas( /**/) {

	string  nombres[5] = {"juan", "perico","andres", "fulano","vengano"};
	int i=0;
	while (i < 5 ) {
		Cuenta * pcu;
		stringstream ss;
		ss << 100 + i;
		string numCuenta = ss.str();
		float saldo = 100*i + 100;
		/* cuentas[i].titular = nombres[i];*/
		cuentas[i] = pcu; // i hasta 4

		i++;
	}
}


void mostrarCuentas( Cuenta  cuentas[]){

	for (int i=0; i< 10; i++)

	cout << endl;
	for (int i=0; i< 10; i++)
		
	cout << endl;
	for (int i=0; i< 10; i++)
		
	cout << endl;

}

int main (int argc, char * argv[]) {

	/* JAVA
	Cuenta cuentas[] ;
	cuentas = new Cuenta[10];
	*/

	Cuenta * cuentas[10];

	for (int i = 0; i < 10; i++ )


	/*
	Cuenta cu;
	Cuentas pcu;

	pcu = new Cuenta;
	(*pcu).ingresar(100);
	float cantidad = pcu->saldo;
	*/

	inicializarCuentas



	mostrarCuentas();
	cuentas[2]->ingresar(100);
	cuentas[4]->reintegrar(88);

	cout << "el titular de la segunda cuenta es "<< cuentas[1]->titular;


	/*
	 * Cuenta *pcu;
	 * pcu = NULL;
	 *
	 * if (pcu != NULL)
	 *
	 *
	 *
	 * */


	Cuenta *max = maximo1(cuentas);
		max->ingresar(1000);

	cuentas[maximo2(cuentas)]->ingresar(1000)

	borrar(cuentas,3);
	mostrarCuentas())
	borrar(cuentas,5);

	/* cómo borrar
		Cuenta *pcu;
		pcu = new Cuenta;
		...

		delete pcu;
	 */

	mostrarCuentas()
	crearCuenta(cuentas) // cin >> tit; pcu->titular = tit;

	mostrarCuentas2(cuentas);





}







