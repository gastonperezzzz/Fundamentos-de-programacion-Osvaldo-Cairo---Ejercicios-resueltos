#include <stdio.h>
#include <string.h>

void deleteNewLine(char *); 

const int max_strings = 3;
const int max_chars = 50;

int main() {
    char arc[max_strings][max_chars];
    char vocales[] = "aeiouAEIOU", aux[max_chars];
    int i, j, k;
    int string_length, cont_vocales, str_mayor_vocales = 0, indice_mayor_vocales;

    for(i = 0; i < max_strings; i++) {
        printf("Ingrese una cadena de caracteres [%d]: ", i);
        fgets(arc[i], max_chars, stdin);
        deleteNewLine(arc[i]);
        strcpy(aux, arc[i]);
        string_length = strlen(aux);
        cont_vocales = 0;
        for(j = 0; j < string_length; j++) {
            for(k = 0; k < 10; k++) {
                if(vocales[k] == aux[j]) {
                    cont_vocales++;
                }
            }
            if(cont_vocales > str_mayor_vocales) {
                str_mayor_vocales = cont_vocales;
                indice_mayor_vocales = i;
            }
        }
    }

    printf("La cadena con mayor numero de vocales es: \n");
    puts(arc[indice_mayor_vocales]);
    printf("Con un total de %d vocales\n", str_mayor_vocales);

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}