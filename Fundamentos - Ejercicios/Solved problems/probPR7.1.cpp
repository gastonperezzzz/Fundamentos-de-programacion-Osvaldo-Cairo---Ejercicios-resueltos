#include <stdio.h>

#define F 20

int main() {
    char cad[F];
    char ch;
    int contador_ch = 0, i = 0;;

    printf("Cadena: ");
    fgets(cad, sizeof(cad), stdin);

    printf("Ahora ingrese un caracter: ");
    ch = getchar();

    while(cad[i] != '\0') {
        if(cad[i] == ch) {
            contador_ch++;
        }
        i++;
    }
    printf("'%c' se repite %d veces en la cadena.\n", ch, contador_ch);

    return 0;
}