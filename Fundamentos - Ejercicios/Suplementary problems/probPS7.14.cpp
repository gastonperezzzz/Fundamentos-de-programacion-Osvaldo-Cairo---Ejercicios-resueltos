#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deleteNewLine(char *);
void strClean(char *, int);

const int max_strings = 3;
const int max_chars = 80;

int main() {
    char arc[max_strings][max_chars], aux[max_chars];
    int cont_letters = 0, i = 0, j = 0, len_str;
    int long_words[max_chars] = {0};

    for(i = 0; i < max_strings; i++) {
        strClean(arc[i], max_chars);
    }

    strClean(aux, max_chars);

    for(i = 0; i < max_strings; i++) {
        printf("Ingrese la cadena [%d]: ", i);
        fgets(arc[i], max_chars, stdin);
        deleteNewLine(arc[i]);
    }
    for(i = 0; i < max_strings; i++) {
        strClean(aux, max_chars);
        strcpy(aux, arc[i]);
        len_str = strlen(aux) + 1;
        for(j = 0; j < len_str; j++) {
            if(isalpha(aux[j])) {
                cont_letters++;
            }
            else {
                long_words[cont_letters]++;
                cont_letters = 0;
            }
        }
    }
    printf("\nLongitud de palabra: \tFrecuencia:\n");
    for(i = 1; i <= 15; i++) {
        printf("%d \t\t\t%d\n", i, long_words[i]);
    }

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void strClean(char *string, int size) {
    for(int i = 0; i < size; i++) {
        string[i] = 0;
    }
}