#include <stdio.h>

const int max_chars = 50;

int main() {
    char string[max_chars];
    int option;
    FILE *archivo;

    if((archivo = fopen("arc.txt", "w")) != NULL) {
        do {
            printf("Desea ingresar una cadena de caracteres? \n0. No \n1.Si\n");
            scanf("%d", &option);
            getchar();
        } while(option != 0 && option != 1);
        while(option) {
            printf("Ingrese una cadena de caracteres: ");
            fgets(string, max_chars, stdin);
            fputs(string, archivo);
            
            do {
                printf("Desea ingresar una cadena de caracteres? \n0. No \n1.Si\n");
                scanf("%d", &option);
                getchar();
            } while(option != 0 && option != 1);
        }
        fclose(archivo);
    }
    else {
        printf("Error: no se ha podido abrir el archivo.\n");
    }

    return 0;
}