#include <stdio.h>

int main() {
    int n, hombres = 0, mujeres = 0, sexo, edad;
    float peso, altura;
    float prom_peso_hombre, prom_peso_mujer;
    float promaltura_hombre, promaltura_mujer;
    float sumpeso_hombre = 0, sumpeso_mujer = 0;
    float sumaltura_hombre = 0, sumaltura_mujer = 0;

    do {
        printf("Ingrese la cantidad de personas: ");
        scanf("%d", &n);
        if(n < 0) {
            printf("Error: cantidad invalida.\n");
        }
    } while(n < 0);

    for(int i = 1; i <= n; i++) {
        do {
            printf("Ingrese la edad [%d]: ", i);
            scanf("%d", &edad);
            if(edad <= 0) {
                printf("Error: numero invalido.\n");
            }
        } while(edad <= 0);
        
        do {
            printf("Ingrese el peso [%d]: ", i);
            scanf("%f", &peso);
            if(peso <= 0) {
                printf("Error: numero invalido.\n");
            }
        } while(peso <= 0);
    
        do {
            printf("Ingrese la altura [%d]: ", i);
            scanf("%f", &altura);
            if(altura <= 0) {
                printf("Error: numero invalido.\n");
            }
        } while(altura <= 0);

        do {
            printf("Ingrese el sexo [%d] [m = 1; f = 0]: ", i);
            scanf("%d", &sexo);
        } while(sexo < 0 || sexo > 1);

        if(edad >= 18) {
            if(sexo) {
                sumpeso_hombre += peso;
                sumaltura_hombre += altura;
                hombres++;
            }
            else {
                sumpeso_mujer += peso;
                sumaltura_mujer += altura;
                mujeres++;
            }
        }
        printf("\n");
    }
    prom_peso_hombre = sumpeso_hombre / hombres;
    prom_peso_mujer = sumpeso_mujer / mujeres;
    promaltura_hombre = sumaltura_hombre / hombres;
    promaltura_mujer = sumaltura_mujer / mujeres;
    
    printf("%d hombres; %d mujeres.\n", hombres, mujeres);
    printf("El promedio del peso de los hombres es: %.2f\n", prom_peso_hombre);
    printf("El promedio de la altura de los hombres es: %.2f\n", promaltura_hombre);
    printf("El promedio del peso de las mujeres es: %.2f\n", prom_peso_mujer);
    printf("El promedio de la altura de las mujeres es: %.2f\n", promaltura_mujer);
}