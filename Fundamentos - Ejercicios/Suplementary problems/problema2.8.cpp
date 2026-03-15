#include <stdio.h>

int main() {
    unsigned int cat, ant, res;

    printf("Ingrese la categoria del empleado: ");
    scanf("%d", &cat);

    printf("Ingrese la antiguedad del empleado: ");
    scanf("%d", &ant);

    switch (cat) {
        case 2: if (ant >= 7) {
            res = 1;
        }
        else {
            res = 0;
        }
        break;
        case 3:
        case 4: if (ant >= 5) {
            res = 1;
        }
        else {
            res = 0;
        }
        break;
        default: printf("La categoria ingresada no coincide con el puesto.");
        break;
    }
    if (res == 1) {
        printf("El trabajador de cat. %d y %d de antiguedad es apto para el puesto", cat, ant);
    }
    else {
        printf("El trabajador no reune los requisitos para el puesto.");
    }
}