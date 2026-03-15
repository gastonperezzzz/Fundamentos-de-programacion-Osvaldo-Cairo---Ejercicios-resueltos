#include <stdio.h>
#include <string.h>

int main() {
    char cad1[50], cad2[50], *cad0 = "";
    int i = 0;

    printf("Ingrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin);
    if(cad1[strlen(cad1) - 1] == '\n') {
        cad1[strlen(cad1) - 1] = '\0';
    }

    printf("Ingrese la cadena a buscar: ");
    fgets(cad2, sizeof(cad2), stdin);
    if(cad2[strlen(cad2) - 1] == '\n') {
        cad2[strlen(cad2) - 1] = '\0';
    }

    strcpy(cad0, cad1);

    cad0 = strstr(cad0, cad2);
    while(cad0 != NULL) {
        i++;
        cad0 = strstr(cad0 + 1, cad2);
    }
    printf("El numero de veces que aparece la primera cadena es: %d", i);

    return 0;
}