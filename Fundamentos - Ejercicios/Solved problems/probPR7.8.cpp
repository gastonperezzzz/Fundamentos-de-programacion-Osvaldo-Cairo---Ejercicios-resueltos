#include <stdio.h>
#include <string.h>

void strinverse(char *);

int main() {
    char cad[50], cad2[] = "Sexooo.";

    printf("Ingrese una cadena de caracteres: ");
    fgets(cad, sizeof(cad), stdin);
    if(cad[strlen(cad) - 1] == '\n') {
        cad[strlen(cad) - 1] = '\0';
    }

    strinverse(cad);
    strinverse(cad2);

    return 0;
}

void strinverse(char *string) {
    int i = 0, flag;
    while(string[i] != '\0') {
        i++;
        if(string[i] == '\0') {
            flag = i;
        }
    }
    for(i = flag; i >= 0; i--) {
        printf("%c", string[i]);
    }
    printf("\n");
}
