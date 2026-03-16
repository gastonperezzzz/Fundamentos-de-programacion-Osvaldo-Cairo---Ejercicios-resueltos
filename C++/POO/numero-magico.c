#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int num, num_magico;
    int intentos = 0;
    
    srand(time(NULL));
    
    printf("ADIVINA EL NUMERO\n");
    num_magico = rand() % 10 + 1;

    do {
        printf("Ingrese el numero: ");
        scanf("%d", &num);
        if(num_magico < num) {
            printf("MENOS...\n");
            intentos++;
        }
        else if(num_magico > num) {
            printf("MAS...\n");
            intentos++;
        }
        /*
        if(intentos >= 3) {
            printf("Pasaste los cinco intentos, perdiste.\n");
            printf("Cantidad de intentos: %d\n", intentos);
            printf("El numero era: %d\n", num_magico);
            break;
        }
        */
        else if(num == num_magico) {
            printf("ACERTASTE.\n");
            printf("Cantidad de intentos: %d\n", intentos);
        }
    } while(num != num_magico);


    return 0;
}