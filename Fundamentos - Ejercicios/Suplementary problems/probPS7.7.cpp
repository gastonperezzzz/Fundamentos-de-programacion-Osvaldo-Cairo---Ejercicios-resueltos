#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deleteNewLine(char *);

int main() {
    char cad[30];
    char cod_area[3], region[2], num[8];
    int i = 0, j = 0, k = 0, flag, lenstr;

    do {
        flag = 1;
        printf("Ingrese un numero telefonico: ");
        fgets(cad, sizeof(cad), stdin);
        deleteNewLine(cad);
        lenstr = strlen(cad);
        if(lenstr < 10) {
            flag = 0;
        }
        else {
            for(i = 0; i < lenstr; i++) {
                if(isalpha(cad[i])) {
                    flag = 0;
                    break;
                }
            }
        }
        if(flag == 0) {
            printf("Error: numero telefonico invalido.\n");
        }
    } while(flag == 0);

    for(i = 0; i < lenstr; i++) {
        if(i <= 1) {
            cod_area[i] = cad[i];
        }
        else if(i > 1 && i < 3) {
            region[j] = cad[i];
            j++;
        }
        else if(i > 2) {
            num[k] = cad[i];
            k++;
        }
    }

    printf("Numero telefonico: (%s) - %s - %s\n", cod_area, region, num);

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}