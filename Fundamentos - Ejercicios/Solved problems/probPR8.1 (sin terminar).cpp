#include <stdio.h>
#include <string.h>

const int max_chars = 50;

// Declaracion de la estructura.
typedef struct {
    int clave;
    char nombre[max_chars];
    int cantidad;
    float precio;
} producto;

// Prototipo de funciones.
void ordenamientoPorClave(producto *, int); // Hecho.
void ventas(producto *, int);
void reabastecimiento(producto *, int);
void nuevosProductos(producto *, int);
void inventario(producto *, int);

// Programa principal.
int main() {
    unsigned int numero_productos;

    do {
        printf("Ingrese el numero de productos: ");
        scanf("%d", &numero_productos);
        if(numero_productos < 1 || numero_productos > 100) {
            printf("Error: numero de productos invalido.\n");
        }
    } while(numero_productos < 1 || numero_productos > 100);

    producto inventario[numero_productos];

    return 0;
}

void ordenamientoPorClave(producto *inv, int size) {
    int i, j, aux = 0;
    for(i = 0; i < size; i++) {
        for(j = (i + 1); j < size; j++) {
            if(inv[i].clave > inv[j].clave) {
                aux = inv[i].clave;
                inv[i].clave = inv[j].clave;
                inv[j].clave = aux;
            }
        }
    }
}
void ventas(producto *inv, int size) {
    
}