#include <stdio.h>
#include <string.h>

// Estructura para almacenar los datos.
typedef struct {
    char nombre[50];
    float latitud, longitud;
    int cantidad_bicicletas;
} Estacion;

// Prototipo de funciones.
void deleteNewLine(char *);
void cargarEstacion(FILE *, Estacion);
void listarEstaciones(FILE *, Estacion);

// Programa principal.
int main() {
    FILE *apuntador;
    int opcion;
    Estacion estacion;

    apuntador = fopen("RiojaBici", "rb+");

    if(apuntador == NULL) {
        printf("Error: no se ha podido abrir el archivo.\n");
        fclose(apuntador);
    }
    else {
        do {
            printf("BIENVENIDO AL SISTEMA DE RIOJA BICI\n");
            printf("1. Agregar estacion.\n");
            printf("2. Listar estaciones y total de bicicletas.\n");
            printf("3. Salir.\n");
            printf("Opcion: ");
            scanf("%d", &opcion);
            getchar();

            switch(opcion) {
                case 1:
                    cargarEstacion(apuntador, estacion);
                    break;
                case 2:
                    listarEstaciones(apuntador, estacion);
                    break;
                case 3:
                    fclose(apuntador);
                    printf("Saliendo del programa.\n");
                    break;
                default:
                    printf("Opcion invalida. Vuelva a intentar.\n");
                    fclose(apuntador);
            }
        } while(opcion != 3);

    }

    return 0;
}

// Definicion de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void cargarEstacion(FILE *pointer, Estacion var) {
    printf("Ingrese el nombre de la estacion: ");
    fgets(var.nombre, 50, stdin);
    deleteNewLine(var.nombre);

    printf("Ubicacion - Longitud: ");
    scanf("%f", &var.longitud);
    getchar();

    printf("Ubicacion - Latitud: ");
    scanf("%f", &var.latitud);
    getchar();

    printf("Ingrese la cantidad de bicicletas disponibles: ");
    scanf("%d", &var.cantidad_bicicletas);
    getchar();

    fwrite(&var, sizeof(Estacion), 1, pointer);
}
void listarEstaciones(FILE *pointer, Estacion var) {
    rewind(pointer);

    while (fread(&var, sizeof(Estacion), 1, pointer) == 1) {
        printf("Nombre de la estacion: %s\n", var.nombre);
        printf("Ubicacion - Latitud: %f\n", var.latitud);
        printf("Ubicacion - Longitud: %f\n", var.longitud);
        printf("Cantidad de bicicletas disponibles: %d\n", var.cantidad_bicicletas);
    }
}
