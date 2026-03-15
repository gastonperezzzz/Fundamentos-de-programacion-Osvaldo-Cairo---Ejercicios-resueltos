#include <stdio.h>

int main() {
    int loc, can, l1_bol = 0, l2_bol = 0, l3_bol = 0, l4_bol = 0, l5_bol = 0, l6_bol = 0;
    float l1, l2, l3, l4, l5, l6, rec_total = 0;
    float l1_monto = 0, l2_monto = 0, l3_monto = 0, l4_monto = 0, l5_monto = 0, l6_monto = 0;

    l1 = 50.5;
    l2 = 40.75;
    l3 = 35.60;
    l4 = 28.30;
    l5 = 20.45;
    l6 = 15.15;

    do {
        do {
            printf("Ingrese la localidad [1 - 6]: ");
            scanf("%d", &loc);

            printf("Ingrese la cantidad de boletos a comprar: ");
            scanf("%d", &can);
            if(loc < 0 || loc > 6) {
                printf("Error: numero invalido.\n");
            }
        } while ((loc < 0 || loc > 6) && can < 0);

        switch(loc) {
            case 1:
                l1_monto += (l1 * can);
                l1_bol += can;
                break;
            case 2:
                l2_monto += (l2 * can);
                l2_bol += can;
                break;
            case 3:
                l3_monto += (l3 * can);
                l3_bol += can;
                break;
            case 4:
                l4_monto += (l4 * can);
                l4_bol += can;
                break;
            case 5:
                l5_monto += (l5 * can);
                l5_bol += can;
                break;
            case 6:
                l6_monto += (l6 * can);
                l6_bol += can;
                break;
        }
    } while(loc != 0 && can != 0);

    rec_total = l1_monto + l2_monto + l3_monto + l4_monto + l5_monto + l6_monto;

    printf("Boletos vendidos y recaudacion total de las localidades:\n");
    printf("\tLoc 1: %d boletos con $%.2f\n\tLoc 2: %d boletos con $%.2f\n\tLoc 3: %d boletos con $%.2f\n", l1_bol, l1_monto, l2_bol, l2_monto,l3_bol, l3_monto);
    printf("\tLoc 4: %d boletos con $%.2f\n\tLoc 5: %d boletos con $%.2f\n\tLoc 6: %d boletos con $%.2f\n", l4_bol, l4_monto,l5_bol, l5_monto,l6_bol, l6_monto);
    printf("La recaudacion total del circo es: $%.2f\n", rec_total);
}