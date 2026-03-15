#include <stdio.h>
#include <math.h>

main () {
	
	float ext; 
	int acre = 4047, hec = 10000;
	
	printf ("Ingrese la extension expresada en acres: ");
	scanf ("%f", &ext);
	
	ext = ext * acre / hec;
	
	printf ("La extension en hectareas es: %.5f", ext);
}