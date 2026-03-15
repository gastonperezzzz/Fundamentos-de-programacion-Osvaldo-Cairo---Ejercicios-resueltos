#include <stdio.h>

int main() {
    int n1, n2, n3, r = 0;

    printf("Ingrese un valor entero [1]: ");
    scanf("%d", &n1);

    printf("Ingrese un valor entero [2]: ");
    scanf("%d", &n2);

    printf("Ingrese un valor entero [3]: ");
    scanf("%d", &n3);

    if(n1 < n2) {
        r++;
        if(n2 < n3) {
            r++;
            if(n1 < n3) {
                r++;
            }
        }
    }
    if(r == 3) {
        printf("Los numeros estan ordenados en forma ascendente %d, %d, %d", n1, n2, n3);
    }
    else {
        printf("Los numeros no estan ordenados en forma ascendete.");
    }
}