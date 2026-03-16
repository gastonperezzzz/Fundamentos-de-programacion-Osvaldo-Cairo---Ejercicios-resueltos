// ALUMNO: PEREZ MERCADO GASTON EZEQUIEL
// CARRERA: LSI
// MATRICULA: ELSI1267

#include <stdio.h>

void duplicar_stock(int *);

int main() {
    int stock_bodega[3] = {150, 80, 20};

    printf("Stock de la bodega: ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", stock_bodega[i]);
    }
    printf("\n\n");

    duplicar_stock(&stock_bodega[1]);
    printf("Stock de la bodega [ACTUALIZADO]: ");
    for(int i = 0; i < 3; i++) {
        printf("%d ", stock_bodega[i]);
    }
    printf("\n");

    return 0;
}

void duplicar_stock(int *stock_ptr) {
    *stock_ptr *= 2;
}