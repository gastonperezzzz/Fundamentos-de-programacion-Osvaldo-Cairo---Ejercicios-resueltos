#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int max_chars = 50;

// Declaracion de estructuras.
typedef struct {
    unsigned int clave_producto;
    char nombre_producto[max_chars];
    unsigned int existencia;
} producto;

// Prototipos de funciones
void deleteNewLine(char *); // Hecho
void lecturaProductos(producto *, int); // Hecho
void mostrarProductos(producto *, int); // Hecho
int verifExistenciaProducto(producto *, int, unsigned); // Hecho
void ventaProducto(producto *, int, unsigned int, int);
void compraProducto(producto *, int, unsigned int, int);

// Programa principal.
int main() {
    int numero_productos, i_producto;
    char operacion;
    unsigned int clave;
    int cantidad;

    do {
        printf("Ingrese la cantidad de productos que tendra la tienda: ");
        scanf("%d", &numero_productos);
        getchar();
        if(numero_productos < 1 || numero_productos > 100) {
            printf("Error: cantidad invalida.\n");
        }
    } while(numero_productos < 1 || numero_productos > 100);

    producto tienda[numero_productos];
    lecturaProductos(tienda, numero_productos);

    do {
        bool pass;
        mostrarProductos(tienda, numero_productos);
        do {
            pass = true;
            printf("Ingrese la operacion [C/V], clave y cantidad del producto a procesar: ");
            scanf("%c %d %d", &operacion, &clave, &cantidad);
            getchar();
            operacion = tolower(operacion);
            i_producto = verifExistenciaProducto(tienda, numero_productos, clave);
            if(operacion != 'c' && operacion != 'v' && operacion != '0') {
                pass = false;
                printf("Error: operacion invalida.\n");
            }
            if(i_producto == -1) {
                pass = false;
                printf("Error: clave de producto inexistente.\n");
            }
            if(cantidad < 0) {
                pass = false;
                printf("Error: cantidad ingresada no disponible.\n");
            }
        } while(pass == false);
        
        switch(operacion) {
            case 'c':
                compraProducto(tienda, numero_productos, clave, cantidad);
                mostrarProductos(tienda, numero_productos);
                break;
            case 'v':
                ventaProducto(tienda, numero_productos, clave, cantidad);
                mostrarProductos(tienda, numero_productos);
                break;
        }
    } while(operacion != '0');

    return 0;
}

// Definiciones de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaProductos(producto *var, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("Producto [%d] | Clave del producto: ", i + 1);
        scanf("%d", &var[i].clave_producto);
        getchar();

        printf("Producto [%d] | Nombre del producto: ", i + 1);
        fgets(var[i].nombre_producto, max_chars, stdin);
        deleteNewLine(var[i].nombre_producto);

        printf("Producto [%d] | Existencia o cantidad: ", i + 1);
        scanf("%d", &var[i].existencia);
        getchar();
    
        printf("\n");
    }
}
void mostrarProductos(producto *var, int size) {
    int i;
    printf("Nombre del producto | Clave del producto | Cantidad\n");
    for(i = 0; i < size; i++) {
        printf("%s | %d | %d\n", var[i].nombre_producto, var[i].clave_producto, var[i].existencia);
    }
}
int verifExistenciaProducto(producto *var, int size, unsigned int num_prod) {
    int i;
    for(i = 0; i < size; i++) {
        if(num_prod == var[i].clave_producto) {
            return i;
        }
        else if(num_prod == 0) {
            return 0;
        }
    }
    return -1;
}
void ventaProducto(producto *var, int size, unsigned int key, int quant) {
    int i;
    for(i = 0; i < size; i++) {
        if(key == var[i].clave_producto) {
            var[i].existencia -= quant;
            break;
        }
    }
}
void compraProducto(producto *var, int size, unsigned int key, int quant) {
    int i;
    for(i = 0; i < size; i++) {
        if(key == var[i].clave_producto) {
            var[i].existencia += quant;
            break;
        }
    }
}