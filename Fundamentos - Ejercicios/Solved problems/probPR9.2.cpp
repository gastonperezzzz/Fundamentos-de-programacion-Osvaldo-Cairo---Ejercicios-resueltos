#include <stdio.h>

const int max_chars = 50;

int main() {
    FILE *archivo;
    char cadena[max_chars], cad_aux[max_chars];
    char caracter;
    int contador = 0;

    if((archivo = fopen("arch.txt", "w")) == NULL) {
        printf("Error: no se ha podido abrir el archivo.\n");
    }
    else {
        printf("Ingrese una cadena de caracteres para insertar en el archivo: ");
        fgets(cadena, max_chars, stdin);
        fputs(cadena, archivo);
        fclose(archivo);
    }

    printf("Ingrese un caracter para determinar cuantas veces se repite: ");
    caracter = getchar();

    archivo = fopen("arch.txt", "r");

    fgets(cad_aux, max_chars, archivo);
    for(int i = 0; i < max_chars; i++) {
        if(cad_aux[i] == caracter) {
            contador++;
        }
    }
    printf("El caracter %c se repite %d veces en la cadena.\n", caracter, contador);

    return 0;
}