#include <stdio.h>

int num_int_input(int num);
int sum_numbers(int a, int b);
int rest_numbers(int a, int b);
int mult_numbers(int a, int b);
float div_numbers(int a, int b);

int main() {
    int n1, n2, option;

    do {
        do {
            printf("Que operacion desea hacer: ");
            printf("\n1) Sumar.\n2) Restar.\n3) Multiplicar.\n4) Dividir.\n5) Salir.");
            printf("\nOpcion: ");
            scanf("%d", &option);
            if(option <= 0 || option > 5) {
                printf("Error: opcion invalida.\n");
            }
        } while(option <= 0 || option > 5);

        switch(option) {
            case 1:
                n1 = num_int_input(n1);
                n2 = num_int_input(n2);
                printf("La suma de los numeros es: %d\n", sum_numbers(n1, n2));
                break;
            case 2:
                n1 = num_int_input(n1);
                n2 = num_int_input(n2);
                printf("La resta de los numeros es: %d\n", rest_numbers(n1, n2));
                break;
            case 3:
                n1 = num_int_input(n1);
                n2 = num_int_input(n2);
                printf("El producto de los numeros es: %d\n", mult_numbers(n1, n2));
                break;
            case 4:
                n1 = num_int_input(n1);
                n2 = num_int_input(n2);
                printf("El cociente de los numeros es: %.2f\n", div_numbers(n1, n2));
                break;
        }
    } while(option != 5);
}

int num_int_input(int num) {
    do {
        printf("Ingrese un numero positivo: ");
        scanf("%d", &num);
        if(num <= 0) {
            printf("Error: numero negativo o nulo.\n");
        }
    } while(num <= 0);

    return num;
}
int sum_numbers(int a, int b) {
    return(a + b);
}
int rest_numbers(int a, int b) {
    return(a - b);
}
int mult_numbers(int a, int b) {
    return(a * b);
}
float div_numbers(int a, int b) {
    return((float)a / b);
}