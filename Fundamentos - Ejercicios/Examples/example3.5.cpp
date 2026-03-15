#include <stdio.h>

int main() {
    float sal, nom, prom;
    int i = 0;

    do {
        printf("Ingrese el salario del profesor [%d]: ", i);
        scanf("%f", &sal);

        nom += sal;
        i++;
    } while(sal != 0);
    prom = nom / (i - 1);
    printf("La nomina del salario de los profesores es: %.2f\n", nom);
    printf("El promedio del salario es: %.2f", prom);
}