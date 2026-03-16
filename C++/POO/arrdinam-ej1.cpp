#include <iostream>
#include <stdlib.h>

using namespace std;

int n_elementos;
int *elementos;

void pedirArray(void);
void ordenarArray(int *);
void mostrarArray();

int main() {
    pedirArray();
    cout << "Array antes de ordenar..." << endl;
    mostrarArray();
    ordenarArray(elementos);
    cout << "Array despues de ordenar..." << endl;
    mostrarArray();

    delete[] elementos;

    return 0;
}

void pedirArray(void) {
    cout << "Ingrese la cantidad de elementos del array: ";
    cin >> n_elementos;

    elementos = new int[n_elementos];

    for(int i = 0; i < n_elementos; i++) {
        cout << "Ingrese el elemento [" << i + 1 << "]: ";
        cin >> *(elementos + i);
    }
}
void ordenarArray(int *arr) {
    int i, j, aux;
    for(i = 0; i < n_elementos; i++) {
        for(j = 0; j < n_elementos; j++) {
            if(arr[i] < arr[j]) {
                aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}
void mostrarArray(void) {
    for(int i = 0; i < n_elementos; i++) {
        cout << "Elemento [" << i + 1 << "]: " << elementos[i] << endl;
    }
}