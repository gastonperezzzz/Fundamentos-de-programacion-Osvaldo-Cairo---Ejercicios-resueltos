#include <iostream>
#include <string>

using namespace std;

int main() {
    string cadena = "Prueba uno...\n";
    string *p_cad;

    p_cad = &cadena;

    cout << *p_cad;
    cout << p_cad << endl;

    return 0;
}