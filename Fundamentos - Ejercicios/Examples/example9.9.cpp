#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nom_ap[50];
    int carrera;
    float promedio;
} alumno;

void deleteNewLine(char *);
void leer(FILE *);

int main() {
    FILE *archive;

    if((archive = fopen("ad1.dat", "r")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        leer(archive);
        fclose(archive);
    }

    return 0;
}
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void leer(FILE *file) {
    alumno estudiante;
    
    fread(&estudiante, sizeof(alumno), 1, file);

    while(!feof(file)) {
        printf("Matricula: %d\n", estudiante.matricula);
        printf("Nombre y apellido: %s\n", estudiante.nom_ap);
        printf("Carrera: %d\n", estudiante.carrera);
        printf("Promedio: %f\n", estudiante.promedio);
        fread(&estudiante, sizeof(alumno), 1, file);
    }
}