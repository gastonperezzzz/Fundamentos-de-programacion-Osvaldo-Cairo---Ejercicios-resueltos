#include <stdio.h>

int main() {
    int med;
    float val, antval;

    printf("1) de pulgadas a milimeetros\n2) de yardas a metros\n3) millas a kilometros\n");
    printf("Ingrese el tipo de conversion que desea realizar [1/2/3]: ");
    scanf("%d", &med);

    printf("Ingrese el valor que desea convertir: ");
    scanf("%f", &val);

    antval = val;

    switch(med) {
        case 1:
            val *= 25.40;
            printf("%.3f pulgadas son %.3f milimetros", antval, val);
            break;
        case 2:
            val *= 0.9144;
            printf("%.3f yardas son %.3f metros", antval, val);
            break;
        case 3:
            val *= 1.6093;
            printf("%.3f millas son %.3f kilometros", antval, val);
            break;
        default:
            printf("El indice ingresado no coincide con las conversiones listadas");
            break;
    }
}