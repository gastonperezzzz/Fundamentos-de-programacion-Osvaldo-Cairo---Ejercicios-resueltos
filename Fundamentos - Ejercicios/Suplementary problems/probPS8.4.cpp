#include <stdio.h>
#include <string.h>

const int max_chars = 50;

// Declaracion de estructuras.
typedef struct {
    char calle_num[max_chars];
    char colonia[max_chars];
    char cod_postal[max_chars];
    char ciudad[max_chars];
    char telefono[max_chars];
} domicilio;

typedef struct {
    unsigned int num_empleado;
    char nom_ap[max_chars];
    char departamento[max_chars];
    domicilio casa;
    float salario_mensual;
    int estado = 0;
} empleado;

// Prototipos de funciones.
void deleteNewLine(char *); // Hecho
void lecturaEmpleados(empleado *, int); // Hecho
int verifExistenciaEmpleado(empleado *, int, unsigned int);
void empleadosAlta(empleado *, int); // Hecho
void empleadosBaja(empleado *, int); // Hecho
void empleadosDptoListado(empleado *, int); // Hecho

// Programa principal.
int main() {
    int numero_empleados;
    int option;

    do {
        printf("Ingrese la cantidad de empleados: ");
        scanf("%d", &numero_empleados);
        getchar();
        if(numero_empleados < 1 || numero_empleados > 100) {
            printf("Error: cantidad invalida.\n");
        }
    } while(numero_empleados < 1 || numero_empleados > 100);

    empleado emple[numero_empleados];
    lecturaEmpleados(emple, numero_empleados);

    do {
        do {
            printf("1. Dar de alta \n2. Dar de baja \n3. Listado por departamento \n4. Salir\n");
            scanf("%d", &option);
            getchar();
            if(option < 1 || option > 4) {
                printf("Error: opcion invalida.\n");
            }
        } while(option < 1 || option > 4);
        switch(option) {
            case 1:
                empleadosAlta(emple, numero_empleados);
                break;
            case 2:
                empleadosBaja(emple, numero_empleados);
                break;
            case 3:
                empleadosDptoListado(emple, numero_empleados);
                break;
        }
    } while(option != 4);


    return 0;
}

// Definiciones de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaEmpleados(empleado *var, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("Empleado [%d] | Nro. de empleado: ", i + 1);
        scanf("%d", &var[i].num_empleado);
        getchar();

        printf("Empleado [%d] | Nombre y apellido: ", i + 1);
        fgets(var[i].nom_ap, max_chars, stdin);
        deleteNewLine(var[i].nom_ap);
    
        printf("Empleado [%d] | Departamento: ", i + 1);
        fgets(var[i].departamento, max_chars, stdin);
        deleteNewLine(var[i].departamento);

        printf("Domicilio: \n");
        printf("\tEmpleado [%d] | Calle y numero: ", i + 1);
        fgets(var[i].casa.calle_num, max_chars, stdin);
        deleteNewLine(var[i].casa.calle_num);

        printf("\tEmpleado [%d] | Colonia: ", i + 1);
        fgets(var[i].casa.colonia, max_chars, stdin);
        deleteNewLine(var[i].casa.colonia);

        printf("\tEmpleado [%d] | Codigo postal: ", i + 1);
        fgets(var[i].casa.cod_postal, max_chars, stdin);
        deleteNewLine(var[i].casa.cod_postal);

        printf("\tEmpleado [%d] | Ciudad: ", i + 1);
        fgets(var[i].casa.ciudad, max_chars, stdin);
        deleteNewLine(var[i].casa.ciudad);

        printf("\tEmpleado [%d] | Telefono: ", i + 1);
        fgets(var[i].casa.telefono, max_chars, stdin);
        deleteNewLine(var[i].casa.telefono);

        printf("Empleado [%d] | Salario mensual: ", i + 1);
        scanf("%f", &var[i].salario_mensual);
        getchar();
    }
    printf("\n");
}
int verifExistenciaEmpleado(empleado *var, int size, unsigned int num_empleado) {
    int i;
    for(i = 0; i < size; i++) {
        if(var[i].num_empleado == num_empleado) {
            return 1;
        }
    }
    return 0;
}
void empleadosAlta(empleado *var, int size) {
    int i, i_empleado = 0;
    char option;
    unsigned int num_empleado;
    printf("Nro. empleado \t\tNombre y apellido \t\tEstado\n");
    for(i = 0; i < size; i++) {
        if(var[i].estado == 0) {
            printf("%d \t\t%s \t\t%s\n", var[i].num_empleado, var[i].nom_ap, "----");
        }
        else if(var[i].estado == 1) {
            printf("%d \t\t%s \t\t%s\n", var[i].num_empleado, var[i].nom_ap, "Alta");
        }
        else if(var[i].estado == 2) {
            printf("%d \t\t%s \t\t%s\n", var[i].num_empleado, var[i].nom_ap, "Baja");
        }
    }
    do {
        printf("Ingrese el numero de un empleado para darlo de alta: ");
        scanf("%d", &num_empleado);
        getchar();
        if(verifExistenciaEmpleado(var, size, num_empleado) == 0) {
            printf("Error: numero de empleado inexistente.\n");
        }
    } while(verifExistenciaEmpleado(var, size, num_empleado) == 0);

    for(i = 0; i < size; i++) {
        if(var[i].num_empleado == num_empleado) {
            i_empleado = i;
        }
    }

    do {
        printf("¿Desea dar de alta a %s (%d)? [S/N]:", var[i_empleado].nom_ap, var[i_empleado].num_empleado);
        option = getchar();
        if(option != 'S' && option != 's' && option != 'N' && option != 'n') {
            printf("Error: opcion invalida.\n");
        }
    } while(option != 'S' && option != 's' && option != 'N' && option != 'n');

    if(option == 'S' || option == 's') {
        var[i_empleado].estado = 1;
    }
}
void empleadosBaja(empleado *var, int size) {
    int i, i_empleado = 0;
    char option;
    unsigned int num_empleado;
    printf("Nro. empleado \t\tNombre y apellido \t\tEstado\n");
    for(i = 0; i < size; i++) {
        if(var[i].estado == 0) {
            printf("%d \t\t%s \t\t%s\n", var[i].num_empleado, var[i].nom_ap, "----");
        }
        else if(var[i].estado == 1) {
            printf("%d \t\t%s \t\t%s\n", var[i].num_empleado, var[i].nom_ap, "Alta");
        }
        else if(var[i].estado == 2) {
            printf("%d \t\t%s \t\t%s\n", var[i].num_empleado, var[i].nom_ap, "Baja");
        }
    }
    do {
        printf("Ingrese el numero de un empleado para darlo de baja: ");
        scanf("%d", &num_empleado);
        getchar();
        if(verifExistenciaEmpleado(var, size, num_empleado) == 0) {
            printf("Error: numero de empleado inexistente.\n");
        }
    } while(verifExistenciaEmpleado(var, size, num_empleado) == 0);

    for(i = 0; i < size; i++) {
        if(var[i].num_empleado == num_empleado) {
            i_empleado = i;
        }
    }

    do {
        printf("¿Desea dar de baja a %s (%d)? [S/N]:", var[i_empleado].nom_ap, var[i_empleado].num_empleado);
        option = getchar();
        if(option != 'S' && option != 's' && option != 'N' && option != 'n') {
            printf("Error: opcion invalida.\n");
        }
    } while(option != 'S' && option != 's' && option != 'N' && option != 'n');

    if(option == 'S' || option == 's') {
        var[i_empleado].estado = 2;
    }
}
void empleadosDptoListado(empleado *var, int size) {
    int i;
    char string[max_chars];
    printf("Ingrese un departamento de la empresa: ");
    fgets(string, max_chars, stdin);
    deleteNewLine(string);
    for(i = 0; i < size; i++) {
        if(!(strcmp(var[i].departamento, string))) {
            printf("%d | %s | %.2f\n", var[i].num_empleado, var[i].nom_ap, var[i].salario_mensual);
        }
    }
}