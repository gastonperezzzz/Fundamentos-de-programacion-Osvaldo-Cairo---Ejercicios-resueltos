#include <stdio.h>
#include <ctype.h>

void contMinusMayus(FILE *);

int main() {
    FILE *archive;
    
    if((archive = fopen("arc5.txt", "r")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        contMinusMayus(archive);
        fclose(archive);
    }
}

void contMinusMayus(FILE *ar) {
    char caracter;
    int minusculas = 0, mayusculas = 0;

    while(!feof(ar)) {
        caracter = fgetc(ar);
        if(isupper(caracter)) {
            mayusculas++;
        }
        else if(islower(caracter)) {
            minusculas++;
        }
    }
    printf("Mayusculas: %d | Minusculas: %d\n", mayusculas, minusculas);
}