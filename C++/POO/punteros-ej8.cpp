#include <iostream>
#include <ctype.h>

using namespace std;

void pedirDatos(char *);
void conteoVocales(char *);

int main() {
    char string[30];

    pedirDatos(string);
    conteoVocales(string);

    return 0;
}

void pedirDatos(char *cadena) {
    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, 50, '\n');
}
void conteoVocales(char *cadena) {
    char vocales[] = "aeiou";
    int cont_vocales[5] = {0};
    while(*cadena) {
        for(int i = 0; i < 5; i++) {
            if(tolower(*cadena) == *(vocales + i)) {
                cont_vocales[i]++;
            }
        }
        cadena++;
    }

    for(int i = 0; i < 5; i++) {
        cout << *(vocales + i) << ": " << *(cont_vocales + i) << endl;
    }
}