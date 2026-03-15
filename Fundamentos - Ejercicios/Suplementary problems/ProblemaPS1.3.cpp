#include <stdio.h>

main () {
	
	float n1, n2, sum, res, mult;
	
	printf ("Ingrese dos valores reales: ");
	scanf ("%f %f", &n1, &n2);
	
	sum = n1 + n2;
	res = n1 - n2;
	mult = n1 * n2;
	
	printf ("La suma de los numeros es %.2f, la resta es %.2f y su multiplicacion es %.2f", sum, res, mult);
}