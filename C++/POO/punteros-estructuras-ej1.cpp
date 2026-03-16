#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string nombre;
    int edad;
    float promedio;
} Alumno;

void pedirDatos(Alumno *);
float alumnoPromedio(Alumno *);
void mostrarDatos(Alumno *);

int main() {
    Alumno alumnos[3];
    int i;
    float mayor_promedio = 0.0;

    for(i = 0; i < 3; i++) {
        pedirDatos(&alumnos[i]);
        if(mayor_promedio < alumnoPromedio(&alumnos[i])) {
            mayor_promedio = alumnoPromedio(&alumnos[i]);
        }
    }
    cout << "El mejor promedio es: " << mayor_promedio << endl;
    for(i = 0; i < 3; i++) {
        mostrarDatos(&alumnos[i]);
    }

    return 0;
}

void pedirDatos(Alumno *var) {
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, var->nombre);

    cout << "Ingrese la edad del alumno: ";
    cin >> var->edad;

    cout << "Ingrese el promedio del alumno: ";
    cin >> var->promedio;

    cin.ignore();
}
float alumnoPromedio(Alumno *var) {
    return var->promedio;
}
void mostrarDatos(Alumno *var) {
    cout << "Nombre: " << var->nombre << endl;
    cout << "Edad: " << var->edad << endl;
    cout << "Promedio: " << var->promedio << endl;
}