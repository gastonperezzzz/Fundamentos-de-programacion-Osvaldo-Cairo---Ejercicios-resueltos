#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char fecha[30];
    char year[15];
    char mes[15];
    char dia[15];
    int i = 0, j = 0, k = 0, n = 0, length_string;

    printf("Ingrese una fecha con el formato [dd/mm/aa]: ");
    fgets(fecha, sizeof(fecha), stdin);

    length_string = strlen(fecha);

    while(i < length_string) {
        if(i >= 0 && i <= 2) {
            if(isdigit(fecha[i])) {
                dia[j] = fecha[i];
                j++;
            }
        }
        if(i > 2 && i < 5) {
            if(isdigit(fecha[i])) {
                mes[k] = fecha[i];
                k++;
            }
        }
        else if(i > 5) {
            if(isdigit(fecha[i])) {
                year[n] = fecha[i];
                n++;
            }
        }
        i++;
    }

    int day = atoi(dia);
    int month = atoi(mes);
    int year_i = atoi(year);

    switch(month) {
        case 1:
            strcpy(mes, "Enero"); break;
        case 2:
            strcpy(mes, "Febrero"); break;
        case 3:
            strcpy(mes, "Marzo"); break;
        case 4:
            strcpy(mes, "Abril"); break;
        case 5:
            strcpy(mes, "Mayo"); break;
        case 6:
            strcpy(mes, "Junio"); break;
        case 7:
            strcpy(mes, "Julio"); break;
        case 8:
            strcpy(mes, "Agosto"); break;
        case 9:
            strcpy(mes, "Septiembre"); break;
        case 10:
            strcpy(mes, "Octubre"); break;
        case 11:
            strcpy(mes, "Noviembre"); break;
        case 12:
            strcpy(mes, "Diciembre"); break;
        default:
            printf("Mes invalido.\n");
    }

    printf("%d de %s del año %d\n", day, mes, year_i + 2000);

    return 0;
}