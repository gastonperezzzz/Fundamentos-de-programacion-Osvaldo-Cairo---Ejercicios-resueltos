#include <stdio.h>
#include <math.h>

int main() {
    int n1, n2, primo_uno = 1, primo_dos = 0, gemelo;

    do {
        printf("Ingrese un numero como limite inferior: ");
        scanf("%d", &n1);
    } while(n1 < 2);
    
    do {
        printf("Ingrese un numero como limite superior: ");
        scanf("%d", &n2);
    } while(n2 <= n1);

    for(int i = 4; i < n2; ++i) {
        bool numprimo = true;
        for(int j = 4; j < i; ++j) {
            if(i % j == 0) {
                numprimo = false;
                break;
            }
        }
        if(numprimo) {
            printf("%d ", i);
            //primo_dos = primo_uno;
            //primo_uno = i;
            //gemelo = fabs(primo_uno - primo_dos);
            //if(gemelo == 2) {
            //printf("%d y %d son primos gemelos.\n", primo_dos, primo_uno);
        }
    }
    return 0;
}
