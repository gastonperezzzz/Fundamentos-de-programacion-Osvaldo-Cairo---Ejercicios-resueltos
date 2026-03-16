#include <iostream>
#include <string>

class Punto {
    private:
        int x, y;
    public:
        void setPuntoX(int);
        void setPuntoY(int);
        int getPuntoX();
        int getPuntoY();
};

void Punto::setPuntoX(int _x) {
    x = _x;
}
void Punto::setPuntoY(int _y) {
    y = _y;
}
int Punto::getPuntoX() {
    return x;
}
int Punto::getPuntoY() {
    return y;
}

int main() {
    Punto p1;

    p1.setPuntoX(5);
    p1.setPuntoY(2);

    std::cout << "x: " << p1.getPuntoX() << std::endl;
    std::cout << "y: " << p1.getPuntoY() << std::endl;

    return 0;
}