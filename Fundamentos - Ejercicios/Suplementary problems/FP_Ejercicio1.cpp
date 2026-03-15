#include <stdio.h>
#include <math.h>

main () {
	
	const float pi = 3.141692;
	
	float area, vol, radio, alt;
	//int vab;
	
	printf ("Ingrese el radio y la altura de un cilindro: ");
	scanf ("%f %f", &radio, &alt);
	
	area = 2 * pi * radio * alt;
	vol = pi * radio * radio * alt;
	
	printf ("El volumen del cilindro es %.3f y su area es %.2f", vol, area);
}