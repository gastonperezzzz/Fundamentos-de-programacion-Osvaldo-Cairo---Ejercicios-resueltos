#include <stdio.h>

int main() {
    int treatment, age, day;
    float cost;

    printf("Ingrese el numero de tratamiento del paciente: ");
    scanf("%d", &treatment);
    
    printf("Ingrese la edad del paciente: ");
    scanf("%d", &age);

    printf("Ingrese el numero de dias de tratamiento: ");
    scanf("%d", &day);

    switch (treatment) {
        case 1:
            cost = 2800 * day;
            break;
        case 2:
            cost = 1950 * day;
            break;
        case 3:
            cost = 2500 * day;
            break;
        case 4: 
            cost = 1150 * day;
            break;
        default:
            printf("El tratamiento no coincide con el listado.\n");
            break;
    }
    if (age >= 60) {
        cost = (cost - (25.0 / 100 * cost));
        printf("El costo total del paciente es: %.3f", cost);
    }
    else if (age <= 25) {
        cost = (cost - (15.0 / 100 * cost));
        printf("El costo total del paciente es: %.3f", cost);
    }
    else {
        printf("El costo total del paciente es: %.3f", cost);
    }
}