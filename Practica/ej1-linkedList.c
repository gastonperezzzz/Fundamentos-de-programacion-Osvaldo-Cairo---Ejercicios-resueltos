#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *next;
};

struct Nodo *primerNodo;

int main() {
    int cantidad_nodos;

    do {
        printf("Ingrese la cantidad de nodos: ");
        scanf("%d", &cantidad_nodos);
        getchar();
        if(cantidad_nodos < 0 || cantidad_nodos > 10) {
            printf("Error: cantidad invalida.\n");
        }
    } while(cantidad_nodos < 0 || cantidad_nodos > 10);

    struct Nodo *nNodo, *tmp;

    primerNodo = (struct Nodo *) malloc(sizeof(struct Nodo));

    if(primerNodo == NULL) {
        printf("Error: memoria insuficiente.\n");
    }
    else {
        printf("Ingrese un dato para el nodo 1: ");
        scanf("%d", &primerNodo->dato);
        primerNodo->next = NULL;
        tmp = primerNodo;

        for(int i = 2; i <= cantidad_nodos; i++) {
            nNodo = (struct Nodo *) malloc(sizeof(struct Nodo));
            printf("Ingrese un dato para el nodo %d: ", i);
            scanf("%d", &nNodo->dato);
            nNodo->next = NULL;
            tmp->next = nNodo;
            tmp = tmp->next;
        }

    }

    tmp = primerNodo;

    printf("\n");

    for(int i = 0; i < cantidad_nodos; i++) {
        printf("Nodo %d: %d\n", i + 1, tmp->dato);
        tmp = tmp->next;
    }



    return 0;
}
