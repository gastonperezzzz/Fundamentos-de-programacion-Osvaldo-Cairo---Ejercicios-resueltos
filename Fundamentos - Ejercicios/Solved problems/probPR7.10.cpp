#include <stdio.h>
#include <string.h>

int main() {
    int n, m, cad_mayor = 0, cantidad_caracteres = 0;
    int i = 0, j = 0;

    do {
        printf("Ingrese la cantidad de cadenas de caracteres: ");
        scanf("%d", &n);
        getchar();
        if(n <= 1 || n > 20) {
            printf("Error: cantidad invalida.\n");
        }
    } while(n <= 1 || n > 20);

    do {
        printf("Ingrese la cantidad de caracteres por cadena: ");
        scanf("%d", &m);
        getchar();
        if(m <= 1 || m > 50) {
            printf("Error: cantidad invalida.\n");
        }
    } while(m <= 1 || m > 50);

    char cadenas[n][m];
    char cad[m];

    for(i = 0; i < n; i++) {
        printf("Ingrese la cadena [%d]: ", i + 1);
        fgets(cadenas[i], sizeof(cadenas[i]), stdin);
    }
    for(i = 0; i < n; i++) {
        j = 0;
        int cont = 0;
        strcpy(cad, cadenas[i]);
        while(cad[j] != '\0') {
            cont++;
            j++;
        }
        if(cantidad_caracteres < cont) {
            cantidad_caracteres = cont;
            cad_mayor = i;
        }
    }

    printf("Cadena más larga: %s y contiene %d caracteres.\n", cadenas[cad_mayor], cantidad_caracteres);

    return 0;
}