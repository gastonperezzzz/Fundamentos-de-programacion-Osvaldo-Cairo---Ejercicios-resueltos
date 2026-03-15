#include <stdio.h>
#include <ctype.h>

// isdigit();
// isalpha();
// islower();
// isupper();
// tolower();
// toupper();

int main() {
    char c1;

    printf("Ingrese un numero o un caracter: ");
    c1 = getchar();

    if(isdigit(c1)) {
        printf("El dato ingresado es un numero.\n");
    }
    else if(isalpha(c1)) {
        printf("El dato ingresado es un caracter.\n");
    }

    return 0;
}