#include <stdio.h>

main() {
    int dis, min, seg, cen;
    float tse, vms, vkh;

    printf ("Ingrese la distancia recorrida por el participante, minutos, segundos y centesimas: ");
     scanf ("%d %d %d %d", &dis, &min, &seg, &cen);

     tse = min * 60 + seg + cen / 100;
     vms = dis / tse;
     vkh = (vms * 3600) / 1000;

     printf ("La velocidad del participante en k/h es: %.3f", vkh);
}