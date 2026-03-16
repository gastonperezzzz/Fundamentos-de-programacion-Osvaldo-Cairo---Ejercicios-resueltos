#include <iostream>
#include <string>

class Rectangulo {
    private:
        float largo;
        float ancho;
    public:
        Rectangulo(float, float);
        void perimetro();
        void area();
};

Rectangulo::Rectangulo(float _large, float _wide) {
    largo = _large;
    ancho = _wide;
}
void Rectangulo::perimetro() {
    std::cout << "El perimetro del rectangulo es: " << largo * 2 + ancho * 2 << std::endl;
}
void Rectangulo::area() {
    std::cout << "El area del rectangulo es: " << largo * ancho << std::endl;
}

int main() {
    Rectangulo r1(4, 2);

    r1.area();
    r1.perimetro();

    return 0;
}