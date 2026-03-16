// ALUMNO: PEREZ MERCADO GASTON EZEQUIEL
// CARRERA: LSI
// MATRICULA: ELSI1267

#include <stdio.h>

void encender_maquina(int **);

int main() {
    int estado_maquina = 0;
    int *p_estado = &estado_maquina;
    int **pp_estado = &p_estado;

    printf("Valor del estado de la maquina antes de usar la funcion: %d\n", estado_maquina);
    encender_maquina(pp_estado);
    printf("Valor del estado de la maquina [ACTUALIZADO]: %d\n", estado_maquina);

    return 0;
}

void encender_maquina(int **estado_doble_ptr) {
    **estado_doble_ptr = 1;
}