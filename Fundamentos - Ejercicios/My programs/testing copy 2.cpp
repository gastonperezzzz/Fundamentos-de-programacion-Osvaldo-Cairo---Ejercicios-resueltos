#include <stdio.h>
#include <string.h>

void deleteNewLine(char *);
char *letterDetect(char *, char);

int main() {
    char frase[50], ch;
    char *letra;

    printf("Ingrese una frase: ");
    fgets(frase, sizeof(frase), stdin);
    deleteNewLine(frase);

    printf("Ingrese la letra que quiera encontrar: ");
    ch = getchar();

    letra = letterDetect(frase, ch);

    if(letra != NULL) {
        printf("La letra %c se encontro con exito.\n", *letra);
    }
    else {
        printf("No se encontro la letra solicitada.\n");
    }

    printf("%p\n", letra);

    return 0;
}

char *letterDetect(char *string, char letter) {
    int i = 0;
    while(string[i] != '\0') {
        if(string[i] == letter) {
            return &string[i];
        }
        i++;
    }
    return nullptr;
}
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}