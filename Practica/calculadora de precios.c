#include <stdio.h>

int main() {
    int precio_base, cantidad_llaveros = 0;
    float descuento_mayorista = 0.05;

    printf("Ingrese el precio base: ");
    scanf("%d", &precio_base);
    getchar();

    for(int i = 0; i < 6; i++) {
        if(cantidad_llaveros == 0) {
            printf("Unidad | $%d\n", precio_base);
            // descuento_mayorista = 110;
            cantidad_llaveros = 10;
        }
        else {
            printf("x%d unidades | $%.0f\n", cantidad_llaveros, precio_base - (precio_base * descuento_mayorista));
            cantidad_llaveros += 10;
            descuento_mayorista += 0.05;
        }
    }


}