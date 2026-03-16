#include <iostream>
#include <string>

using namespace std;

int main() {
    string nombre;
    string *pNombre, *pNombreII;
    string nombre_II = "El diablex";

    pNombre = &nombre;

    cout << "Ingrese su nombre: ";
    getline(cin, nombre);

    cout << "Su nombre es: " << *pNombre << endl;

    pNombre = &nombre_II;
    pNombreII = pNombre;

    cout << "pNombreII es: " << *pNombreII << endl;

    return 0;
}