/*
Enunciado:
Escribir un programa de consola en el cual se realiza un gestor de transacciones para un banco.
Las transacciones constan de un codigo de operacion e importe.
El sistema debe ser capaz de crear, eliminar, buscar, mostrar por pantalla las transacciones generadas en tiempo de
ejecucion, ademas de, si el usuario desea, guardar las transacciones en un archivo binario.
*/

#include <stdio.h>
#include <stdlib.h>

struct nodoTransaccion {
    int codigo_transaccion;
    float importe;
    struct nodoTransaccion *sigue;
};

struct nodoTransaccion *inicio, *nuevo, *recorre, *aux;

void crearTransaccion(); // Listo
void buscarTransaccion(); // Listo
void eliminarTransaccion(); // Listo
void mostrarTransacciones(); // Listo
void guardarTransacciones();
void leerTransacciones();

int main() {
    inicio = NULL;
    int opcion;

    do {
        printf("\n-----Gestor de transacciones-----\n");
        printf("1. Agregar transaccion (insercion ordenada)\n");
        printf("2. Mostrar lista de transacciones\n");
        printf("3. Buscar transaccion (por cod. de transaccion)\n");
        printf("4. Eliminar transaccion (por cod. de transaccion)\n");
        printf("5. Guardar transacciones en un archivo.\n");
        printf("6. Leer las transacciones del archivo.\n");
        printf("0. Salir del programa\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                crearTransaccion();
                break;
            case 2:
                mostrarTransacciones();
                break;
            case 3:
                buscarTransaccion();
                break;
            case 4:
                eliminarTransaccion();
                break;
            case 5:
                guardarTransacciones();
                printf("Transacciones guardadas exitosamente.\n");
                break;
            case 6:
                leerTransacciones();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                // limpiarMemoria();
                break;
            default:
                printf("Error: Opcion invalida.\n");
                break;
        }

    } while(opcion != 0);

    return 0;
}

void crearTransaccion() {
    nuevo = (struct nodoTransaccion *) malloc(sizeof(struct nodoTransaccion));

    if(nuevo == NULL) {
        printf("Error de memoria. No se pudo crear el nodo.\n");
    }
    else {
        printf("Ingrese el codigo de transaccion: ");
        scanf("%d", &nuevo->codigo_transaccion);
        getchar();

        printf("Ingrese el importe de la transaccion: ");
        scanf("%f", &nuevo->importe);
        getchar();

        if(inicio == NULL || nuevo->codigo_transaccion <= inicio->codigo_transaccion) {
            nuevo->sigue = inicio;
            inicio = nuevo;
        }
        else {
            recorre = inicio;

            while(recorre->sigue != NULL && nuevo->codigo_transaccion >= recorre->sigue->codigo_transaccion) {
                recorre = recorre->sigue;
            }

            nuevo->sigue = recorre->sigue;
            recorre->sigue = nuevo;
        }
    }
}
void buscarTransaccion() {
    if(inicio == NULL) {
        printf("La lista esta vacia.\n");
    }
    else {
        int key;

        printf("Ingrese el codigo de la transaccion a buscar: ");
        scanf("%d", &key);
        getchar();

        recorre = inicio;

        while(recorre != NULL && recorre->codigo_transaccion != key) {
            recorre = recorre->sigue;
        }

        if(recorre == NULL) {
            printf("No se ha encontrado una transaccion coincidente.\n");
        }
        else {
            printf("Transaccion encontrada\n \t%d | %.2f\n", recorre->codigo_transaccion, recorre->importe);
        }
    }


}
void eliminarTransaccion() {
    if(inicio == NULL) {
        printf("La lista esta vacia.\n");
    }
    else {
        int key;

        printf("Ingrese el codigo de la transaccion a eliminar: ");
        scanf("%d", &key);
        getchar();

        // Verificamos si la transaccion a eliminar se encuentra al inicio de la lista.
        if(inicio->codigo_transaccion == key) {
            aux = inicio;
            inicio = inicio->sigue;
            free(aux);
            printf("Transaccion (codigo: %d) eliminada correctamente.\n", key);
        }
        else {
            recorre = inicio;

            while(recorre->sigue != NULL && recorre->sigue->codigo_transaccion != key) {
                recorre = recorre->sigue;
            }

            if(recorre == NULL) {
                printf("No se ha encontrado una transaccion coincidente con el codigo [%d]\n", key);
            }
            else {
                aux = recorre->sigue;
                recorre->sigue = recorre->sigue->sigue;
                free(aux);
                printf("Transaccion (codigo: %d) eliminada correctamente.\n", key);
            }
        }
    }
}
void mostrarTransacciones() {
    printf("\n-----Lista de transacciones-----\n");
    printf("Codigo de transaccion | Importe\n");
    recorre = inicio;
    while(recorre != NULL) {
        printf("%d | %.2f\n", recorre->codigo_transaccion, recorre->importe);
        recorre = recorre->sigue;
    }
    printf("-----------------------------------");
}
void guardarTransacciones() {
    FILE *pArchivo = fopen("transacciones.dat", "wb+");

    if(pArchivo == NULL) {
        printf("Error: no se ha podido abrir el archivo.\n");
        fclose(pArchivo);
    }
    else {
        // struct nodoTransaccion aux;

        recorre = inicio;

        while(recorre != NULL) {
            // aux.codigo_transaccion = recorre->codigo_transaccion;
            // aux.importe = recorre->importe;
            fwrite(recorre, sizeof(struct nodoTransaccion), 1, pArchivo);
            recorre = recorre->sigue;
        }
    }
    fclose(pArchivo);
}
void leerTransacciones() {
    FILE *pArchivo = fopen("transacciones.dat", "rb+");

    if(pArchivo == NULL) {
        printf("Error: no se ha podido abrir el archivo o es inexistente.\n");
        fclose(pArchivo);
    }
    else {
        struct nodoTransaccion aux;
        recorre = inicio;

        printf("\nTransacciones guardadas en el archivo.\n");
        printf("\tCod. de transaccion | Importe.\n");
        while(recorre != NULL) {
            fread(&aux, sizeof(struct nodoTransaccion), 1, pArchivo);
            printf("\t%d | %.2f\n", aux.codigo_transaccion, aux.importe);
            recorre = recorre->sigue;
        }
    }
    fclose(pArchivo);
}
