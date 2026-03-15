#include <stdio.h>
#include <string.h>

const int max_chars = 50;

// Declaracion de estructuras.
typedef struct {
    char calle[max_chars];
    int numero;
    char colonia[max_chars];
    char cod_postal[max_chars];
    char ciudad[max_chars];
} domicilio;

typedef struct {
    char nom_ap[max_chars];
    int edad;
    char genero;
    int condicion;
    domicilio direccion;
    char telefono[max_chars];
} paciente;

// Prototipo de funciones.
void deleteNewLine(char *); // Done
void lecturaPacientes(paciente *, int); // Done
void hombresMujeresPorcentaje(paciente *, int); // Done
void numeroPacientesCondicion(paciente *, int); // Done
void telefonoPacientesGraves(paciente *, int); // Done

// Programa principal.
int main() {
    int numero_pacientes;

    do {
        printf("Ingrese el numero de pacientes: ");
        scanf("%d", &numero_pacientes);
        getchar();
        if(numero_pacientes < 1 || numero_pacientes > 100) {
            printf("Error: numero invalido.\n");
        }
    } while(numero_pacientes < 1 || numero_pacientes > 100);

    paciente hospital[numero_pacientes];

    lecturaPacientes(hospital, numero_pacientes);
    hombresMujeresPorcentaje(hospital, numero_pacientes);
    numeroPacientesCondicion(hospital, numero_pacientes);
    telefonoPacientesGraves(hospital, numero_pacientes);

    return 0;
}

// Definicion de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaPacientes(paciente *var, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("Paciente [%d] | Nombre y apellido: ", i + 1);
        fgets(var[i].nom_ap, max_chars, stdin);
        deleteNewLine(var[i].nom_ap);

        do {
            printf("Paciente [%d] | Edad: ", i + 1);
            scanf("%d", &var[i].edad);
            getchar();
        } while(var[i].edad < 0 || var[i].edad > 120);

        do {
            printf("Paciente [%d] | Genero [M/F]: ", i + 1);
            var[i].genero = getchar();
            if(var[i].genero != 'M' && var[i].genero != 'm' && var[i].genero != 'F' && var[i].genero != 'f') {
                printf("Error: opcion invalida.\n");
            }
        } while(var[i].genero != 'M' && var[i].genero != 'm' && var[i].genero != 'F' && var[i].genero != 'f');

        do {
            printf("Paciente [%d] | Condicion [1 - 5]: ", i + 1);
            scanf("%d", &var[i].condicion);
            getchar();
            if(var[i].condicion < 1 || var[i].condicion > 5) {
                printf("Error: Condicion invalida.\n");
            }
        } while(var[i].condicion < 1 || var[i].condicion > 5);

        printf("Domicilio:\n");
        printf("\tPaciente [%d] | Calle: ", i + 1);
        fgets(var[i].direccion.calle, max_chars, stdin);
        deleteNewLine(var[i].direccion.calle);

        printf("\tPaciente [%d] | Numero de casa: ", i + 1);
        scanf("%d", &var[i].direccion.numero);
        getchar();

        printf("\tPaciente [%d] | Colonia: ", i + 1);
        fgets(var[i].direccion.colonia, max_chars, stdin);
        deleteNewLine(var[i].direccion.colonia);

        printf("\tPaciente [%d] | Codigo postal: ", i + 1);
        fgets(var[i].direccion.cod_postal, max_chars, stdin);
        deleteNewLine(var[i].direccion.cod_postal);

        printf("\tPaciente [%d] | Ciudad: ", i + 1);
        fgets(var[i].direccion.ciudad, max_chars, stdin);
        deleteNewLine(var[i].direccion.ciudad);

        printf("Paciente [%d] | Telefono: ", i + 1);
        fgets(var[i].telefono, max_chars, stdin);
        deleteNewLine(var[i].telefono);
    }
}
void hombresMujeresPorcentaje(paciente *var, int size) {
    int i;
    float hombres = 0.0, mujeres = 0.0, total = 0.0;
    for(i = 0; i < size; i++) {
        if(var[i].genero == 'M' || var[i].genero == 'm') {
            hombres++;
        }
        else if(var[i].genero == 'F' || var[i].genero == 'f') {
            mujeres++;
        }
    }
    total = hombres + mujeres;
    printf("Porcentaje de hombres en el hospital: %.1f \n", (hombres / total) * 100.0);
    printf("Porcentaje de mujeres en el hospital: %.1f \n", (mujeres / total) * 100.0);
}
void numeroPacientesCondicion(paciente *var, int size) {
    int i;
    int condiciones[5] = {0};
    for(i = 0; i < size; i++) {
        if(var[i].condicion == 1) {
            condiciones[0]++;
        }
        else if(var[i].condicion == 2) {
            condiciones[1]++;
        }
        else if(var[i].condicion == 3) {
            condiciones[2]++;
        }
        else if(var[i].condicion == 4) {
            condiciones[3]++;
        }
        else if(var[i].condicion == 5) {
            condiciones[4]++;
        }
    }
    for(i = 0; i < 5; i++) {
        printf("Condicion %d | Pacientes: %d\n", i + 1, condiciones[i]);
    }
}
void telefonoPacientesGraves(paciente *var, int size) {
    int i;
    printf("Numero telefonico de parcientes de maxima gravedad (cat. 5):\n");
    for(i = 0; i < size; i++) {
        if(var[i].condicion == 5) {
            printf("Paciente %d | %s | Telefono: %s\n", i + 1, var[i].nom_ap, var[i].telefono);
        }
    }
}