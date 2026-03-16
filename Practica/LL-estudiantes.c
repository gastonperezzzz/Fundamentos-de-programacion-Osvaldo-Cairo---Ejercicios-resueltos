#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

struct nodoEstudiante {
    char nombre[MAX_CHARS];
    int legajo;
    struct nodoEstudiante *sigue;
};

struct nodoEstudiante *inicio, *nuevo, *recorre, *aux;

void agregarNodo(); // Insercion ordenada (alfabeticamente)
int eliminarNodo(); // Eliminacion por clave
void busqueda(); // Busqueda por nombre
void mostrarLista();
void deleteNewLine(char *);

int main() {
    inicio = NULL;
    int opcion;

    do {
        printf("\n-----Gestor de estudiantes-----\n");
        printf("1. Agregar estudiantes (insercion ordenada)\n");
        printf("2. Mostrar lista de estudiantes\n");
        printf("3. Buscar estudiante (por nombres)\n");
        printf("4. Eliminar estudiante (por clave)\n");
        printf("0. Salir del programa\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                agregarNodo();
                break;
            case 2:
                mostrarLista();
                break;
            case 3:
                busqueda();
                break;
            case 4:
                eliminarNodo();
                break;
            case 0:
                printf("Saliendo del programa...");
                // limpiarMemoria();
                break;
            default:
                printf("Error: Opcion invalida.\n");
                break;
        }

    } while(opcion != 0);


    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void agregarNodo() {
    nuevo = (struct nodoEstudiante *) malloc(sizeof(struct nodoEstudiante));

    if(nuevo == NULL) {
        printf("Error de memoria.\n");
    }
    else {
        printf("Ingrese el nombre completo del estudiante: ");
        fgets(nuevo->nombre, MAX_CHARS, stdin);
        deleteNewLine(nuevo->nombre);

        printf("Ingrese el legajo del estudiante: ");
        scanf("%d", &nuevo->legajo);
        getchar();

        if(inicio == NULL || nuevo->nombre[0] <= inicio->nombre[0]) {
            nuevo->sigue = inicio;
            inicio = nuevo;
        }
        else {
            recorre = inicio;
            while(recorre->sigue != NULL && nuevo->nombre[0] <= inicio->nombre[0]) {
                recorre = recorre->sigue;
            }
            nuevo->sigue = recorre->sigue;
            recorre->sigue = nuevo;
        }
    }
}
int eliminarNodo() {
    if(inicio == NULL) {
        printf("La lista esta vacia.\n");
        return 0;
    }
    else {
        int key;

        printf("Ingrese el legajo del estudiante que desea eliminar: ");
        scanf("%d", &key);
        getchar();

        if(inicio->legajo == key) {
            aux = inicio;
            inicio = inicio->sigue;
            free(aux);
            printf("Estudiante eliminado correctamente.\n");
            return 1;
        }
        else {
            recorre = inicio;

            while(recorre->sigue != NULL && recorre->sigue->legajo != key) {
                recorre = recorre->sigue;
            }

            if(recorre == NULL) {
                printf("No se ha encontrado una coincidencia con el legajo [%d]\n", key);
                return 0;
            }
            else {
                aux = recorre->sigue;
                recorre->sigue = recorre->sigue->sigue;
                free(aux);
                printf("Estudiante eliminado correctamente.\n");
                return 1;
            }
        }
    }
    return 0;
}
void mostrarLista() {
    printf("----------LISTA DE ESTUDIANTES----------\n");
    recorre = inicio;
    while(recorre) {
        printf("%s | %d\n", recorre->nombre, recorre->legajo);
        recorre = recorre->sigue;
    }
    printf("------------------------------");
}
void busqueda() {
    char nombre_busqueda[MAX_CHARS];

    printf("Ingrese el nombre del estudiante a buscar: ");
    fgets(nombre_busqueda, MAX_CHARS, stdin);
    deleteNewLine(nombre_busqueda);

    recorre = inicio;

    while(recorre != NULL && strcmp(nombre_busqueda, recorre->nombre) != 0) {
        recorre = recorre->sigue;
    }

    if(recorre == NULL) {
        printf("No se ha encontrado una coincidencia con el nombre [%s]\n", nombre_busqueda);
    }
    else {
        printf("Estudiante coincidente:\n \t%s | %d\n", recorre->nombre, recorre->legajo);
    }
}
