#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int codigo;
    float precio;
    struct Nodo *sigue;
};

struct Nodo *inicio, *recorre, *nuevo, *aux;

void agregarArticulo(int, float);
// void insertarArticulo(int, float);
void mostrarLista();
void buscarArticulo(int);
int eliminarArticulo(int);

int main() {
    inicio = NULL;
    int codigo;
    float precio;
    int opcion;

    do {
        printf("Menu de opciones:\n");
        printf("1. Agregar articulo\n");
        printf("2. Mostrar lista de articulos\n");
        printf("3. Buscar articulo por codigo\n");
        printf("4. Eliminar articulo por codigo\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese el codigo del articulo: ");
                scanf("%d", &codigo);
                getchar(); // Limpiar el buffer
                printf("Ingrese el precio del articulo: ");
                scanf("%f", &precio);
                getchar(); // Limpiar el buffer
                agregarArticulo(codigo, precio);
                break;
            case 2:
                mostrarLista();
                break;
            case 3:
                printf("Ingrese el codigo del articulo a buscar: ");
                scanf("%d", &codigo);
                buscarArticulo(codigo);
                break;
            case 4:
                printf("Ingrese el codigo del articulo a eliminar: ");
                scanf("%d", &codigo);
                if(!eliminarArticulo(codigo)) {
                    printf("No se encontro el articulo con codigo %d.\n", codigo);
                }
                break;
            case 5:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 5);


    return 0;
}

void agregarArticulo(int code, float price) {
    nuevo = malloc(sizeof(struct Nodo));
    nuevo->codigo = code;
    nuevo->precio = price;
    nuevo->sigue = inicio;
    inicio = nuevo;

    printf("Articulo ingresado correctamente.\n");
}

void mostrarLista() {
    recorre = inicio;

    printf("-------------------------\nLISTA\n\n");

    while(recorre != NULL) {
        printf("Codigo: %d\n", recorre->codigo);
        printf("Precio: %.2f\n\n", recorre->precio);
        recorre = recorre->sigue;
    }

    printf("Final de lista\n-------------------------\n");
}

void buscarArticulo(int code) {
    recorre = inicio;

    while(recorre != NULL) {
        if(recorre->codigo == code) {
            printf("Articulo encontrado exitosamente. Descripcion: \n");
            printf("\tCodigo | %d \n \tPrecio: %.2f\n", recorre->codigo, recorre->precio);
            break;
        }
        else {
            recorre = recorre->sigue;
        }
    }

    if(recorre == NULL) {
        printf("No se ha podido encontrar el articulo o la lista esta vacia.\n");
    }
}

int eliminarArticulo(int code) {

    // Verificar si la lista esta vacia.
    if(inicio == NULL) {
        printf("La lista esta vacia.\n");
        return 0;
    }
    // Si el elemento a eliminar esta al principio.
    else if(inicio->codigo == code) {
        aux = inicio;
        inicio = inicio->sigue;
        free(aux);
        printf("Elemento eliminado correctamente.\n");
        return 1;
    }

    recorre = inicio;

    // Recorremos la lista hasta encontrar el elemento en cuestion.
    while((recorre->sigue != NULL) && (recorre->sigue->codigo != code)) {
        recorre = recorre->sigue;
    }

    if((recorre->sigue)->codigo == code) {
        aux = recorre->sigue;
        recorre->sigue = recorre->sigue->sigue;
        free(aux);
        printf("Elemento eliminado correctamente.\n");
        return 1;
    }
    return 0;
}
