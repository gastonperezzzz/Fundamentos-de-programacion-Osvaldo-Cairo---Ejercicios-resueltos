#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void agregarCola(Nodo *&, int);
// void quitarCola(Nodo *&);

int main() {
    Nodo *fifo = NULL;
    int num;

    for(int i = 0; i < 3; i++) {
        cout << "[" << i + 1 << "] Ingrese un numero para agregar a la cola: ";
        cin >> num;
        agregarCola(fifo, num);
    }



    return 0;
}

void agregarCola(Nodo *&cola, int n) {
    Nodo *new_node = new Nodo();
    new_node->dato = n;
    cola = new_node;

    cout << "El numero " << new_node->dato << " ha sido agregado a la cola." << endl;
}
void quitarCola(Nodo *&cola) {

}
