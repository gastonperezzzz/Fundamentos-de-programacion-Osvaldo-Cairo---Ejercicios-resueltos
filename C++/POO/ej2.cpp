// Ejercicio 2: Construya una clase Tiempo que contenga los siguientes atributos enteros: horas, minutos y segundos. 
// Haga que la clase contenga 2 constructores, el primero debe tener 3 parámetros Tiempo(int,int,int) y el segundo 
// sólo tendrá un campo que serán los segundos y desensamble el número entero largo 
// en horas, minutos y segundos.

#include <iostream>
#include <string>

class Tiempo {
    private:
        int horas;
        int minutos;
        int segundos;
    public:
        Tiempo(int, int, int); // Constructor 1
        Tiempo(long); // Constructor 2
        void mostrarTiempo();
};

Tiempo::Tiempo(int _horas, int _minutos, int _segundos) {
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
}
Tiempo::Tiempo(long _segundos) {
    horas = _segundos / 3600;
    _segundos %= 3600;
    minutos = _segundos / 60;
    _segundos %= 24;
    segundos = _segundos / 60;
}
void Tiempo::mostrarTiempo() {
    std::cout << "Tiempo: " << horas << ":" << minutos << ":" << segundos << std::endl;
}

int main() {
    Tiempo t1(1440);

    t1.mostrarTiempo();

    return 0;
}