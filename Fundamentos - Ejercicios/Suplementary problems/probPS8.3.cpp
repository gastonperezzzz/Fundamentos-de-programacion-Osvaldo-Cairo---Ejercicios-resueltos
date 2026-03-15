#include <stdio.h>
#include <string.h>

const int max_chars = 50;
const int meses = 3;

// Declaracion de estructuras.
typedef struct {
    unsigned int num_empleado;
    char nom_ap[max_chars];
    char departamento[max_chars];
    char puesto[max_chars];
    char grado_academico[max_chars];
    char nacionalidad[max_chars];
    float salario[meses];
} profesor;

// Prototipos de funciones.
void deleteNewLine(char *); // Hecho
void lecturaProfesores(profesor *, int); // Hecho
void profesorMayorSalario(profesor *, int); // Hecho
void montoTotalProfesoresExtranjeros(profesor *, int); // Hecho
void departamentoMasEgresos(profesor *, int); // Hecho

// Programa principal.
int main() {
    unsigned int numero_profesores;

    do {
        printf("Ingrese la cantidad de profesores que tiene la universidad: ");
        scanf("%d", &numero_profesores);
        getchar();
        if(numero_profesores < 1 || numero_profesores > 100) {
            printf("Error: cantidad invalida.\n");
        }
    } while(numero_profesores < 1 || numero_profesores > 100);

    profesor profesores[numero_profesores];

    lecturaProfesores(profesores, numero_profesores);
    profesorMayorSalario(profesores, numero_profesores);
    montoTotalProfesoresExtranjeros(profesores, numero_profesores);
    departamentoMasEgresos(profesores, numero_profesores);

    return 0;
}

// Definicion de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaProfesores(profesor *var, int size) {
    int i, j;
    for(i = 0; i < size; i++) {
        printf("Profesor [%d] | Nro. de empleado: ", i + 1);
        scanf("%d", &var[i].num_empleado);
        getchar();

        printf("Profesor [%d] | Nombre y apellido: ", i + 1);
        fgets(var[i].nom_ap, max_chars, stdin);
        deleteNewLine(var[i].nom_ap);
    
        printf("Profesor [%d] | Departamento: ", i + 1);
        fgets(var[i].departamento, max_chars, stdin);
        deleteNewLine(var[i].departamento);

        printf("Profesor [%d] | Puesto a cargo: ", i + 1);
        fgets(var[i].puesto, max_chars, stdin);
        deleteNewLine(var[i].puesto);

        printf("Profesor [%d] | Grado academico: ", i + 1);
        fgets(var[i].grado_academico, max_chars, stdin);
        deleteNewLine(var[i].grado_academico);
    
        printf("Profesor [%d] | Nacionalidad: ", i + 1);
        fgets(var[i].nacionalidad, max_chars, stdin);
        deleteNewLine(var[i].nacionalidad);

        for(j = 0; j < meses; j++) {
            do {
                printf("Profesor [%d] | Salario mes [%d]: ", i + 1, j + 1);
                scanf("%f", &var[i].salario[j]);
                getchar();
            } while(var[i].salario[j] < 1.0);
        }
    }
    printf("\n");
}
void profesorMayorSalario(profesor *var, int size) {
    int i, j;
    int i_mayorsalario = 0;
    float salario_total, mayor_salario = 0.0;
    for(i = 0; i < size; i++) {
        salario_total = 0.0;
        for(j = 0; j < meses; j++) {
            salario_total += var[i].salario[j];
        }
        if(mayor_salario < salario_total) {
            mayor_salario = salario_total;
            i_mayorsalario = i;
        }
    }
    printf("Profesor con el mayor salario del año anterior: \n");
    printf("%s | %s | %s | Ingreso total: %.2f\n", var[i_mayorsalario].nom_ap, var[i_mayorsalario].departamento, var[i_mayorsalario].nacionalidad, mayor_salario);
}
void montoTotalProfesoresExtranjeros(profesor *var, int size) {
    int i, j;
    double total_erogado = 0.0, monto_total_extranjeros = 0.0;
    for(i = 0; i < size; i++) {
        for(j = 0; j < meses; j++) {
            total_erogado += var[i].salario[j];
            if(strcmp(var[i].nacionalidad, "Colombia")) {
                monto_total_extranjeros += var[i].salario[j];
            }
        }
    }
    printf("El pago total a profesores extranjeros fue de %.2lf que corresponde al %.2lf total erogado por la universidad.\n", monto_total_extranjeros, (monto_total_extranjeros / total_erogado) * 100.0);
}
void departamentoMasEgresos(profesor *var, int size) {
    int i, i_dpto = 0, dpto_mas_egresos = 0;
    int departamentos[4] = {0};
    for(i = 0; i < size; i++) {
        if(!(strcmp(var[i].departamento, "Economia"))) {
            departamentos[0]++;
        }
        else if(!(strcmp(var[i].departamento, "Derecho"))) {
            departamentos[1]++;
        }
        else if(!(strcmp(var[i].departamento, "Computacion"))) {
            departamentos[2]++;
        }
        else if(!(strcmp(var[i].departamento, "Administracion"))) {
            departamentos[3]++;
        }
    }
    for(i = 0; i < 4; i++) {
        if(departamentos[i] > dpto_mas_egresos) {
            dpto_mas_egresos = departamentos[i];
            i_dpto = i;
        }
    }
    switch(i_dpto) {
        case 0:
            printf("El departamento de ECONOMIA fue el que mas egresos tuvo el ultimo año. Egresos: %d\n", dpto_mas_egresos);
            break;
        case 1:
            printf("El departamento de DERECHO fue el que mas egresos tuvo el ultimo año. Egresos: %d\n", dpto_mas_egresos);
            break;
        case 2:
            printf("El departamento de COMPUTACION fue el que mas egresos tuvo el ultimo año. Egresos: %d\n", dpto_mas_egresos);
            break;
        case 3:
            printf("El departamento de ADMINISTRACION fue el que mas egresos tuvo el ultimo año. Egresos: %d\n", dpto_mas_egresos);
            break;
    }
}