#include <stdio.h>

int main() {
    unsigned int cat;
    float sal, hsxt;

    printf("Ingrese la categoria del trabajador [1/2/3]: ");
    scanf("%d", &cat);

    printf("Ingrese el salario del trabajador: ");
    scanf("%f", &sal);

    printf("Ingrese la cantidad de horas extras trabajadas: ");
    scanf("%f", &hsxt);

    if(hsxt > 30) {
        hsxt = 30;
    }

    switch(cat) {
        case 1:
            sal += hsxt * 40;
            break;
        case 2:
            sal += hsxt * 50;
            break;
        case 3:
            sal += hsxt * 85;
            break;
        default:
            printf("Categoria no figurada. No puede obtener este beneficio.\n");
    }
    printf("El salario total del trabajador es: %.2f", sal);
}