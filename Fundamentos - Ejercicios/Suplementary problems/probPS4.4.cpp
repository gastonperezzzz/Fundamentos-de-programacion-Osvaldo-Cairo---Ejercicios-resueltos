#include <stdio.h>

float inversion(int, float, float);

int main() {
    int month;
    float money, interest;

    do {
        printf("Ingrese la cantidad de meses pondra la inversion: ");
        scanf("%d", &month);
        if(month <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(month <= 0);

    do {
        printf("Ingrese la cantidad de capital a invertir: ");
        scanf("%f", &money);
        if(money <= 0) {
            printf("Error: numero invalido.\n");
        }
    } while(money <= 0);

    do {
        printf("Ingrese la tasa de interes a considerar: ");
        scanf("%f", &interest);
        if(interest <= 0 || interest > 1) {
            printf("Error: numero invalido.\n");
        }
    } while(interest <= 0 || interest > 1);

    printf("Dados los parametros, el rendimiento generado seria de: %.2f\n", inversion(month, money, interest));
}

float inversion(int mes, float cap, float tas) {
    float rendimiento;
    rendimiento = mes * cap * tas;
    return rendimiento;
}