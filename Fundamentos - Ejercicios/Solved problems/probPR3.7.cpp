#include <stdio.h>

int main() {
    int voto = 1, cand1 = 0, cand2 = 0, cand3 = 0, cand4 = 0, cand5 = 0;
    float sum = 0;

    while(voto != 0 && voto <= 5) {
        printf("Ingrese numero de voto del candidato [1 - 5]: ");
        scanf("%d", &voto);

        if(voto > 0 && voto <= 5) {
            switch(voto) {
                case 1:
                    cand1++;
                    sum++;
                    break;
                case 2:
                    cand2++;
                    sum++;
                    break;
                case 3:
                    cand3++;
                    sum++;
                    break;
                case 4:
                    cand4++;
                    sum++;
                    break;
                case 5:
                    cand5++;
                    sum++;
                    break;
            }
        }
    }
    printf("Candidato 1 => con %d votos y %.2f de la cantidad de votantes.\n", cand1, (float)cand1 / sum) * 100;
    printf("Candidato 2 => con %d votos y %.2f de la cantidad de votantes.\n", cand2, (float)cand2 / sum) * 100;
    printf("Candidato 3 => con %d votos y %.2f de la cantidad de votantes.\n", cand3, (float)cand3 / sum) * 100;
    printf("Candidato 4 => con %d votos y %.2f de la cantidad de votantes.\n", cand4, (float)cand4 / sum) * 100;
    printf("Candidato 5 => con %d votos y %.2f de la cantidad de votantes.\n", cand5, (float)cand5 / sum) * 100;
}