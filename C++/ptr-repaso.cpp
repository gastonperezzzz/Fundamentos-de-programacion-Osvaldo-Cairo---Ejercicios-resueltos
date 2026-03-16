#include <iostream>

using namespace std;

void pasoReferencia(int &);
void pasoRef2(int *);

int main() {
    int *p_numero = nullptr;
    int numero = 10;
    p_numero = &numero;

    cout << "Valor de la variable 'numero': " << numero << endl;
    pasoReferencia(numero);
    cout << "Nuevo valor de 'numero': " << numero << endl;
    pasoRef2(p_numero);
    cout << "Valor de 'numero': " << numero << endl;

    return 0;
}

void pasoReferencia(int &n) {
    n = 50;
}
void pasoRef2(int *n) {
    *n = 100;
}
