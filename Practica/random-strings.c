#include <stdio.h>
#include <string.h>

const int max_chars = 50;
const int max_str = 5;

int hash(char *, int);

int main() {
    char text[max_str][max_chars];
    
    for(int i = 0; i < max_str; i++) {
        printf("[%d] Ingrese una frase: ", i + 1);
        fgets(text[i], max_chars, stdin);
    }

    printf("STRING | HASH \n");
    for(int i = 0; i < max_str; i++) {
        printf("%s | %d\n", text[i], hash(text[i], 10));
    }

    return 0;
}

int hash(char *string, int size) {
    int str_size = strlen(string);
    int sum = 0;

    for(int i = 0; i < str_size; i++) {
        sum += string[i];
    }

    return (sum % size);
}