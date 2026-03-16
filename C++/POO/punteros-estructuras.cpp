#include <iostream>
#include <string>

using namespace std;

const int max_chars = 50;

typedef struct {
    string nombre;
    string apellido;
    int edad;
} Persona;

void pedirDatos(Persona *);
void mostrarDatos(Persona *);

int main() {
    Persona persona1;
    Persona *pPersona;

    pPersona = &persona1;

    pedirDatos(pPersona);
    cout << '\n';
    mostrarDatos(pPersona);

    return 0;
}

void pedirDatos(Persona *var) {
    cout << "Ingrese el nombre: ";
    getline(cin, var->nombre);

    cout << "Ingrese el apellido: ";
    getline(cin, var->apellido);

    cout << "Ingrese la edad: ";
    cin >> var->edad;
}
void mostrarDatos(Persona *var) {
    cout << "Nombre de la persona: " << var->nombre << endl;
    cout << "Apellido de la persona: " << var->apellido << endl;
    cout << "Edad de la persona: " << var->edad << endl;
}