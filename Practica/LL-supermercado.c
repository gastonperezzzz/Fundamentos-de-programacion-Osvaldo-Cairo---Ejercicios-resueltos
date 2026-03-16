/*
Implementar:
    - Insercion (al principio, ordenada)
    - Eliminacion (al principio, por clave)
    - Funcion de busqueda (por clave)
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 50

struct NodoProducto {
    char nombre[MAX_CHARS];
    int stock;
    int clave;
    struct NodoProducto *sigue;
};

struct NodoProducto *inicio, *nuevo, *recorre, *aux;

void agregarProducto(); // Insercion de manera ordenada
void buscarProducto(); // Por clave de producto
int eliminarProducto(); // Eliminacion por clave
void mostrarLista();
void limpiarMemoria();
void deleteNewLine(char *);

int main() {
    inicio = NULL;
    int opcion;
    do {
        printf("\n-----Gestor de productos de supermercado-----\n");
        printf("1. Agregar producto (insercion ordenada)\n");
        printf("2. Mostrar lista de productos\n");
        printf("3. Buscar producto (por clave)\n");
        printf("4. Eliminar producto (por clave)\n");
        printf("0. Salir del programa\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                mostrarLista();
                break;
            case 3:
                buscarProducto();
                break;
            case 4:
                eliminarProducto();
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

void agregarProducto() {
    nuevo = (struct NodoProducto *) malloc(sizeof(struct NodoProducto));

    // Verificamos si se ha podido otorgar espacio de memoria al puntero.
    if(nuevo == NULL) {
        printf("Error: memoria insuficiente.\n");
    }
    else {
        printf("Ingrese el nombre del producto: ");
        fgets(nuevo->nombre, MAX_CHARS, stdin);
        deleteNewLine(nuevo->nombre);

        printf("Ingrese la clave del producto: ");
        scanf("%d", &nuevo->clave);
        getchar();

        printf("Ingrese el stock del producto: ");
        scanf("%d", &nuevo->stock);
        getchar();

        // Insercion al inicio
        if(inicio == NULL || (nuevo->clave) <= (inicio->clave)) {
            nuevo->sigue = inicio;
            inicio = nuevo;
        }
        else {
            // Insercion ordenada ascendente
            recorre = inicio;

            while(recorre->sigue != NULL && recorre->sigue->clave <= nuevo->clave) {
                recorre = recorre->sigue;
            }

            nuevo->sigue = recorre->sigue;
            recorre->sigue = nuevo;
        }
    }
}
void buscarProducto() {
    int key;

    printf("Ingrese la clave del producto que desea buscar: ");
    scanf("%d", &key);

    recorre = inicio;

    while((recorre != NULL) && (recorre->clave != key)) {
        recorre = recorre->sigue;
    }

    if(recorre == NULL) {
        printf("No se podido encontrar un producto con clave [%d]\n", key);
    }
    else {
        printf("Producto encontrado:\n");
        printf("%s | %d | %d\n", recorre->nombre, recorre->clave, recorre->stock);
    }
}
int eliminarProducto() {
    int key;

    printf("Ingrese la clave del producto que desea buscar: ");
    scanf("%d", &key);

    if(inicio->clave == key) {
        aux = inicio;
        inicio = inicio->sigue;
        free(aux);
        printf("Producto (al principio) eliminado correctamente.\n");
        return 1;
    }

    recorre = inicio;

    while((recorre->sigue) != NULL && (recorre->sigue)->clave != key) {
        recorre = recorre->sigue;
    }

    if(recorre == NULL) {
        printf("No se ha podido eliminar el producto con clave [%d]\n", key);
        return 0;
    }
    else {
        aux = recorre->sigue;
        recorre->sigue = recorre->sigue->sigue;
        free(aux);
        printf("Producto eliminado correctamente.\n");
        return 1;
    }

    return 0;
}
void mostrarLista() {
    printf("----------LISTA DE PRODUCTOS----------\n");
    recorre = inicio;
    while(recorre) {
        printf("%s | %d | %d\n", recorre->nombre, recorre->clave, recorre->stock);
        recorre = recorre->sigue;
    }
    printf("------------------------------");
}
/*
void limpiarMemoria() {
    while(inicio->sigue != NULL) {
        aux = inicio;
        inicio = inicio->sigue;
        free(aux);
    }
    free(inicio); free(recorre); free(nuevo);
}
*/
