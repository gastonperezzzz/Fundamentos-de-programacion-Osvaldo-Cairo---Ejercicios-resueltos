#include <stdio.h>
#define MES 3

void mayor_prom(float, float, float, int *);

int main() {
    int reg_indice;
    float prom_mensual;
    float prom_anual_gol = 0, prom_anual_pac = 0, prom_anual_car = 0;

    for(int i = 1; i <= MES; i++) {
        do {
            printf("Ingrese el promedio de lluvia del 'Golfo' del mes [%d]: ", i);
            scanf("%f", &prom_mensual);
            if(prom_mensual <= 0) {
                printf("Error: entrada invalida.\n");
            }
        } while (prom_mensual <= 0);

        prom_anual_gol += prom_mensual;

        do {
            printf("Ingrese el promedio mensual del 'Pacifico' del mes [%d]: ", i);
            scanf("%f", &prom_mensual);
            if(prom_mensual <= 0) {
                printf("Error: entrada invalida.\n");
            }
        } while(prom_mensual <= 0);

        prom_anual_pac += prom_mensual;

        do {
            printf("Ingrese el promedio mensual del 'Caribe' del mes [%d]: ", i);
            scanf("%f", &prom_mensual);
            if(prom_mensual <= 0) {
                printf("Error: entrada invalida.\n");
            }
        } while(prom_mensual <= 0);

        prom_anual_car += prom_mensual;
    }

    prom_anual_gol = prom_anual_gol / MES;
    prom_anual_pac = prom_anual_pac / MES;
    prom_anual_car = prom_anual_car / MES;

    mayor_prom(prom_anual_gol, prom_anual_pac, prom_anual_car, &reg_indice);

    printf("El promedio anual del la region 'Golfo' es: %.2f\n", prom_anual_gol);
    printf("El promedio anual del la region 'Pacifico' es: %.2f\n", prom_anual_pac);
    printf("El promedio anual del la region 'Caribe' es: %.2f\n", prom_anual_car);
    
    if(reg_indice == 1) {
        printf("La region 'Golfo' es la de mayor promedio.\n");
    }
    else if(reg_indice == 2) {
        printf("La region 'Pacifico' es la de mayor promedio.\n");
    }
    else {
        printf("La region 'Caribe' es la de mayor promedio.\n");
    }

    return 0;
}

void mayor_prom(float reg1, float reg2, float reg3, int *reg_ind) {
    if(reg1 > reg2 && reg1 > reg3) {
        *reg_ind = 1;
    }
    else if(reg2 > reg1 && reg2 > reg3) {
        *reg_ind = 2;
    }
    else {
        *reg_ind = 3;
    }
}

