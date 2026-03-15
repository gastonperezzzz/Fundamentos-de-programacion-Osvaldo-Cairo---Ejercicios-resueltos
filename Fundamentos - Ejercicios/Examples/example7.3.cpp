#include <stdio.h>

int main() {
    char *cad0 = "Buenos dias";
    puts(cad0);

    cad0 = "Dias buenos";
    puts(cad0);

    char cad1[20] = "Hola";

    char cad2[] = "Argentina";

    char cad3[] = {'B', 'i', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};

    char cad4[20], cad5[20], cad6[20];

    printf("La cadena cad0 es: ");
    puts(cad0);

    printf("La cadena cad1 es: %s\n", cad1);

    printf("La cadena cad2 es: ");
    puts(cad2);

    printf("La cadena cad3 es: ");
    puts(cad3);

    printf("Ingrese una linea de texto: ");
    fgets(cad4, sizeof(cad4), stdin);

    printf("\nLa cadena cad4 es: ");
    puts(cad4);
    fflush(stdin);

    printf("Ingrese una linea de texto: ");
    scanf("%s", cad5);
    fflush(stdin);

    char p;
    int i = 0;

    while((p = getchar()) != '\0') {
        cad6[i++] = p;
        cad6[i] = '\0';
        printf("La cadena cad6 es: ");
        puts(cad6);
    }

    return 0;
}