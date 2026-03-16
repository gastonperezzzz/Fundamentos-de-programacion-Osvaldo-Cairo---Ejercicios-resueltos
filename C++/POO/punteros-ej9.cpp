#include <iostream>
#include <stdlib.h>

using namespace std;

int **pMatriz;
int nFilas, nCol;

void pedirDatos();
void matrizTranspuesta(int **, int, int);

int main() {
    pedirDatos();
    matrizTranspuesta(pMatriz, nFilas, nCol);

    return 0;
}

void pedirDatos() {
    cout << "Ingrese el numero de filas: ";
    cin >> nFilas;

    cout << "Ingrese el numero de columnas: ";
    cin >> nCol;

    pMatriz = new int*[nFilas];
    for(int i = 0; i < nFilas; i++) {
        pMatriz[i] = new int[nCol];
    }

    for(int i = 0; i < nFilas; i++) {
        for(int j = 0; j < nCol; j++) {
            cout << "Ingrese un valor para la posicion [" << i << "][" << j << "]: ";
            cin >> *(*(pMatriz + i) + j); 
        }
    }
}
void matrizTranspuesta(int **pMat, int f, int c) {
    cout << "\nMatriz transpuesta: \n";
    for(int i = 0; i < f; i++) {
        for(int j = 0; j < c; j++) {
            cout << *(*(pMat + j) + i);
        }
        cout << '\n';
    }
}