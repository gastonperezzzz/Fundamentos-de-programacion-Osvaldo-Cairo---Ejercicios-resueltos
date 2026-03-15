#include <stdio.h>

int main()
{
int sounds;
float fa;

printf("Ingrese el numero de sonidos emitidos por el grillo: ");
scanf("%d", &sounds);

fa = sounds/4.0 + 40;

printf("La temperatura en grados Farenheit segun los sonidos del grillo es: %.1f", fa);
}