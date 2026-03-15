#include <stdio.h>
#include <errno.h>

int main() {
    FILE *fp = fopen("myData.txt", "w");
    if (fp == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }
    printf("Posición inicial: %ld\n", ftell(fp));
    fprintf(fp, "12345678910");
    printf("Posición después de escribir '12': %ld\n", ftell(fp));
    fclose(fp);
    return 0;
}