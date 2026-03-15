#include <stdio.h>

int main() {
    unsigned int key;
    float cost, call;

    printf("1) EEUU\n2) Canada\n5) Sudamerica\n6) Centroamerica\n7) Mexico");
    printf("\n9) Europa\n10) Asia\n15) Africa\n20) Oceania\n");

    printf("Ingrese la clave [zona geografica]: ");
    scanf("%d", &key);

    printf("Ingrese la duracion de la llamada [en minutos]: ");
    scanf("%f", &call);

    switch (key) {
        case 1:
            cost = 0.13 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 2: 
            cost = 0.11 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 5:
             cost = 0.22 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 6:
             cost = 0.19 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 7:
             cost = 0.17 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 9:
             cost = 0.17 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 10:
             cost = 0.20 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 15:
             cost = 0.39 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        case 20:
             cost = 0.28 * call;
            printf("El costo de la llamada es: %.3f", cost);
            break;
        default:
            printf("La clave no corresponde a la lista.");
            break;
    }
}