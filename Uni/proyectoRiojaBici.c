// ESTUDIANTE: PEREZ MERCADO GASTON EZEQUIEL, MATRICULA: ELSI1267, CARRERA: LICENCIATURA EN SISTEMAS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de una estaci�n de bicicletas
typedef struct {
    char nombre[50];
    float latitud;
    float longitud;
    int bicis_disponibles;
} Estacion;

// Carga una nueva estaci�n de bicicletas en el archivo
void cargarEstacion() {
    Estacion estacion;
    // Abrimos el archivo en modo anexar ("a") para no borrar los datos existentes
    FILE *archivo = fopen("estaciones.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    printf("Ingrese el nombre de la estacion: ");
    getchar(); // Limpia el buffer de entrada para evitar errores con fgets
    fgets(estacion.nombre, sizeof(estacion.nombre), stdin);
    estacion.nombre[strcspn(estacion.nombre, "\n")] = '\0'; // Elimina el salto de linea

    printf("Ingrese latitud: ");
    scanf("%f", &estacion.latitud);

    printf("Ingrese longitud: ");
    scanf("%f", &estacion.longitud);

    printf("Ingrese bicicletas disponibles: ");
    scanf("%d", &estacion.bicis_disponibles);

    // Escribimos los datos en el archivo separados por tabuladores
    fprintf(archivo, "%s\t%.3f\t%.3f\t%d\n", estacion.nombre, estacion.latitud, estacion.longitud, estacion.bicis_disponibles);
    fclose(archivo);

    printf("Estacion cargada exitosamente.\n");
}

// IMPLEMENTACION ARBITRARIA (la funcion fgets nos guarda un string con un salto de linea, esta funcion lo quita)
void borrarSaltoLinea(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}

// Muestra todas las estaciones del archivo y calcula el total de bicicletas
void mostrarEstacionesYTotalBicicletas() {
    // Abrimos el archivo en modo lectura ("r")
    FILE *archivo = fopen("estaciones.txt", "r");
    if (archivo == NULL) {
        printf("No hay estaciones cargadas todavia.\n");
        return;
    }

    Estacion estacion;
    int totalBicicletas = 0;

    printf("\nLista de estaciones:\n");
    // Leemos los datos del archivo usando fscanf()
    while (fscanf(archivo, "%49[^\t]\t%f\t%f\t%d\n",estacion.nombre, &estacion.latitud, &estacion.longitud, &estacion.bicis_disponibles) == 4) {
        printf("Estacion: %s, Latitud: %.3f, Longitud: %.3f, Bicicletas disponibles: %d\n",estacion.nombre, estacion.latitud, estacion.longitud, estacion.bicis_disponibles);
        totalBicicletas += estacion.bicis_disponibles;
    }

    fclose(archivo);

    printf("\nTotal de bicicletas disponibles en todas las estaciones: %d\n", totalBicicletas);
}

// Funcion que permite realizar la busqueda de una estacion por su nombre.
void buscarEstacion(void) {
    int flag = 0;
    Estacion estacion;
    FILE *archivo;
    char nombreEstacion[50];
    char estacionCoincidente[50];

    archivo = fopen("estaciones.txt", "r");
    rewind(archivo);

    if(archivo == NULL) {
        printf("No se ha podido abrir el archivo.\n");
        fclose(archivo);
    }
    else {
        printf("Ingrese el nombre de la estacion: ");
        fgets(nombreEstacion, 50, stdin);
        borrarSaltoLinea(nombreEstacion);

        while(fscanf(archivo, "%s", estacionCoincidente) == 1) {
            if(strcmp(nombreEstacion, estacionCoincidente) == 0) {
                fscanf(archivo, "%f", &estacion.latitud);
                fscanf(archivo, "%f", &estacion.longitud);
                fscanf(archivo, "%d", &estacion.bicis_disponibles);
                printf("Busqueda exitosa...\n");
                printf("Nombre: %s | Lat. | %f | Long. %f | Bicicletas disponibles: %d", nombreEstacion, estacion.latitud, estacion.longitud, estacion.bicis_disponibles);
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("No se ha podido encontrar la estacion '%s'.\n", nombreEstacion);
            fclose(archivo);
        }
    }
}

// Funcion principal que muestra un menu de opciones al usuario
void menu() {
    int opcion;

    do {
        printf("\nBienvenido al sistema de gestion de bicicletas, seleccione una opcion:\n");
        printf("1. Cargar nueva estacion\n");
        printf("2. Listar estaciones y total de bicicletas\n");
        printf("3. Buscar estacion por nombre.\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1:
                cargarEstacion();
                break;
            case 2:
                mostrarEstacionesYTotalBicicletas();
                break;
            case 3:
                buscarEstacion();
                break;
            case 4:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while (opcion != 4);
}

int main() {
    menu();
    return 0;
}

