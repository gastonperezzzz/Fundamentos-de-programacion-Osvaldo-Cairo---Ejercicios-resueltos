#include <stdio.h>
#include <string.h>

void delNewLine(char *);

struct alumno {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char direccion[20];
};

void lectura(struct alumno *);

int main() {
    struct alumno a0 = {120, "Maria", "Contabilidad", 8.9, "Tijuana"};
    struct alumno *a4;
    struct alumno a6;

    // a3 = &a0;

    a4 = new(struct alumno);
    lectura(a4);

    // a5 = new(struct alumno);
    // lectura(a5);

    // lectura(&a6);

    printf("Datos del alumno 4:\n %d, %s, %s, %.2f, %s\n", a0.matricula, a0.nombre, a0.carrera, a0.promedio, a0.direccion);
    printf("Datos del alumno 4:\n %d, %s, %s, %.2f, %s\n", a4->matricula, (*a4).nombre, a4->carrera, a4->promedio, a4->direccion);
    
    lectura(&a6);

    printf("Datos del alumno 6:\n %d, %s, %s, %.2f, %s\n", a6.matricula, a6.nombre, a6.carrera, a6.promedio, a6.direccion);

    return 0;
}

void lectura(struct alumno *a) {
    // fflush(stdin);
    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &(*a).matricula);
    getchar();

    printf("Ingrese el nombre del alumno: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    delNewLine(a->nombre);

    printf("Ingrese la carrera del alumno: ");
    fgets((*a).carrera, sizeof((*a).carrera), stdin);
    delNewLine((*a).carrera);

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &a->promedio);
    getchar();

    printf("Ingrese el domicilio del alumno: ");
    fgets(a->direccion, sizeof(a->direccion), stdin);
    delNewLine(a->direccion);
}
void delNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}