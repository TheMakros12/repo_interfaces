#include <iostream>
#include <stdio.h>

using namespace std;

class Complejo{

public:
    float real;
    float imaginario;

    Complejo(): real(0), imaginario(0) {

    }

    Complejo(float r, float i): real(r), imaginario(i){
    }

    void mostrar() {
        cout << "("<< real << " + " << imaginario << "i)" <<  endl;
    }

    Complejo operator+ (Complejo otro) {
        Complejo aux;
        aux.real = real + otro.real;
        aux.imaginario = imaginario + otro.imaginario;
        return aux;
    }

    Complejo operator+ (float num) {
        Complejo aux;
        aux.real = real + num;
        aux.imaginario = imaginario;
        return aux;
    }

    Complejo operator- (float num) {
        return *this + (-num);
    }

    Complejo operator- (Complejo otro) {
        Complejo aux;
        aux.real = real - otro.real;
        aux.imaginario = imaginario - otro.imaginario;
        return aux;
    }

    Complejo operator- (){

        Complejo aux;
        aux.real = -real;
        aux.imaginario = -imaginario;

        return aux;

    }

};

int main(int argc, char *argv[]) {

    cout << endl;
    cout << "COMPLEJOS" << endl;

    Complejo c;
    c.real = 2;
    c.imaginario = 4;
    c.mostrar();

    Complejo s(8, -5);
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

    //Suma2 de Complejos
    Complejo suma2;
    suma2 = s + 8 - 5;
    cout << "OPERACIONES con INT" << endl;
    suma2.mostrar();

    cout << endl;

    //Inversión de Complejo
    Complejo invertido = - s;
    cout << "INVERTIDO" << endl;
    invertido.mostrar();

    cout << endl;

    return 0;
}
