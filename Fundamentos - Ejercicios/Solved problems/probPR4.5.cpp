#include <stdio.h>

void rango_calificaciones(float num);

int range1 = 0;
int range2 = 0;
int range3 = 0;
int range4 = 0;
int range5 = 0;

int main() {
    float calificacion;

    do {
        printf("Ingrese la primera calificacion: ");
        scanf("%f", &calificacion);
        if(calificacion < 0 || calificacion > 10) {
            printf("Error: calificacion invalida.\n");
        }
    } while(calificacion < 0 || calificacion > 10);

    while(calificacion >= 0 && calificacion <= 10) {
        
        rango_calificaciones(calificacion);
        
        do {
            printf("Ingrese otra calificacion: ");
            scanf("%f", &calificacion);
            if(calificacion < -1 || calificacion > 10) {
                printf("Error: calificacion invalida.\n");
            }
        } while(calificacion < -1 || calificacion > 10);
    }

    printf("Calificaciones en el rango 1: %d\n", range1);
    printf("Calificaciones en el rango 2: %d\n", range2);
    printf("Calificaciones en el rango 3: %d\n", range3);
    printf("Calificaciones en el rango 4: %d\n", range4);
    printf("Calificaciones en el rango 5: %d\n", range5);

    return 0;
}

void rango_calificaciones(float num) {
    if(num >= 0 && num < 4) {
        range1++;
    }
    else if(num >= 4 && num < 6) {
        range2++;
    }
    else if(num >= 6 && num < 8) {
        range3++;
    }
    else if(num >= 8 && num < 9) {
        range4++;
    }
    else if(num >= 9 && num <= 10) {
        range5++;
    }
}