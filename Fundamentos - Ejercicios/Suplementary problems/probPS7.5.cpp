#include <stdio.h>
#include <ctype.h>

int main() {
    char cadena[50];
    int i = 0;

    printf("Ingrese una cadena de caracteres: ");
    fgets(cadena, sizeof(cadena), stdin);

    if(isalpha(cadena[0]) && islower(cadena[0])) {
        cadena[0] = toupper(cadena[0]);
    }

    while(cadena[i] != '\0') {
        if(cadena[i] == ',') {
            if(cadena[i + 1] == ' ' && islower(cadena[i + 2])) {
                cadena[i + 2] = toupper(cadena[i + 2]);
            }
            else if(islower(cadena[i + 1])) {
                cadena[i + 1] = toupper(cadena[i + 1]);
            }
        }
        else if(cadena[i] == ' ' && islower(cadena[i + 1])) {
            cadena[i + 1] = toupper(cadena[i + 1]);
        }
        i++;
    }

    puts(cadena);

    return 0;
}