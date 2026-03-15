#include <stdio.h>
#include <string.h>

const int max_chars = 50;

// Declaracion de estructuras.
typedef struct {
    char calle_numero[max_chars];
    char cod_postal[max_chars];
    char colonia[max_chars];
    char ciudad[max_chars];
    char telefono[max_chars];
} domicilio;

typedef struct {
    long int num_cuenta;
    char nom_cliente[max_chars];
    domicilio domicilio_cliente;
    float saldo;
} cliente;

// Prototipo de funciones.
void deleteNewLine(char *); // Hecho
void lecturaClientes(cliente *, int); // Hecho
int verificarNumCuenta(cliente *, int, long int); // Hecho
void funcionDeposito(cliente *, int); // Hecho
void funcionRetiro(cliente *, int);

// Programa principal.
int main() {
    int numero_clientes;
    unsigned int option;

    do {
        printf("Ingrese la cantidad de clientes del banco: ");
        scanf("%d", &numero_clientes);
        getchar();
        if(numero_clientes < 1 || numero_clientes > 100) {
            printf("Error: cantidad invalida.\n");
        }
    } while(numero_clientes < 1 || numero_clientes > 100);

    cliente banco[numero_clientes];
    lecturaClientes(banco, numero_clientes);
    
        do {
            printf("1. Depositar \n2. Retirar \n3.Salir\n");
            do {
                printf("Ingrese una opcion: ");
                scanf("%d", &option);
                getchar();
                if(option < 1 || option > 3) {
                    printf("Error: opcion invalida.\n");
                }
            } while(option < 1 || option > 3);
        switch(option) {
            case 1:
                funcionDeposito(banco, numero_clientes);
                break;
            case 2:
                funcionRetiro(banco, numero_clientes);
                break;
            case 3:
                printf("Muchas gracias por confiar en nosotros. Hasta luego.\n");
                break;
        }
    } while(option != 3);

    return 0;
}

// Definiciones de funciones.
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaClientes(cliente *var, int size) {
    int i;
    printf("Ingrese los datos de los clientes:\n");
    for(i = 0; i < size; i++) {
        printf("Cliente [%d] | Numero de cuenta: ", i + 1);
        scanf("%ld", &var[i].num_cuenta);
        getchar();

        printf("Cliente [%d] | Nombre del cliente: ", i + 1);
        fgets(var[i].nom_cliente, max_chars, stdin);
        deleteNewLine(var[i].nom_cliente);

        printf("Domicilio:\n");

        printf("\tCliente [%d] | Calle y numero: ", i + 1);
        fgets(var[i].domicilio_cliente.calle_numero, max_chars, stdin);
        deleteNewLine(var[i].domicilio_cliente.calle_numero);

        printf("\tCliente [%d] | Codigo postal: ", i + 1);
        fgets(var[i].domicilio_cliente.cod_postal, max_chars, stdin);
        deleteNewLine(var[i].domicilio_cliente.cod_postal);

        printf("\tCliente [%d] | Colonia: ", i + 1);
        fgets(var[i].domicilio_cliente.colonia, max_chars, stdin);
        deleteNewLine(var[i].domicilio_cliente.colonia);
    
        printf("\tCliente [%d] | Ciudad: ", i + 1);
        fgets(var[i].domicilio_cliente.ciudad, max_chars, stdin);
        deleteNewLine(var[i].domicilio_cliente.ciudad);

        printf("\tCliente [%d] | Telefono: ", i + 1);
        fgets(var[i].domicilio_cliente.telefono, max_chars, stdin);
        deleteNewLine(var[i].domicilio_cliente.telefono);

        printf("Cliente [%d] | Saldo: ", i + 1);
        scanf("%f", &var[i].saldo);
        getchar();

        printf("\n");
    }
}
int verificarNumCuenta(cliente *var, int size, long int num_acc) {
    int i;
    for(i = 0; i < size; i++) {
        if(var[i].num_cuenta == num_acc) {
            return 1;
        }
    }

    return 0;
}
void funcionDeposito(cliente *var, int size) {
    int i, ind_cliente = 0;
    long int num_acc;
    float monto;
    printf("DEPOSITOS \nNombre del cliente \t\tNro. de cuenta\n");
    for(i = 0; i < size; i++) {
        printf("%s \t\t%ld\n", var[i].nom_cliente, var[i].num_cuenta);
    }

    do {
        printf("Ingrese su numero de cuenta: ");
        scanf("%ld", &num_acc);
        getchar();
        if(verificarNumCuenta(var, size, num_acc) == 0) {
            printf("Error: numero de cuenta inexistente.\n");
        }
    } while(verificarNumCuenta(var, size, num_acc) == 0);

    do {
        printf("Ingrese el monto a depositar [1 hasta 50000]: ");
        scanf("%f", &monto);
        getchar();
        if(monto <= 0.0 || monto >= 50000.0) {
            printf("Error: monto ingresado invalido.\n");
        }
    } while(monto <= 0.0 || monto >= 50000.0);

    for(i = 0; i < size; i++) {
        if(var[i].num_cuenta == num_acc) {
            var[i].saldo += monto;
            ind_cliente = i;
            break;
        }
    }

    printf("SALDO ACTUALIZADO \nNombre del cliente \t\tNro. de cuenta \t\tNuevo saldo \n");
    printf("%s \t\t%ld \t\t%.2f\n", var[ind_cliente].nom_cliente, var[ind_cliente].num_cuenta, var[ind_cliente].saldo);
}
void funcionRetiro(cliente *var, int size) {
    int i, ind_cliente = 0;
    long int num_acc;
    float monto;
    printf("RETIROS \nNombre del cliente \t\tNro. de cuenta\n");
    for(i = 0; i < size; i++) {
        printf("%s \t\t%ld\n", var[i].nom_cliente, var[i].num_cuenta);
    }

    do {
        printf("Ingrese su numero de cuenta: ");
        scanf("%ld", &num_acc);
        getchar();
        if(verificarNumCuenta(var, size, num_acc) == 0) {
            printf("Error: numero de cuenta inexistente.\n");
        }
    } while(verificarNumCuenta(var, size, num_acc) == 0);

    for(i = 0; i < size; i++) {
        if(var[i].num_cuenta == num_acc) {
            ind_cliente = i;
            break;
        }
    }

    do {
        printf("Ingrese el monto a retirar: ");
        scanf("%f", &monto);
        getchar();
        if(monto <= 0.0) {
            printf("Error: monto ingresado invalido.\n");
        }
        else if(monto > var[ind_cliente].saldo) {
            printf("Error: monto excedente del saldo actual disponible.\n");
        }
    } while(monto <= 0.0 || monto > var[ind_cliente].saldo);

    var[ind_cliente].saldo -= monto;

    printf("SALDO ACTUALIZADO \nNombre del cliente \t\tNro. de cuenta \t\tNuevo saldo \n");
    printf("%s \t\t%ld \t\t%.2f\n", var[ind_cliente].nom_cliente, var[ind_cliente].num_cuenta, var[ind_cliente].saldo);
}