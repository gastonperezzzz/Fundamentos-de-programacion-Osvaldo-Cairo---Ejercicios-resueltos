#include <stdio.h>
#define mes 2

int main() {
    int zona_temp_menor, zona_temp_mayor, reg_mayor_prom, mes_mayor_temp, mes_menor_temp;
    float nor, cen, sur, gol, pac, car;
    float temp_menor = 200, temp_mayor = 0;
    float prom_nor = 0, prom_cen = 0, prom_sur = 0, prom_gol = 0, prom_pac = 0, prom_car = 0;

    for(int i = 1; i <= mes; i++) {
        printf("Ingrese la temperatura de la region 'Norte' [%d]: ", i);
        scanf("%f", &nor);
    
        printf("Ingrese la temperatura de la region 'Centro' [%d]: ", i);
        scanf("%f", &cen);

        printf("Ingrese la temperatura de la region 'Sur' [%d]: ", i);
        scanf("%f", &sur);

        printf("Ingrese la temperatura de la region 'Golfo' [%d]: ", i);
        scanf("%f", &gol);

        printf("Ingrese la temperatura de la region del 'Pacifico' [%d]: ", i);
        scanf("%f", &pac);

        printf("Ingrese la temperatura de la region del 'Caribe' [%d]: ", i);
        scanf("%f", &car);

        prom_nor += nor;
        prom_cen += cen;
        prom_sur += sur;
        prom_gol += gol;
        prom_pac += pac;
        prom_car += car;

        // DETERMINAR TEMPERATURA MENOR Y ZONA.
        if(nor > temp_mayor) {
            temp_mayor = nor;
            zona_temp_mayor = 1;
            mes_mayor_temp = i;
        }
        if(cen > temp_mayor) {
            temp_mayor = cen; 
            zona_temp_mayor = 2;
            mes_mayor_temp = i;
        }
        if(sur > temp_mayor) {
            temp_mayor = sur;
            zona_temp_mayor = 3;
            mes_mayor_temp = i;
        }
        if(gol > temp_mayor) {
            temp_mayor = gol;
            zona_temp_mayor = 4;
            mes_mayor_temp = i;
        }
        if(pac > temp_mayor) {
            temp_mayor = pac;
            zona_temp_mayor = 5;
            mes_mayor_temp = i;
        }
        if(car > temp_mayor) {
            temp_mayor = car;
            zona_temp_mayor = 6;
            mes_mayor_temp = i;
        }

        // DETERMINAR TEMPERATURA MENOR Y ZONA.
        if(nor < temp_menor) {
            temp_menor = nor;
            zona_temp_menor = 1;
            mes_menor_temp = i;
        }
        if(cen < temp_menor) {
            temp_menor = cen; 
            zona_temp_menor = 2;
            mes_menor_temp = i;
        }
        if(sur < temp_menor) {
            temp_menor = sur;
            zona_temp_menor = 3;
            mes_menor_temp = i;
        }
        if(gol < temp_menor) {
            temp_menor = gol;
            zona_temp_menor = 4;
            mes_menor_temp = i;
        }
        if(pac < temp_menor) {
            temp_menor = pac;
            zona_temp_menor = 5;
            mes_menor_temp = i;
        }
        if(car < temp_menor) {
            temp_menor = car;
            zona_temp_menor = 6;
            mes_menor_temp = i;
        }
    }
    // PROMEDIO.
    prom_nor = prom_nor / mes;
    prom_cen = prom_cen / mes;
    prom_sur = prom_sur / mes;
    prom_gol = prom_gol / mes;
    prom_pac = prom_pac / mes;
    prom_car = prom_car / mes;

    // DETERMINAR CUAL REG. DE SUR, PAC, CAR TIENE > PROMEDIO.
    if(sur > pac && sur > car) {
        reg_mayor_prom = 3;
    }
    else if(pac > sur && pac > car) {
        reg_mayor_prom = 5;
    }
    else {
        reg_mayor_prom = 6;
    }

    // IMPRIMIR PROMEDIO ANUAL.
    printf("Promedio anual de cada region:\n");
    printf("\tNorte: %.2f\n\tCentro: %.2f\n\tSur: %.2f\n\tGolfo: %.2f\n\tPacifico: %.2f\n\tCaribe: %.2f\n", prom_nor, prom_cen, prom_sur, prom_gol, prom_pac, prom_car);
    
    // IMPRIMIR MES, REGISTRO DE MAYOR TEMP Y ZONA PERTENECIENTE.
    if(zona_temp_mayor == 1) {
        printf("El mes nro %d tiene mayor temperatura, con %.2f perteneciente al Norte.\n", mes_mayor_temp, temp_mayor);
    }
    else if(zona_temp_mayor == 2) {
        printf("El mes nro %d tiene mayor temperatura, con %.2f perteneciente al Centro.\n", mes_mayor_temp, temp_mayor);
    }
    else if(zona_temp_mayor == 3) {
        printf("El mes nro %d tiene mayor temperatura, con %.2f perteneciente al Sur.\n", mes_mayor_temp, temp_mayor);
    }
    else if(zona_temp_mayor == 4) {
        printf("El mes nro %d tiene mayor temperatura, con %.2f perteneciente al Golfo.\n", mes_mayor_temp, temp_mayor);
    }
    else if(zona_temp_mayor ==5) {
        printf("El mes nro %d tiene mayor temperatura, con %.2f perteneciente al Pacifico.\n", mes_mayor_temp, temp_mayor);
    }
    else if(zona_temp_mayor == 6) {
        printf("El mes nro %d tiene mayor temperatura, con %.2f perteneciente al Caribe.\n", mes_mayor_temp, temp_mayor);
    }

    // IMPRIMIR MES, REGISTRO DE MENOR TEMP Y ZONA PERTENECIENTE.
    if(zona_temp_menor == 1) {
        printf("El mes nro %d tiene menor temperatura, con %.2f perteneciente al Norte.\n", mes_menor_temp, temp_menor);
    }
    else if(zona_temp_menor == 2) {
        printf("El mes nro %d tiene menor temperatura, con %.2f perteneciente al Centro.\n", mes_menor_temp, temp_menor);
    }
    else if(zona_temp_menor == 3) {
        printf("El mes nro %d tiene menor temperatura, con %.2f perteneciente al Sur.\n", mes_menor_temp, temp_menor);
    }
    else if(zona_temp_menor == 4) {
        printf("El mes nro %d tiene menor temperatura, con %.2f perteneciente al Golfo.\n", mes_menor_temp, temp_menor);
    }
    else if(zona_temp_menor ==5) {
        printf("El mes nro %d tiene menor temperatura, con %.2f perteneciente al Pacifico.\n", mes_menor_temp, temp_menor);
    }
    else if(zona_temp_menor == 6) {
        printf("El mes nro %d tiene menor temperatura, con %.2f perteneciente al Caribe.\n", mes_menor_temp, temp_menor);
    }

    // IMPRIMIR REGION (SUR, PAC, CAR) CON MAYOR PROMEDIO.
    if(reg_mayor_prom == 3) {
        printf("La region Sur con %.2f tiene el mayor promedio entre (SUR, PAC, CAR).\n", prom_sur);
    }
    else if(reg_mayor_prom == 5) {
        printf("La region Pacifico con %.2f tiene el mayor promedio entre (SUR, PAC, CAR).\n", prom_pac);
    }
    else if(reg_mayor_prom == 6) {
        printf("La region Caribe con %.2f tiene el mayor promedio entre (SUR, PAC, CAR).\n", prom_car);
    }
}