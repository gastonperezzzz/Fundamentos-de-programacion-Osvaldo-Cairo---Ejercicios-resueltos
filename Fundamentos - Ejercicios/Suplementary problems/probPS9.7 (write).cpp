#include <stdio.h>
#include <string.h>

const int max_chars = 50;

typedef struct {
    int matricula;
    char nom_ap[max_chars];
    int carrera;
    float promedio;
} alumno;

void deleteNewLine(char *);
void deleteReg(FILE *pointer, int replica);

int main() {
    FILE *apuntador;
    alumno estudiante;
    int option;
    int conteo = 0;

    apuntador = fopen("probPS9.7.dat", "w+");

    do {
        printf("Desea ingresar informacion sobre alumnos? \n0. No \n1. Si \nOpcion: ");
        scanf("%d", &option);
        getchar();
    } while(option != 1 && option != 0);

    while(option) {
        conteo++;

        printf("Alumno [%d] | Matricula: ", conteo);
        scanf("%d", &estudiante.matricula);
        getchar();

        printf("Alumno [%d] | Nombre y apellido: ", conteo);
        fgets(estudiante.nom_ap, max_chars, stdin);
        deleteNewLine(estudiante.nom_ap);

        printf("Alumno [%d] | Carrera: ", conteo);
        scanf("%d", &estudiante.carrera);
        getchar();

        printf("Alumno [%d] | Promedio: ", conteo);
        scanf("%f", &estudiante.promedio);
        getchar();

        fwrite(&estudiante, sizeof(alumno), 1, apuntador);

        do {
            printf("Desea ingresar informacion sobre alumnos? \n0. No \n1. Si \nOpcion: ");
            scanf("%d", &option);
            getchar();
        } while(option != 1 && option != 0);
    }

    int index;

    do {
        printf("Desea duplicar registros al final del archivo?: ");
        scanf("%d", &option);
        getchar();
    } while(option != 0 && option != 1);


    while(option) {
        do {
            printf("Que registro de alumno desea duplicar? [1 - %d]: ", conteo);
            scanf("%d", &index);
            getchar();
        } while(index < 1 || index > conteo);

        fseek(apuntador, (index - 1) * sizeof(alumno), SEEK_SET);
        fread(&estudiante, sizeof(alumno), 1, apuntador);
        fseek(apuntador, 0, SEEK_END);
        fwrite(&estudiante, sizeof(alumno), 1, apuntador);

        do {
            printf("Desea duplicar otro registro al final del archivo?: ");
            scanf("%d", &option);
            getchar();
        } while(option != 0 && option != 1);
    }
    
    fclose(apuntador);

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void deleteReg(FILE *pointer, int replica) {
    alumno student;
    
    fseek(pointer, 0, SEEK_END);
    fread(&student, sizeof(alumno), 1, pointer);
    fseek(pointer, (replica - 1), SEEK_SET);
    fwrite(&student, sizeof(alumno), 1, pointer);
}