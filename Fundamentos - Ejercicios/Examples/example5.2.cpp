#include <stdio.h>

int main() {
    int votos[5] = {0};
    int voto;

    do {
        do {
            printf("Ingrese el voto: ");
            scanf("%d", &voto);
            if(voto < 0 || voto > 5) {
                printf("Error: voto invalido.\n");
            }
            else {
                votos[voto - 1]++;
            }
        } while(voto < 0 || voto > 5);
    } while(voto != 0);

    for(int i = 0; i < 5; i++) {
        printf("El candidato %d tiene %d votos.\n", i + 1, votos[i]);
    }

    return 0;
}