#include <iostream>

using namespace std;

int main() {
    int numeros[10];
    int *p_numeros;

    for(int i = 0; i < 10; i++) {
        cout << "Posicion [" << i << "]: "; cin >> numeros[i];
    }

    p_numeros = numeros;

    for(int i = 0; i < 10; i++) {
        if(*p_numeros % 2 == 0) {
            cout << *p_numeros << " es par." << endl;
            cout << "Posicion de memoria: " << p_numeros << endl;
        }
        p_numeros++;
    }


    return 0;
}