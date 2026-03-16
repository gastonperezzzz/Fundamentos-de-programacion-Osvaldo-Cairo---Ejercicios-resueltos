#include <iostream>
#include <string>

class Persona {
    // Atributos.
    private:
        std::string nombre;
        int edad;
        float altura;
    // Metodos.
    public:
        Persona(std::string, int, float);
        void leer();
        void correr();
        void reir();
};

Persona::Persona(std::string _nombre, int _edad, float _altura) {
    nombre = _nombre;
    edad = _edad;
    altura = _altura;
}
void Persona::leer() {
    std::cout << "Soy " << nombre << " y estoy leyendo un libro muy interesante." << std::endl;
}
void Persona::correr() {
    std::cout << nombre << ", de " << edad << " de edad, que mide " << altura << " esta corriendo una maraton." << std::endl;
}
void Persona::reir() {
    std::cout << nombre << ", de " << edad << " de edad, no para de reir." << std::endl;
}

int main() {
    std::string name;
    int years;
    float heigh;
    
    Persona p1 = Persona("Gaston", 19, 1.70);

    std::cout << "Ingrese un nombre para su personaje: ";
    std::getline(std::cin, name);

    std::cout << "Ingrese la edad de su personaje: ";
    std::cin >> years;

    std::cout << "Ingrese la altura de su personaje: ";
    std::cin >> heigh;

    Persona p2(name, years, heigh);

    p1.correr();
    p1.leer();
    p1.reir();

    p2.correr();
    p2.leer();
    p2.reir();


    return 0;
}