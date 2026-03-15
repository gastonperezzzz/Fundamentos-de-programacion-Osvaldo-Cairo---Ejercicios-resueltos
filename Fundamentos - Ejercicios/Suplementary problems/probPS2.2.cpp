#include <stdio.h>

int main() 
{
    float sal;

    printf("Ingrese el salario del profesor: ");
    scanf("%f", &sal);

    if (sal < 18000) 
    {
        sal = sal + (12/100.0 * sal);
    }
    else if (sal >= 18000 && sal <= 30000) 
    {
        sal = sal + (8/100.0 * sal);
    }
    else if (sal > 30000 && sal <= 50000) 
    {
        sal = sal + (7/100.0 * sal);
    }
    else if (sal > 50000)
    {
        sal = sal + (6/100.0 * sal);
    }
    printf("El nuevo salario del profesor es: %.2f", sal);
}