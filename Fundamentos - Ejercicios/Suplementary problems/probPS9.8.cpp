#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

const int max_chars = 50;

// Prototipos de funciones.
int getMatricula(char *);
int contRenglones(FILE *);
void ordenamientoArray(int *, int);
void deleteNewLine(char *);

// Programa principal.
int main() {
    FILE *apuntador_lectura = fopen("PS9.8 (arc.dat).dat", "r");
    FILE *apuntador_escritura = fopen("PS9.8 (arc1.dat).dat", "w");
    char cadena[max_chars];
    int i, j;

    if(apuntador_lectura == NULL) {
        printf("No se ha podido abrir el archivo.\n");
    }
    else {
        int cantidad_alumnos = contRenglones(apuntador_lectura);
        int matriculas[cantidad_alumnos];

        rewind(apuntador_lectura);

        for(i = 0; i < cantidad_alumnos; i++) {
            fgets(cadena, max_chars, apuntador_lectura);
            matriculas[i] = getMatricula(cadena);
            printf("Matricula: %d\n", matriculas[i]);
        }

        ordenamientoArray(matriculas, cantidad_alumnos);

        printf("\nMatriculas ordenadas: \n");
        for(i = 0; i < cantidad_alumnos; i++) {
            printf("Matricula: %d\n", matriculas[i]);
        }

        rewind(apuntador_lectura);

        for(i = 0; i < cantidad_alumnos; i++) {
            rewind(apuntador_lectura);
            for(j = 0; j < cantidad_alumnos; j++) {
                fgets(cadena, max_chars, apuntador_lectura);
                deleteNewLine(cadena);
                if(getMatricula(cadena) == matriculas[i]) {
                    fputs(cadena, apuntador_escritura);
                    fprintf(apuntador_escritura, "\n");
                }
            }
        }
    }

    fclose(apuntador_lectura);
    fclose(apuntador_escritura);

    return 0;
}

// Definiciones de funciones.
int getMatricula(char *string) {
    int i = 0, j = 0;
    char mat_str[max_chars];
    
    while(string[i] != ' ') {
        if(isdigit(string[i])) {
            mat_str[j] = string[i];
            j++;
        }
        i++;
    }

    return atoi(mat_str);
}
int contRenglones(FILE *pointer) {
    int cont = 0;
    char aux[max_chars];

    rewind(pointer);
    while(!(feof(pointer))) {
        fgets(aux, max_chars, pointer);
        cont++;
    }

    return cont;
}
void ordenamientoArray(int *array, int size) {
    int i, j, aux;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if(array[i] < array[j]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}