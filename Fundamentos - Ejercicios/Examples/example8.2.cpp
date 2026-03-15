#include <stdio.h>
#include <string.h>

struct alumno {
    int matricula;
    char nombre[20];
    char carrera[20];
    float promedio;
    char domicilio[20];
};

int main() {
    struct alumno a1 = {1234, "Guillermo", "Sistemas", 9.1, "La shioja"};
    struct alumno a2, a3;

    char nom[20], carr[20], dom[20];
    int mat;
    float prom;
    
    // Asignacion de valores a 'a2'
    printf("Ingrese la matricula del alumno 2: ");
    scanf("%d", &a2.matricula);
    getchar();

    printf("Ingrese el nombre del alumno 2: ");
    fgets(a2.nombre, sizeof(a2.nombre), stdin);

    printf("Ingrese la carrera del alumno 2: ");
    fgets(a2.carrera, sizeof(a2.carrera), stdin);

    printf("Ingrese el promedio del alumno 2: ");
    scanf("%f", &a2.promedio);
    getchar();

    printf("Ingrese el domicilio del alumno 2: ");
    fgets(a2.domicilio, sizeof(a2.domicilio), stdin);

    // Asignacion de valores a 'a3'
    printf("Ingrese la matricula del alumno 3: ");
    scanf("%d", &mat);
    getchar();
    a3.matricula = mat;

    printf("Ingrese el nombre del alumno 3: ");
    fgets(nom, sizeof(nom), stdin);
    strcpy(a3.nombre, nom);

    printf("Ingrese la carrera del alumno 3: ");
    fgets(carr, sizeof(carr), stdin);
    strcpy(a3.carrera, carr);

    printf("Ingrese el promedio del alumno 3: ");
    scanf("%f", &prom);
    getchar();
    a3.promedio = prom;

    printf("Ingrese el domicilio del alumno 3: ");
    fgets(dom, sizeof(dom), stdin);
    strcpy(a3.domicilio, dom);

    puts(a1.nombre);

    printf("%d\n", a2.matricula);
    puts(a2.nombre);
    puts(a2.carrera);
    printf("%f\n", a2.promedio);
    puts(a2.domicilio);

    printf("\n\n");

    printf("%d\n", a3.matricula);
    puts(a3.nombre);
    puts(a3.carrera);
    printf("%f\n", a3.promedio);
    puts(a3.domicilio);

    return 0;
}