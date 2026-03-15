#include <stdio.h>
#include <string.h>

const int max_chars = 50;

typedef struct {
    int matricula;
    char nom_ap[max_chars];
    int carrera;
    float promedio;
} alumno;

void deleteNewLine(char *);

int main() {
    

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}