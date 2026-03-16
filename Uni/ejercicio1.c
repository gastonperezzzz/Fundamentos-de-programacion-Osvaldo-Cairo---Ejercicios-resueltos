// ALUMNO: PEREZ MERCADO GASTON EZEQUIEL
// CARRERA: LSI
// MATRICULA: ELSI1267

#include <stdio.h>

void calibrar_nivel(float *, float);

int main() {
    float nivel_inicial = 95.5;
    float error_calibracion = 2.1;

    printf("Nivel actual del tanque: %.2f\n\n", nivel_inicial);
    calibrar_nivel(&nivel_inicial, error_calibracion);

    printf("Nivel actual despues de aplicar la funcion: %.2f\n", nivel_inicial);

    return 0;
}

void calibrar_nivel(float *nivel_actual_ptr, float error_calibracion) {
    *nivel_actual_ptr = *nivel_actual_ptr - error_calibracion;
}