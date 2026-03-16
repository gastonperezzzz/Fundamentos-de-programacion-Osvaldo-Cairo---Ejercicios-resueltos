#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Nodo {
    char dato;
    struct Nodo* siguiente;
} *nuevo, *inicio, *recorre, *aux;

void verListaEnlazada();

int main() {
    inicio = NULL;
    char c;

    printf("Ingrese caracteres hasta el punto: ");

    while((c = getchar()) != '.') {
        if(islower(c)) {
            nuevo = malloc(sizeof(struct Nodo));
            nuevo->dato = c;
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
        verListaEnlazada();
    }


    return 0;
}

void verListaEnlazada() {
    recorre = inicio;
    while(recorre != NULL) {
        printf("%c", recorre->dato);
        recorre = recorre->siguiente;
    }
}
