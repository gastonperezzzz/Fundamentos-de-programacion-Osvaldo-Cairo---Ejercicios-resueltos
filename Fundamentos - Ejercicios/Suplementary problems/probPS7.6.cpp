#include <stdio.h>
#include <string.h>

const int max_strings = 20;
const int max_chars = 20;

int main() {
    char option;
    char cadena[max_strings][max_chars];
    int i = 0, long_string = 0, mayorstring = 0, i_mayor = 0;

    do {
        printf("Desea ingresar una cadena de caracteres? [S/N]: ");
        scanf("%c", &option);
        getchar();
    } while(option != 'S' && option != 's' && option != 'N' && option != 'n');

    while(option == 'S' || option == 's') {
        printf("Ingrese una cadena de caracteres [%d]: ", i + 1);
        fgets(cadena[i], sizeof(cadena[i]), stdin);

        long_string = strlen(cadena[i]);

        if(long_string > mayorstring) {
            mayorstring = long_string;
            i_mayor = i;
        }

        i++;

        do {
            printf("Desea ingresar otra cadena de caracteres? [S/N]: ");
            scanf("%c", &option);
            getchar();
        } while(option != 'S' && option != 's' && option != 'N' && option != 'n');
    }

    printf("La cadena de mayor longitud es la numero: %d\n", i_mayor + 1);
    puts(cadena[i_mayor]);

    return 0;
}