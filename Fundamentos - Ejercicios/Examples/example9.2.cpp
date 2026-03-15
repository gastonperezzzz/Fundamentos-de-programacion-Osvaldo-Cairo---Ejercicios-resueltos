#include <stdio.h>

int main() {
    char p1;
    FILE *archive;
    if((archive = fopen("arc.txt", "r")) == NULL) {
        printf("Error: No se ha podido abrir el archivo.\n");
    }
    else {
        while(!feof(archive)) {
            p1 =fgetc(archive);
            putchar(p1);
        }
        fclose(archive);
    }

    return 0;
}