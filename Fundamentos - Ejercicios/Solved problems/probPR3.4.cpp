#include <stdio.h>

int main() {
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;
    float calif;

    printf("Ingrese la calificacion del alumno: ");
    scanf("%f", &calif);

    while(calif != -1) {
        if(calif < 4) {
            r1++;
        }
        else {
            if(calif < 6) {
                r2++;
            }
            else {
                if(calif < 8) {
                    r3++;
                }
                else {
                    if(calif < 9) {
                        r4++;
                    }
                    else {
                        if(calif < 10) {
                            r5++;
                        }
                    }
                }
            }
        }
        printf("Ingrese otra calificacion: ");
        scanf("%f", &calif);
    }
    printf("%d, %d, %d, %d, %d", r1, r2, r3, r4, r5);
}