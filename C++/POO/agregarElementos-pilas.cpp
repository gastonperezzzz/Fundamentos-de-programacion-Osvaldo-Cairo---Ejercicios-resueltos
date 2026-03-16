#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *next;
};

void agregarPila(Nodo *&, int);

int main() {
    Nodo *pila = NULL;
    int num_1, num_2;

    cout << "Ingrese un numero para agregar a la pila: ";
    cin >> num_1;

    agregarPila(pila, num_1);

    cout << "Ingrese otro numero para agregar a la pila: ";
    cin >> num_2;

    agregarPila(pila, num_2);

    return 0;
}

void agregarPila(Nodo *&pila, int n) {
    Nodo *new_Nodo = new Nodo();
    new_Nodo->dato = n;
    new_Nodo->next = pila;
    pila = new_Nodo;
    cout << "Valor de la direccion de memoria de pila ahora " << pila << endl;
}
