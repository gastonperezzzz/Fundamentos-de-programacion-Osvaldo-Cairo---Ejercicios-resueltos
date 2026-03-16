#include <iostream>

using namespace std;

int main() {
    int num;
    int *p_num;

    cout << "Ingrese un numero: ";
    cin >> num;

    p_num = &num;

    if(*p_num % 2 == 0) {
        cout << "El numero " << *p_num << " es par." << endl;
    }
    else {
        cout << "El numero " << *p_num << " es impar." << endl;
    }

    cout << "Direccion donde se almacena dicho numero: " << p_num << endl;

    return 0;
}