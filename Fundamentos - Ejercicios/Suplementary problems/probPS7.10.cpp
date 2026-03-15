#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deleteNewLine(char *);
void strClean(char *);

const int max_strings = 20;
const int max_chars = 50;

int main() {
    char fechas_dias_idem[max_strings][max_chars], cad[max_chars], fechahoy[15], diahoy[3], dia_comp[3];
    char option;
    int i = 0, j = 0, len_str, cont_str = 1;

    strClean(cad);
    strClean(fechahoy);
    strClean(dia_comp);
    strClean(dia_comp);

    for(i = 0; i < max_strings; i++) {
        strClean(fechas_dias_idem[i]);
    }

    do {
        printf("Desea ingresar una cadena de caracteres? [S/N]: ");
        scanf("%c", &option);
        getchar();
        if(option != 'S' && option != 's' && option != 'N' && option != 'n') {
            printf("Error: opcion invalida.\n");
        }
    } while(option != 'S' && option != 's' && option != 'N' && option != 'n');

    printf("Ingrese la fecha de hoy en formato [dd/mm/yyyy]: ");
    fgets(fechahoy, sizeof(fechahoy), stdin);
    deleteNewLine(fechahoy);
    len_str = strlen(fechahoy);
    for(i = 0; i < len_str; i++) {
        if(isdigit(fechahoy[i])) {
            diahoy[i] = fechahoy[i];
        }
        else {
            break;
        }
    }

    puts(diahoy);

    i = 0;

    while(option == 'S' || option == 's') {
        printf("[%d] Ingrese una fecha en formato dd/mm/yyyy: ", i);
        fgets(cad, max_chars, stdin);
        deleteNewLine(cad);
        len_str = strlen(cad);
        for(j = 0; j < len_str; j++) {
            if(isdigit(cad[j])) {
                dia_comp[j] = cad[j];
            }
            else {
                break;
            }
        }
        if(!(strcmp(diahoy, dia_comp))) {
            strcpy(fechas_dias_idem[i], cad);
        }
        i++;

        do {
            printf("Desea ingresar otra cadena de caracteres? [S/N]: ");
            scanf("%c", &option);
            getchar();
            if(option != 'S' && option != 's' && option != 'N' && option != 'n') {
                printf("Error: opcion invalida.\n");
            }
        } while(option != 'S' && option != 's' && option != 'N' && option != 'n');
        
        if(option == 'S' || option == 's') {
            cont_str++;
        }
    }

    printf("\nFechas que coinciden con el dia de hoy:\n");
    for(i = 0; i < cont_str; i++) {
        printf("%s\n", fechas_dias_idem[i]);
    }

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void strClean(char *string) {
    int len = strlen(string);
    for(int i = 0; i < len; i++) {
        string[i] = 0;
    }
}