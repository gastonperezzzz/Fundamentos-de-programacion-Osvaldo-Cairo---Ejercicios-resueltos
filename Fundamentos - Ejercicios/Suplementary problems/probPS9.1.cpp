#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int max_chars = 50;

void cadMayorLongitud(FILE *);

int main() {
    FILE *archivo;
    archivo = fopen("prob9.1.txt", "w+");
    int option = 1, i = 0;
    char cadena[max_chars];

    do {
        printf("[%d] Ingrese una cadena de caracteres para ponerla en el archivo: ", i + 1);
        fgets(cadena, max_chars, stdin);

        fputs(cadena, archivo);

        do {
            printf("Desea ingresar otra cadena? \n0. No \n1. Si \nOpcion: ");
            scanf("%d", &option);
            getchar();
        } while(option != 0 && option != 1);

    } while(option);

    cadMayorLongitud(archivo);
    fclose(archivo);

    return 0;
}

void cadMayorLongitud(FILE *ar) {
    int cont = 0, cadenas = 1;
    char caracter[max_chars];
    int cad_mayor = 0, i_cadmayor = 0, i = 0;

    rewind(ar);

    while(!(feof(ar))) {
        fgets(caracter, max_chars, ar);
        while(caracter[i] != '\0') {
            cont++;
            i++;
        }
    
        if(cad_mayor < cont) {
            cad_mayor = cont;
            i_cadmayor = cadenas;
        }

        i = 0;
        cont = 0;
        cadenas++;
    }
    
    printf("Cadena mas larga %d | Cadena nro. %d\n", cad_mayor, i_cadmayor);
}