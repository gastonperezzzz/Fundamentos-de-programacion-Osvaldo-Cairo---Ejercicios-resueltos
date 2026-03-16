#include <iostream>
#include <stdlib.h>

int n_calif;
int *calificaciones;

void pedirNotas(void);
void mostrarNotas(void);

using namespace std;

int main() {
    pedirNotas();
    cout << "\n";
    mostrarNotas();

    delete[] calificaciones;

    return 0;
}

void pedirNotas(void) {
    cout << "Ingrese la cantidad de notas: ";
    cin >> n_calif;

    calificaciones = new int[n_calif];

    for(int i = 0; i < n_calif; i++) {
        cout << "Ingrese la nota [" << i + 1 << "]: ";
        cin >> calificaciones[i];
    }
}
void mostrarNotas(void) {
    for(int i = 0; i < n_calif; i++) {
        cout << "Nota [" << i + 1 << "]: " << calificaciones[i] << endl; 
    }
}