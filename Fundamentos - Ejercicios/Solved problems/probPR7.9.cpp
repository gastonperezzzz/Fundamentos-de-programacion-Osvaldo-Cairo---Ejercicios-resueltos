#include <stdio.h>
#include <string.h>

int wordCounter(char *);

int main() {
    char cad[50];

    printf("Ingrese una cadena de caracteres para contar sus palabras: ");
    fgets(cad, sizeof(cad), stdin);

    printf("La cadena ingresada tiene %d palabras.\n", wordCounter(cad));

    return 0;
}

int wordCounter(char *string) {
    int i = 0, counter = 0;
    while(string[i] != '\0') {
        if(string[i] == ' ' && string[i + 1] != ' ') {
            counter++;
        }
        i++;
    }
    return (counter + 1);
}