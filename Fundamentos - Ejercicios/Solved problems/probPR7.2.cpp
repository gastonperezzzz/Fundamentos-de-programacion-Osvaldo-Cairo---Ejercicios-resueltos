#include <stdio.h>
#include <stdlib.h>

int main() {
    char c, cadena[50];
    float sum = 0.0;
    int i = 0;

    printf("Desea ingresar una cadena de caracteres? [S/N]: ");
    scanf("%c", &c);
    getchar();

    while(c == 'S' || c == 's') {
        printf("Ingrese una cadena de caracteres: ");
        fgets(cadena, sizeof(cadena), stdin);
        i++;
        sum += atof(cadena);
        printf("Desea ingresar otra cadena de caracteres? [S/N]: ");
        scanf("%c", &c);
        getchar();
    }

    printf("Sumatoria: %.2f\n", sum);
    printf("Promedio: %.2f\n", sum / i);

    return 0;
}