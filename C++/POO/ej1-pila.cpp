#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void agregarPila(Nodo *&, int);
void quitarPila(Nodo *&, int &);

int main() {
    Nodo *pila = nullptr;
    int dato;

    while(1) {
        cout << "Ingrese un numero: ";
        cin >> dato;
        if(dato == 0) {
            break;
        }
        agregarPila(pila, dato);
    }

    while(pila != nullptr) {
        quitarPila(pila, dato);
        cout << "El numero " << dato << " se ha quitado correctamente de la pila." << endl;
    }

    return 0;
}

void agregarPila(Nodo *&pila, int n) {
    Nodo *new_node = new Nodo();
    new_node->dato = n;
    new_node->siguiente = pila;
    pila = new_node;
}
void quitarPila(Nodo *&pila, int &n) {
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}
