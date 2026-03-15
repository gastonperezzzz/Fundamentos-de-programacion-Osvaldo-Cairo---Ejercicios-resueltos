#include <stdio.h>
#include <string.h>

typedef struct {
    int matricula;
    char nom_ap[50];
    int carrera;
    float promedio;
} alumno;

void deleteNewLine(char *);
void modificar(FILE *);

int main() {
    FILE *archive;

    if((archive = fopen("ad1.dat", "r+")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        modificar(archive);
        fclose(archive);
    }

    return 0;
}
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void modificar(FILE *file) {
    alumno estudiante;
    
    int indice;

    printf("Ingrese el numero de registro del alumno que desea modificar: ");
    scanf("%d", &indice);
    getchar();

    fseek(file, (indice - 1)*sizeof(alumno), 0);
    fread(&estudiante, sizeof(alumno), 1, file);

    printf("Ingrese el promedio correcto del alumno: ");
    scanf("%f", &estudiante.promedio);
    getchar();

    fseek(file, (indice - 1)*sizeof(alumno), 0);
    fwrite(&estudiante, sizeof(alumno), 1, file);
}
