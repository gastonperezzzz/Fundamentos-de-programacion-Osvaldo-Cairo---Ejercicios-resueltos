#include <stdio.h>
#include <ctype.h>
#include <string.h>

void minsymayus(char *cad);

int main() {
    char fra[20][50];
    int i, n;

    printf("Ingrese el numero de cadenas: ");
    scanf("%d", &n);
    getchar();

    for(i = 0; i < n; i++) {
        printf("Cadena [%d]: ", i + 1);
        fgets(fra[i], sizeof(fra[i]), stdin);
    }

    for(i = 0; i < n; i++) {
        minsymayus(fra[i]);
    }

    return 0;
}

void minsymayus(char *cad) {
    int i = 0, mi = 0, ma = 0;
    while(cad[i] != '\0') {
        if(islower(cad[i])) {
            mi++;
        }
        else if(isupper(cad[i])) {
            ma++;
        }
        i++;
    }
    printf("Minusculas %d | Mayusculas %d\n", mi, ma);
}