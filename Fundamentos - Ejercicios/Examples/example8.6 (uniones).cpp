#include <stdio.h>
#include <string.h>

const int max_chars = 40;

union datos {
    char celular[15];
    char correo[max_chars];
};
typedef struct {
    int matricula;
    char nom_ap[max_chars];
    char carrera[max_chars];
    float promedio;
    union datos persona;
} alumno;

void lecturaAlumno(alumno *);

int main() {
    // alumno a1 = {333, "Rosa Melano", "Gastronomia", 7.8, "549 606072"};
    alumno a2;

    lecturaAlumno(&a2);
    // lecturaAlumno(a3);

    // Impresion de los datos de los alumnos
    printf("Datos del alumno a2:\n");
    printf("%d\n", a2.matricula);
    puts(a2.nom_ap);
    puts(a2.carrera);
    printf("%.2f\n", a2.promedio);
    puts(a2.persona.celular);

    // a2.persona.correo imprime basura (?)
    puts(a2.persona.correo);

    strcpy(a2.persona.correo, "miniosnose@gmail.com");

    puts(a2.persona.correo);
    puts(a2.persona.celular);

    // Conclusion: En este caso el otro miembro de la union no imprime basura, sino que ambas
    // variables toman el contenido del miembro en uso, por lo tanto se imprime el mismo valor.

    return 0;
}

void delNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaAlumno(alumno *var) {
    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &(*var).matricula);
    getchar();

    printf("Ingrese el nombre y apellido del alumno: ");
    fgets(var->nom_ap, max_chars, stdin);
    delNewLine(var->nom_ap);

    printf("Ingrese la carrera del alumno: ");
    fgets(var->carrera, max_chars, stdin);
    delNewLine(var->carrera);

    printf("Ingrese el promedio del alumno: ");
    scanf("%f", &(*var).promedio);
    getchar();

    printf("Ingrese su telefono: ");
    fgets(var->persona.celular, max_chars, stdin);
    delNewLine(var->persona.celular);

    printf("\n");
}