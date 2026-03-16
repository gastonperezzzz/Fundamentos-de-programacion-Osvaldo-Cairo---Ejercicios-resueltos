#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int);
void quitarPila(Nodo *&, int &);

int main() {
    Nodo *pila = nullptr;
    int times;
    int dato;

    cout << "Ingrese la cantidad de numeros que desea ingresar: ";
    cin >> times;

    for(int i = 0; i < times; i++) {
        cout << "Ingrese un numero: ";
        cin >> dato;
        agregarPila(pila, dato);
    }

    // Quitando elementos de la pila.
    cout << "Ahora quitamos los elementos de la pila." << endl;

    for(int i = 0; i < times; i++) {
        quitarPila(pila, dato);
    }

    return 0;
}

void agregarPila(Nodo *&pila, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
    cout << "El numero " << n << " agregado correctamente." << endl;
}
void quitarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
    cout << "El numero " << n << " quitado correctamente." << endl;
}
