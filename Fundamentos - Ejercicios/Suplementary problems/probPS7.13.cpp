#include <stdio.h>
#include <string.h>
#include <ctype.h>

void deleteNewLine(char *);
int wordCounter(char *);

const int max_strings = 3;
const int max_chars = 50;

int main() {
    char arc[max_strings][max_chars], aux[max_chars];
    int i;
    int arc_words[max_strings] = {0};

    for(i = 0; i < max_strings; i++) {
        printf("Ingrese la cadena [%d]: ", i);
        fgets(arc[i], max_chars, stdin);
        deleteNewLine(arc[i]);
        strcpy(aux, arc[i]);
        arc_words[i] = wordCounter(aux);
    }

    for(i = 0; i < max_strings; i++) {
        printf("Cadena: %s | Palabras: %d\n", arc[i], arc_words[i]);
    }

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
int wordCounter(char *string) {
    int words = 0;
    int i, string_length;
    string_length = strlen(string);
    for(i = 0; i < string_length; i++) {
        if(string[i] == ' ') {
            words++;
        }
    }

    return words + 1;
}