#include <stdio.h>
#include <stdlib.h>

// DEFINICION DE ESTRUCTURA NODO.
struct Nodo {
  char dato;
  struct Nodo *siguiente;
};

struct Nodo *inicio, *nuevo, *recorre, *aux;

// PROTOTIPOS DE FUNCIONES.
void verLista();
void agregarNodo(char);

// FUNCION PRINCIPAL
int main() {
    inicio = NULL;
    char dato;

    while((dato = getchar()) != '.') {
        agregarNodo(dato);
    }

    verLista();

    return 0;
}

// DEFINICION DE FUNCIONES
    // VER_LISTA
void verLista() {
    recorre = inicio;

    while(recorre != NULL) {
        printf("%c ", recorre->dato);
        recorre = recorre->siguiente;
    }

    printf("\nFIN DE LISTA.\n");
}

    // AGREGAR NODOS
void agregarNodo(char dato) {
    nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevo->dato = dato;
    nuevo->siguiente = inicio;
    inicio = nuevo;

    printf("Nodo creado correctamente.\n");
}
