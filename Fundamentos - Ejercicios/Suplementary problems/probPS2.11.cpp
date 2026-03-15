#include <stdio.h>
#include <math.h>

int main() {
    float l1, l2, l3, sp, area;

    printf("Ingrese una medida para 'L1': ");
    scanf("%f", &l1);

    printf("Ingrese una medida para 'L2': ");
    scanf("%f", &l2);

    printf("Ingrese una medida para 'L3': ");
    scanf("%f", &l3);

    if(l1 + l2 > l3 && l2 + l3 > l1 && l1 + l3 > l2) {
        if(l1 == l2 && l2 == l3) {
            printf("Se trata de un triangulo equilatero.");
        }
        else if(l1 != l2 && l2 != l3) {
            printf("Se trata de un triangulo escaleno.");
        }
        else {
            printf("Se trata de un triangulo isosceles.");
        }
    }
    sp = (l1 + l2 + l3) / 2;
    area = sqrt(sp * (sp - l1) * (sp - l2) * (sp - l3));

    printf("\nEl perimetro es %.2f, y el area es %.2f", sp, area);
}