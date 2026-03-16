#include <iostream>
#include <string>

// CLASES

// Clase padre
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

// Subclase - Empleado de Persona
class Empleado: public Persona {
    private:
        std::string codEmpleado;
        float sueldo;
    public:
        void setCodEmpleado(std::string);
        void setSueldo(float);
        std::string getCodEmpleado();
        float getSueldo();
        void mostrarEmpleado();
};

// Subclase - Estudiante de Persona
class Estudiante: public Persona {
    private:
        std::string codAlumno;
        int matricula;
    public:
        void setCodAlumno(std::string);
        void setMatricula(int);
        std::string getCodAlumno();
        int getMatricula();
        void mostrarAlumno();
};

// Subclase - Universitario de Estudiante
class Universitario: public Estudiante {
    private:
        std::string carrera;
        float promedio;
    public:
        void setCarrera(std::string);
        void setPromedio(float);
        std::string getCarrera();
        float getPromedio();
        void mostrarUniversitario();
};

// Definicion de metodos - Persona

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

// Definicion de metodos - Empleado

void Empleado::setCodEmpleado(std::string _codEmpleado) {
    codEmpleado = _codEmpleado;
}
void Empleado::setSueldo(float _sueldo) {
    sueldo = _sueldo;
}
std::string Empleado::getCodEmpleado() {
    return codEmpleado;
}
float Empleado::getSueldo() {
    return sueldo;
}
void Empleado::mostrarEmpleado() {
    mostrarPersona();
    std::cout << "Codigo de empleado: " << codEmpleado << std::endl;
    std::cout << "Sueldo: " << sueldo << std::endl;
}

// Definicion de metodos - Estudiante

void Estudiante::setCodAlumno(std::string _codAlumno) {
    codAlumno = _codAlumno;
}
void Estudiante::setMatricula(int _mat) {
    matricula = _mat;
}
std::string Estudiante::getCodAlumno() {
    return codAlumno;
}
int Estudiante::getMatricula() {
    return matricula;
}
void Estudiante::mostrarAlumno() {
    mostrarPersona();
    std::cout << "Codigo de alumno: " << codAlumno << std::endl;
    std::cout << "Matricula: " << matricula << std::endl;
}

// Definicion de metodos - Universitario

void Universitario::setCarrera(std::string _carrera) {
    carrera = _carrera;
}
void Universitario::setPromedio(float _prom) {
    promedio = _prom;
}
std::string Universitario::getCarrera() {
    return carrera;
}
float Universitario::getPromedio() {
    return promedio;
}
void Universitario::mostrarUniversitario() {
    mostrarAlumno();
    std::cout << "Carrera: " << carrera << std::endl;
    std::cout << "Promedio: " << promedio << std::endl;
}

// Programa principal.
int main() {
    Universitario univ1;

    univ1.setNombre("Manuel");
    univ1.setEdad(34);
    univ1.setCodAlumno("106933923");
    univ1.setMatricula(1069);
    univ1.setCarrera("Lic. En Sistemas");
    univ1.setPromedio(9.91230);
    univ1.mostrarUniversitario();

    return 0;
}