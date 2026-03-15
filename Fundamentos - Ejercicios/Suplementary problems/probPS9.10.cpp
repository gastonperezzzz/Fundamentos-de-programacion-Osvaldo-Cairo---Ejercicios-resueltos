#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Constantes necesarias.
const int max_chars = 50;

// Declaracion de estructuras.
typedef struct {
    char calle[max_chars];
    int numero_casa;
    char colonia[max_chars];
    char cod_postal[max_chars];
    char ciudad[max_chars];
    char telefono[max_chars];
} domicilio;

typedef struct {
    int clave_paciente;
    char nom_ap[max_chars];
    int edad;
    char sexo;
    int condicion;
    domicilio vivienda;
} paciente;

// Prototipos de funciones.
void deleteNewLine(char *);
void lecturaPaciente(FILE *);
void porcentajeHombresMujeres(FILE *, int);
void pacientesPorCondicion(FILE *, int);
void pacientesCategoriaEdad(FILE *, int);

// Programa principal.
int main() {
    FILE *apuntador = fopen("probPS9.10 (pacientes.dat).dat", "w+");
    int cantidad_pacientes = 0;
    int option = 1;

    while(option == 1) {
        
        lecturaPaciente(apuntador);
        cantidad_pacientes++;
        do {
            printf("Desea ingresar otro paciente? \n0. No \n1. Si \nOpcion: ");
            scanf("%d", &option);
            getchar();
        } while(option != 0 && option != 1);
    }

    porcentajeHombresMujeres(apuntador, cantidad_pacientes);
    pacientesPorCondicion(apuntador, cantidad_pacientes);
    pacientesCategoriaEdad(apuntador, cantidad_pacientes);

    return 0;
}

// Definicion de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaPaciente(FILE *pointer) {
    paciente aux;

    do {
        printf("Clave del paciente: ");
        scanf("%d", &aux.clave_paciente);
        getchar();
        if(aux.clave_paciente <= 0) {
            printf("Error: clave invalida.\n");
        }
    } while(aux.clave_paciente <= 0);

    printf("Nombre y apellido del paciente: ");
    fgets(aux.nom_ap, max_chars, stdin);
    deleteNewLine(aux.nom_ap);

    do {
        printf("Edad del paciente: ");
        scanf("%d", &aux.edad);
        getchar();
    } while(aux.edad < 0);

    do {
        printf("Sexo del paciente (M/F): ");
        aux.sexo = getchar();
        if(islower(aux.sexo)) {
            aux.sexo = toupper(aux.sexo);
        }
        if(aux.sexo != 'M' && aux.sexo != 'F') {
            printf("Error: Condicion invalida.\n");
        }
    } while(aux.sexo != 'M' && aux.sexo != 'F');

    do {
        printf("Condicion del paciente [1 - 5]: ");
        scanf("%d", &aux.condicion);
        getchar();
        if(aux.condicion < 1 || aux.condicion > 5) {
            printf("Error: Condicion invalida.\n");
        }
    } while(aux.condicion < 1 || aux.condicion > 5);

    printf("Domicilio: \n");
    printf("\tCalle: ");
    fgets(aux.vivienda.calle, max_chars, stdin);
    deleteNewLine(aux.vivienda.calle);

    do {
        printf("\tNumero de casa: ");
        scanf("%d", &aux.vivienda.numero_casa);
        getchar();
        if(aux.vivienda.numero_casa <= 0) {
            printf("Error: numero de casa invalido.\n");
        }
    } while(aux.vivienda.numero_casa <= 0);

    printf("\tColonia: ");
    fgets(aux.vivienda.colonia, max_chars, stdin);
    deleteNewLine(aux.vivienda.colonia);

    printf("\tCodigo postal: ");
    fgets(aux.vivienda.cod_postal, max_chars, stdin);
    deleteNewLine(aux.vivienda.cod_postal);

    printf("\tCiudad: ");
    fgets(aux.vivienda.ciudad, max_chars, stdin);
    deleteNewLine(aux.vivienda.ciudad);

    printf("\tTelefono: ");
    fgets(aux.vivienda.telefono, max_chars, stdin);
    deleteNewLine(aux.vivienda.telefono);

    fwrite(&aux, sizeof(paciente), 1, pointer);
}
void porcentajeHombresMujeres(FILE *pointer, int size) {
    int i;
    float hombres = 0, mujeres = 0;
    paciente aux;

    rewind(pointer);
    for(i = 0; i < size; i++) {
        fread(&aux, sizeof(paciente), 1, pointer);
        if(aux.sexo == 'M') {
            hombres++;
        }
        else {
            mujeres++;
        }
    }

    printf("Porcentaje de hombres en el hospital: %.2f\n", (hombres / size) * 100);
    printf("Porcentaje de mujeres en el hospital: %.2f\n\n", (mujeres / size) * 100);
}
void pacientesPorCondicion(FILE *pointer, int size) {
    int condicion[5] = {0};
    int i;
    paciente aux;

    rewind(pointer);
    for(i = 0; i < size; i++) {
        fread(&aux, sizeof(paciente), 1, pointer);
        condicion[aux.condicion - 1]++;
    }
    for(i = 0; i < 5; i++) {
        printf("Condicion %d | Numero de pacientes: %d\n", i + 1, condicion[i]);
    }
    printf("\n");
}
void pacientesCategoriaEdad(FILE *pointer, int size) {
    int cat[11] = {0}, i;
    paciente aux;

    rewind(pointer);
    for(i = 0; i < size; i++) {
        fread(&aux, sizeof(paciente), 1, pointer);
        if(aux.edad >= 0 && aux.edad <= 9) {
            cat[0]++;
        }
        else if(aux.edad >= 10 && aux.edad <= 19) {
            cat[1]++;
        }
        else if(aux.edad >= 20 && aux.edad <= 29) {
            cat[2]++;
        }
        else if(aux.edad >= 30 && aux.edad <= 39) {
            cat[3]++;
        }
        else if(aux.edad >= 40 && aux.edad <= 49) {
            cat[4]++;
        }
        else if(aux.edad >= 50 && aux.edad <= 59) {
            cat[5]++;
        }
        else if(aux.edad >= 60 && aux.edad <= 69) {
            cat[6]++;
        }
        else if(aux.edad >= 70 && aux.edad <= 79) {
            cat[7]++;
        }
        else if(aux.edad >= 80 && aux.edad <= 89) {
            cat[8]++;
        }
        else if(aux.edad >= 90 && aux.edad <= 99) {
            cat[9]++;
        }
        else if(aux.edad >= 100) {
            cat[10]++;
        }
    }

    for(i = 0; i < 11; i++) {
        printf("Categoria %d | Numero de pacientes: %d\n", i + 1, cat[i]);
    }
    printf("\n");
}