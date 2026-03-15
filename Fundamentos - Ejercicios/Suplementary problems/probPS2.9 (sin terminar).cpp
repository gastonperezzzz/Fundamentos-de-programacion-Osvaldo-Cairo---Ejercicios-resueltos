#include <stdio.h>
#include <math.h>

int main() {
    int med1, med2;
    float val;

    printf("1) Medidas de longitud\n2) Medidas de volumen\n3) Medidas de peso\n");

    printf("Ingrese la categoria de medida en la cual convertir [1/2/3]: ");
    scanf("%d", &med1);

    switch(med1) {
        case 1:
            printf("MEDIDAS DE LONGITUD\n");
            printf("1) Pulgadas a milimetros\n2) Yardas a metros\n3) Millas a kilometros\n");
            printf("4) Pulgadas^2 a centimetros^2\n5) Pies^2 a metros^2\n");
            printf("6) Yardas^2 a metros^2\n7) Acres a hectareas\n");
            printf("8) Millas^2 a kilometros^2\n");

            printf("Ingrese una tipo de conversion de la lista [1 - 8]: ");
            scanf("%d", &med2);

            printf("Ingrese el valor a convertir: ");
            scanf("%f", &val);

            switch(med2) {
                case 1:
                    val *= 25.40;
                    break;
                case 2:
                    val *= 0.9144;
                    break;
                case 3:
                    val *= 1.6093;
                    break;
                case 4:
                    val = pow(val, 2) * pow(6.452, 2);
                    break;
                case 5:
                    val = pow(val, 2) * pow(0.09290, 2);
                    break;
                case 6:
                    val = pow(val, 2) * pow(0.8361, 2);
                    break;
                case 7:
                    val *= 0.4047;
                    break;
                case 8: 
                    val = pow(val, 2) * pow(2.59, 2);
                    break;
                default:
                    printf("Conversion no coincide con medidas listadas.");
            }
        case 2:
            printf("MEDIDAS DE VOLUMEN\n");
            printf("1) Pies^3 a metros^3\n2) Yardas^3 a metros^3\n");
            printf("3) Pintas a litros\n4) Galones a litros\n");

            printf("Ingrese una tipo de conversion de la lista [1 - 4]: ");
            scanf("%d", &med2);

            printf("Ingrese el valor a convertir: ");
            scanf("%f", &val);


            switch(med2) {

            }
        case 3:
            printf("MEDIDAS DE PESO\n");
            printf("1) Onzas a gramos\n2) Libras a kilogramos\n3) Toneladas inglesas a toneladas\n");
            
            printf("Ingrese una tipo de conversion de la lista [1 - 3]: ");
            scanf("%d", &med2);

            printf("Ingrese el valor a convertir: ");
            scanf("%f", &val);

            switch(med2) {

            }
    }
}