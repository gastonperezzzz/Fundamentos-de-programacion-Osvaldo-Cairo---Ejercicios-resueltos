/*
Escribir un programa en el que se usen listas enlazadas para la gestion de alumnos en una universidad.
Implementar funciones de agregacion, busqueda y eliminacion de alumnos. La busqueda y eliminacion se
realizara de acuerdo a la matricula del estudiante.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHARS 50

struct Nodo {
    char nombre[MAX_CHARS];
    int matricula;
    float nota_final;
    struct Nodo *siguiente;
};

struct Nodo *inicio, *recorre, *aux, *nuevo;

void deleteNewLine(char *);
void agregarAlumno();
void buscarAlumno(int);
int eliminarAlumno(int);

int main() {
    inicio = NULL;
    int opcion;
    int matricula;

    do {
        printf("SISTEMA DE GESTION DE ALUMNOS UNLAR.\n");
        printf("1. Agregar alumno\n");
        printf("2. Buscar alumno\n");
        printf("3. Eliminar alumno\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                agregarAlumno();
                break;
            case 2:
                printf("Ingrese la matricula del alumno a buscar: ");
                scanf("%d", &matricula);
                buscarAlumno(matricula);
                getchar();
                break;
            case 3:
                printf("Ingrese la matricula del alumno a eliminar: ");
                scanf("%d", &matricula);
                eliminarAlumno(matricula);
                getchar();
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while(opcion != 0);

    printf("Saliendo del programa...\n");

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void agregarAlumno() {
    char name[MAX_CHARS];
    int mat;
    float nota_final;

    printf("Ingrese el nombre del alumno: ");
    fgets(name, MAX_CHARS, stdin);
    deleteNewLine(name);

    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &mat);
    getchar();

    printf("Ingrese la nota final: ");
    scanf("%f", &nota_final);
    getchar();

    nuevo = malloc(sizeof(struct Nodo));
    nuevo->matricula = mat;
    nuevo->nota_final = nota_final;
    strcpy(nuevo->nombre, name);
    nuevo->siguiente = inicio;
    inicio = nuevo;

    printf("Alumno %d agregado correctamente.\n", inicio->matricula);
}

void buscarAlumno(int matri) {
    recorre = inicio;

    while(recorre != NULL) {
        if(recorre->matricula == matri) {
            printf("Alumno encontrado:\n %s | %d | %.2f.\n", recorre->nombre, recorre->matricula, recorre->nota_final);
            break;
        }
        recorre = recorre->siguiente;
    }
    if(recorre == NULL) {
        printf("Matricula inexistente.\n");
    }
}

int eliminarAlumno(int matri) {
    if(inicio == NULL) {
        printf("La lista esta vacia.\n");
        return 0;
    }
    else if(inicio->matricula == matri) {
        aux = inicio;
        inicio = inicio->siguiente;
        free(aux);
        printf("Alumno eliminado correctamente.\n");
        return 1;
    }

    recorre = inicio;

    while((recorre->siguiente != NULL) && (recorre->siguiente->matricula != matri)) {
        recorre = recorre->siguiente;
    }

    if(recorre->siguiente != NULL) {
        if((recorre->siguiente)->matricula == matri) {
            aux = recorre->siguiente;
            recorre->siguiente = (recorre->siguiente)->siguiente;
            free(aux);
            printf("Alumno eliminado correctamente.\n");
            return 1;
        }
    }

    return 0;
}
