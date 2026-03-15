#include <stdio.h>
#include <string.h>

#define MAX_CHARS 30

void swapStrings(char strings[][MAX_CHARS], int);

int main() {
    int n;

    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &n);
    getchar();

    char cadenas[n][MAX_CHARS];

    for(int i = 0; i < n; i++) {
        printf("Ingrese la cadena [%d]: ", i);
        fgets(cadenas[i], sizeof(cadenas[i]), stdin);
    }

    swapStrings(cadenas, n);

    for(int i = 0; i < n; i++) {
        printf("%s", cadenas[i]);
    }

    return 0;
}

void swapStrings(char strings[][MAX_CHARS], int filas) {
    char cad[MAX_CHARS];
    int i;
    for(i = 0; i < (filas / 2); i++) {
        strcpy(cad, strings[i]);
        strcpy(strings[i], strings[filas - 1 - i]);
        strcpy(strings[filas - 1 - i], cad);
    }
}