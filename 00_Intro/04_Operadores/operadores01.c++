#include <iostream>
#include <stdio.h>

using namespace std;

class Complejo{

public:
    float real;
    float imaginario;

    void mostrar() {
        cout << "("<< real << " + " << imaginario << "i)" <<  endl;
    }

};

Complejo operator+ (Complejo num1, Complejo num2) {

    Complejo aux;

    aux.real = num1.real + num2.real;
    aux.imaginario = num1.imaginario + num2.imaginario;

    return aux;

}

Complejo operator- (Complejo  num){

    num.real = -num.real;
    num.imaginario = -num.imaginario;

    return num;

}

Complejo operator- (Complejo num1, Complejo num2) {

    return num1 + (-num2);

    /*Complejo aux;

    aux.real = num1.real - num2.real;
    aux.imaginario = num1.imaginario - num2.imaginario;

    return aux;*/

}

int main(int argc, char *argv[]) {

    cout << endl;

    Complejo c;
    c.real = 2;
    c.imaginario = 4;
    c.mostrar();

    Complejo s;
    s.real = 8;
    s.imaginario = -5;
    s.mostrar();

    cout << endl;

    //Suma de Complejos
    Complejo resultado;
    resultado = c + s;
    cout << "SUMA" << endl;
    resultado.mostrar();

    cout << endl;

    //Resta de Complejos
    Complejo resultadoResta;
    resultadoResta = c - s;
    cout << "RESTA" << endl;
    resultadoResta.mostrar();

    cout << endl;

    //Inversión de Complejo
    Complejo invertido = - s;
    cout << "INVERTIDO" << endl;
    invertido.mostrar();

    cout << endl;

    return 0;
}
