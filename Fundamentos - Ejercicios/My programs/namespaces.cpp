#include <iostream>
#include <string>
#include <limits>

int main() {
    char cadena[41];
    float real;
    int entero;

    std::cout << "Ingrese un numero entero: ";
    std::cin >> entero;

    std::cout << "Ingrese un numero real: ";
    std::cin >> real;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Ahora ingrese una cadena: ";
    std::cin.getline(cadena, sizeof(cadena));

    std::cout << "Entero ingresado --> " << entero << std::endl;
    std::cout << "Real ingresado --> " << real << std::endl;
    std::cout << "Cadena ingresada --> " << cadena << std::endl;

    return 0;
}