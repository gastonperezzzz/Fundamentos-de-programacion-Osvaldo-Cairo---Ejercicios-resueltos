// ALUMNO: PEREZ MERCADO GASTON EZEQUIEL
// CARRERA: LSI
// MATRICULA: ELSI1267

#include <stdio.h>

void calcular_costo(int, float, float *);

int main() {
    int horas = 40;
    float tarifa = 550.75;
    float costo_final = 0.0;

    printf("Costo final antes de usar la funcion: %.2f\n", costo_final);
    calcular_costo(horas, tarifa, &costo_final);
    printf("Costo final [ACTUALIZADO]: %.2f\n", costo_final);

    return 0;
}

void calcular_costo(int horas, float tarifa, float *costo_total_ptr) {
    *costo_total_ptr = horas * tarifa;
}