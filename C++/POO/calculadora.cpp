#include <math.h>
#include <iostream>
#include <string>

using namespace std;

class Calculadora {
    private:
        double operando1;
        double operando2;
        double resultado;
    public:
    void setOp1();
    void setOp2();
    void setResultado(int);
    double getOp1();
    double getOp2();
    double getResultado();
    double sumar();
    double restar();
    double producto();
    double dividir();
};

// Definicion de metodos.

void Calculadora::setOp1() {
    cout << "Ingrese el primer operando: ";
    cin >> operando1;
}
void Calculadora::setOp2() {
    cout << "Ingrese el segundo operando: ";
    cin >> operando2;
}
void Calculadora::setResultado(int option) {
    switch(option) {
        case 1:
            resultado = sumar();
            break;
        case 2:
            resultado = restar();
            break;
        case 3:
            resultado = producto();
            break;
        case 4:
            resultado = dividir();
            break;
    }
}
double Calculadora::getOp1() {
    return operando1;
}
double Calculadora::getOp2() {
    return operando2;
}
double Calculadora::getResultado() {
    return resultado;
}
double Calculadora::sumar() {
    return (operando1 + operando2);
}
double Calculadora::restar() {
    return (operando1 - operando2);
}
double Calculadora::producto() {
    return (operando1 * operando2);
}
double Calculadora::dividir() {
    return (operando1 / operando2);
}

int main() {
    Calculadora calculo;
    int option;

    do {
        calculo.setOp1();
        calculo.setOp2();
        do {
            cout << "Ingrese la operacion a realizar: " << endl;
            cout << "1. Sumar \n2. Restar \n3. Multiplicar \n4. Dividir \n5. Salir" << endl;
            cout << "Opcion: ";
            cin >> option;
        } while(option < 1 || option > 4);
        calculo.setResultado(option);
        cout << "El resulado entre " << calculo.getOp1() << " y " << calculo.getOp2() << " es: " << calculo.getResultado() << endl;
    } while(option != 5);

    return 0;
}