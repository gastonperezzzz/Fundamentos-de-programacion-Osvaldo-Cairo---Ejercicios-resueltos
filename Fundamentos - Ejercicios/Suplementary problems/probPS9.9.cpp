#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Constantes necesarias.
const int max_chars = 50;

// Declaracion de estructuras.
typedef struct {
    int clave;
    char nombre_producto[max_chars];
    int existencia;
    float precio;
} producto;

// Prototipos de funciones.
void deleteNewLine(char *);
void imprimirInventario(FILE *, int);
void ordenamientoProductosClave(FILE *, FILE *, int);
void ordenamientoArray(int *, int);
int verificarExistenciaProducto(FILE *, int, int);
void nuevosProductos(FILE *, int *);
void ventas(FILE *, int);
void reabastecimiento(FILE *, int);

// Programa principal.
int main() {
    FILE *apuntador = fopen("PS9.9 (com.dat).dat", "w+");
    FILE *apuntador_productos_ordenados = fopen("PS9.9 (com.dat1).dat", "w+");
    producto inventario;
    int option = 1;
    int cantidad_productos = 0;


    while(option == 1) {
        do {
            printf("Ingrese la clave del producto (0 para dejar de ingresar productos): ");
            scanf("%d", &inventario.clave);
            getchar();
            if(inventario.clave < 0) {
                printf("Error: clave invalida.\n");
            }
        } while(inventario.clave < 0);

        if(inventario.clave == 0) {
            break;
        }

        printf("Ingrese el nombre del producto: ");
        fgets(inventario.nombre_producto, max_chars, stdin);
        deleteNewLine(inventario.nombre_producto);

        do {
            printf("Ingrese la existencia del producto (cantidad): ");
            scanf("%d", &inventario.existencia);
            getchar();
            if(inventario.existencia < 0) {
                printf("Error: cantidad invalida.\n");
            }
        } while(inventario.existencia < 0);

        do {
            printf("Ingrese el precio del producto: ");
            scanf("%f", &inventario.precio);
            getchar();
            if(inventario.precio <= 0) {
                printf("Error: precio invalido.\n");
            }
        } while(inventario.precio <= 0);

        fwrite(&inventario, sizeof(producto), 1, apuntador);
        cantidad_productos++;
    }

    ordenamientoProductosClave(apuntador, apuntador_productos_ordenados, cantidad_productos);

    do {
        do {
            printf("Que accion desea realizar? \n1. Ventas \n2. Reabastecimiento \n3. Nuevos productos \n4. Imprimir inventario \n5. Salir \nOpcion: ");
            scanf("%d", &option);
            getchar();

            switch(option) {
                case 1:
                    ventas(apuntador_productos_ordenados, cantidad_productos);
                    break;
                case 2:
                    reabastecimiento(apuntador_productos_ordenados, cantidad_productos);
                    break;
                case 3:
                    nuevosProductos(apuntador, &cantidad_productos);
                    ordenamientoProductosClave(apuntador, apuntador_productos_ordenados, cantidad_productos);
                    break;
                case 4:
                    // ordenamientoProductosClave(apuntador, apuntador_productos_ordenados, cantidad_productos);
                    imprimirInventario(apuntador_productos_ordenados, cantidad_productos);
                    break;
            }
        } while(option < 1 || option > 5);
    } while(option != 5);

    return 0;
}

// Definiciones de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void nuevosProductos(FILE *pointer, int *size) {
    int option = 1;
    producto inventario;
    int flag;

    while(option == 1) {
        do {
            flag = 0;

            printf("Ingrese la clave del producto (0 para dejar de ingresar productos): ");
            scanf("%d", &inventario.clave);
            getchar();
            if(verificarExistenciaProducto(pointer, *size, inventario.clave)) {
                printf("Error: clave de producto existente.\n");
                flag = 1;
            }
            else if(inventario.clave < 0) {
                printf("Error: clave invalida.\n");
                flag = 1;
            }
        } while(flag == 1);

        if(inventario.clave == 0) {
            break;
        }

        *size += 1;

        printf("Ingrese el nombre del producto: ");
        fgets(inventario.nombre_producto, max_chars, stdin);
        deleteNewLine(inventario.nombre_producto);

        do {
            printf("Ingrese la existencia del producto (cantidad): ");
            scanf("%d", &inventario.existencia);
            getchar();
            if(inventario.existencia < 0) {
                printf("Error: cantidad invalida.\n");
            }
        } while(inventario.existencia < 0);

        do {
            printf("Ingrese el precio del producto: ");
            scanf("%f", &inventario.precio);
            getchar();
            if(inventario.precio <= 0) {
                printf("Error: precio invalido.\n");
            }
        } while(inventario.precio <= 0);

        fwrite(&inventario, sizeof(producto), 1, pointer);
    }
}
void imprimirInventario(FILE *pointer, int size) {
    int i;
    producto inventario;

    rewind(pointer);
    printf("Clave | Nombre | Existencia | Precio\n");
    for(i = 0; i < size; i++) {
        fread(&inventario, sizeof(producto), 1, pointer);
        printf("%d | %s | %d | %.2f\n", inventario.clave, inventario.nombre_producto, inventario.existencia, inventario.precio);
    }
}
void ordenamientoProductosClave(FILE *pointer_inv, FILE *pointer_newinv, int size) {
    int i, j;
    int claves[size];
    producto aux;

    rewind(pointer_inv);
    rewind(pointer_newinv);
    for(i = 0; i < size; i++) {
        fread(&aux, sizeof(producto), 1, pointer_inv);
        claves[i] = aux.clave;
    }
    ordenamientoArray(claves, size);
    for(i = 0; i < size; i++) {
        rewind(pointer_inv);
        for(j = 0; j < size; j++) {
            fread(&aux, sizeof(producto), 1, pointer_inv);
            if(aux.clave == claves[i]) {
                fwrite(&aux, sizeof(producto), 1, pointer_newinv);
            }
        }
    }
}
void ordenamientoArray(int *array, int size) {
    int i, j, aux;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            if(array[i] < array[j]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}
int verificarExistenciaProducto(FILE *pointer, int size, int key) {
    int i;
    producto aux;

    rewind(pointer);
    for(i = 0; i < size; i++) {
        fread(&aux, sizeof(producto), 1, pointer);
        if(aux.clave == key) {
            return 1;
        }
    }
    return 0;
}
void reabastecimiento(FILE *pointer, int size) {
    int i, clave_prod, reab, clave_i;
    producto inventario;

    rewind(pointer);
    printf("Clave | Nombre | Cantidad | Precio\n");
    for(i = 0; i < size; i++) {
        fread(&inventario, sizeof(producto), 1, pointer);
        printf("%d | %s | %d | %.2f\n", inventario.clave, inventario.nombre_producto, inventario.existencia, inventario.precio);
    }

    do {
        printf("Ingrese la clave del producto que desea reabastecer: ");
        scanf("%d", &clave_prod);
        getchar();
    } while(verificarExistenciaProducto(pointer, size, clave_prod) == 0);

    rewind(pointer);
    for(i = 0; i < size; i++) {
        fread(&inventario, sizeof(producto), 1, pointer);
        if(inventario.clave == clave_prod) {
            clave_i = i;
            break;
        }
    }

    fseek(pointer, clave_i * sizeof(producto), SEEK_SET);
    fread(&inventario, sizeof(producto), 1, pointer);

    do {
        printf("Ingrese la cantidad desea reabastecer: ");
        scanf("%d", &reab);
        getchar();
    } while(reab < 0);

    inventario.existencia += reab;

    fseek(pointer, clave_i * sizeof(producto), SEEK_SET);
    fwrite(&inventario, sizeof(producto), 1, pointer);
}
void ventas(FILE *pointer, int size) {
    int i, clave_prod, venta, diferencia, clave_i;
    producto inventario;

    rewind(pointer);
    printf("Clave | Nombre | Cantidad | Precio\n");
    for(i = 0; i < size; i++) {
        fread(&inventario, sizeof(producto), 1, pointer);
        printf("%d | %s | %d | %.2f\n", inventario.clave, inventario.nombre_producto, inventario.existencia, inventario.precio);
    }

    do {
        printf("Ingrese la clave del producto que desea vender: ");
        scanf("%d", &clave_prod);
        getchar();
    } while(verificarExistenciaProducto(pointer, size, clave_prod) == 0);

    rewind(pointer);
    for(i = 0; i < size; i++) {
        fread(&inventario, sizeof(producto), 1, pointer);
        if(inventario.clave == clave_prod) {
            clave_i = i;
            break;
        }
    }

    fseek(pointer, clave_i * sizeof(producto), SEEK_SET);
    fread(&inventario, sizeof(producto), 1, pointer);
    
    float total;

    do {
        printf("Ingrese la cantidad desea vender: ");
        scanf("%d", &venta);
        getchar();
        total = venta * inventario.precio;
        diferencia = inventario.existencia - venta;
        if(diferencia < 0) {
            printf("Error: cantidad a vender insuficiente");
        }
    } while(diferencia < 0);

    inventario.existencia -= venta;

    printf("Cantidad vendida %d | Total de la venta: %.2f\n", venta, total);

    fseek(pointer, clave_i * sizeof(producto), SEEK_SET);
    fwrite(&inventario, sizeof(producto), 1, pointer);
}