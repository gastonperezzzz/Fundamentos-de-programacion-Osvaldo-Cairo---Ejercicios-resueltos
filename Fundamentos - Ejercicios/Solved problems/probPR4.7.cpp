#include <stdio.h>

float promedio_temp(float num);
void temperatura_max(float a, int b);
void temperatura_min(float a, int b);

float temp_acu = 0, temp_max = 0, temp_min = 100;
int hmax, hmin;

int main() {
    float temp;
    int i;

    for(i = 1; i <= 24; i++) {
        do {
            printf("Ingrese la temperatura de la hora [%d:00]: ", i);
            scanf("%f", &temp);
            if(temp < -10 || temp > 60) {
                printf("Error: temperatura invalida.\n");
            }
        } while(temp < -10 || temp > 60);
        temp_acu += temp;
        temperatura_max(temp, i);
        temperatura_min(temp, i);
    }

    printf("El promedio de la temperatura del dia es: %.2f\n", promedio_temp(temp_acu));
    printf("La mayor temperatura registrada fue %.2f a las [%d:00].\n", temp_max, hmax);
    printf("La menor temperatura registrada fue %.2f a las [%d:00].\n", temp_min, hmin);

    return 0;
}

float promedio_temp(float num) {
    float prom;
    prom = num / 24;
    return prom;
}
void temperatura_max(float a, int b) {
    if(a > temp_max) {
        temp_max = a;
        hmax = b;
    }
}
void temperatura_min(float a, int b) {
    if(a < temp_min) {
        temp_min = a;
        hmin = b;
    }
}
