#include <iostream>
#include <string>

class Persona {
    private:
        std::string nombre;
        int edad;
    public:
        void setNombre(std::string);
        void setEdad(int);
        std::string getNombre();
        int getEdad();
        void mostrarPersona();
};

class Alumno: public Persona {
    private:
        std::string codAlumno;
        float notaFinal;
    public:
        void setCodAlumno(std::string);
        void setNotaFinal(float);
        std::string getCodAlumno();
        float getNotaFinal();
        void mostrarAlumno();
};

// Clase persona (clase padre o super clase)
void Persona::setNombre(std::string _nombre) {
    nombre = _nombre;
}
void Persona::setEdad(int _edad) {
    edad = _edad;
}
std::string Persona::getNombre() {
    return nombre;
}
int Persona::getEdad() {
    return edad;
}
void Persona::mostrarPersona() {
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Edad: " << edad << std::endl;
}

// Clase alumno (clase hija)
void Alumno::setCodAlumno(std::string _codAlumno) {
    codAlumno = _codAlumno;
}
void Alumno::setNotaFinal(float _notaFinal) {
    notaFinal = _notaFinal;
}
std::string Alumno::getCodAlumno() {
    return codAlumno;
}
float Alumno::getNotaFinal() {
    return notaFinal;
}
void Alumno::mostrarAlumno() {
    mostrarPersona();
    std::cout << "Codigo de alumno: " << codAlumno << std::endl;
    std::cout << "Nota final: " << notaFinal << std::endl;
}


int main() {
    Alumno a1;
    Persona p1;

    a1.setNombre("Gaston");
    a1.setEdad(19);
    a1.setCodAlumno("1267");
    a1.setNotaFinal(8.50);
    a1.mostrarAlumno();

    p1.setNombre("Ezequiel");
    p1.setEdad(12);
    p1.mostrarPersona();

    // std::cout << "Edad de " << p1.getNombre() << ": " << p1.getEdad() << std::endl; 

    return 0;
}