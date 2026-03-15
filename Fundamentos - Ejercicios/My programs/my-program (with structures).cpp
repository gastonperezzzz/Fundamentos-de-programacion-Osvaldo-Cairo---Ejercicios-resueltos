#include <stdio.h>
#include <string.h>

const int max_chars = 50;

typedef struct {
    char nombre_apellido[max_chars];
    int edad;
    char genero;
    float altura;
    char domicilio[max_chars];
} persona;

void lecturaPersonas(persona *, int); // Hecho
void imprimirPersona(persona); // Hecho
void promedioEdad(persona *, int);  // Hecho
void promedioAltura(persona *, int); // Hecho
void cantidadHombresMujeres(persona *, int); // Hecho
persona personaMasLongeva(persona *, int); // Hecho
persona personaMasAlta(persona *, int); // Hecho

// Programa principal.
int main() {
    int cantidad_personas;

    do {
        printf("Ingrese la cantidad de personas: ");
        scanf("%d", &cantidad_personas);
        getchar();
    } while(cantidad_personas < 1 || cantidad_personas > 50);

    persona personas[cantidad_personas];
    persona per_mas_alta, per_mas_longeva;

    lecturaPersonas(personas, cantidad_personas);

    printf("Persona mas longeva: \n");
    per_mas_longeva = personaMasLongeva(personas, cantidad_personas);
    imprimirPersona(per_mas_longeva);

    printf("Persona mas alta: \n");
    per_mas_alta = personaMasAlta(personas, cantidad_personas);
    imprimirPersona(per_mas_alta);

    cantidadHombresMujeres(personas, cantidad_personas);

    return 0;
}

// Definicion de las funciones.
void DeleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaPersonas(persona *var, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("Persona [%d] | Nombre y apellido: ", i + 1);
        fgets(var[i].nombre_apellido, max_chars, stdin);
        DeleteNewLine(var[i].nombre_apellido);

        do {
            printf("Persona [%d] | Edad: ", i + 1);
            scanf("%d", &var[i].edad);
            getchar();
        } while(var[i].edad < 1 || var[i].edad > 100);

        do {
            printf("Persona [%d] | Genero [M/F]: ", i + 1);
            var[i].genero = getchar();
        } while(var[i].genero != 'M' && var[i].genero != 'm' && var[i].genero != 'F' && var[i].genero != 'f');

        printf("Persona [%d] | Altura: ", i + 1);
        scanf("%f", &var[i].altura);
        getchar();

        printf("Persona [%d] | Domicilio: ", i + 1);
        fgets(var[i].domicilio, max_chars, stdin);
        DeleteNewLine(var[i].domicilio);
    
        printf("\n");
    }
}
void imprimirPersona(persona var) {
    printf("Nombre y apellido: %s\n", var.nombre_apellido);
    printf("Edad: %d\n", var.edad);
    printf("Genero: %c\n", var.genero);
    printf("Altura: %.2f\n", var.altura);
    printf("Domicilio: %s\n\n", var.domicilio);
}
void promedioEdad(persona *var, int size) {
    int i;
    float sum_edades = 0.0;
    for(i = 0; i < size; i++) {
        sum_edades += var[i].edad;
    }
    printf("El promedio de edad de las personas es: %.2f\n", sum_edades / size);
}
void promedioAltura(persona *var, int size) {
    int i;
    float sum_alturas = 0.0;
    for(i = 0; i < size; i++) {
        sum_alturas += var[i]. altura;
    }
    printf("El promedio de altura de las personas es: %.2f\n", sum_alturas / size);
}
persona personaMasLongeva(persona *var, int size) {
    int i, i_persona_longeva = 0, persona_edad = 0;
    persona persona_longeva;
    for(i = 0; i < size; i++) {
        if(persona_edad < var[i].edad) {
            persona_edad = var[i].edad;
            i_persona_longeva = i;
        }
    }

    persona_longeva = var[i_persona_longeva];

    return persona_longeva;
}
persona personaMasAlta(persona *var, int size) {
    int i, i_persona_alta = 0;
    float persona_alta = 0;
    persona persona_mas_alta;
    for(i = 0; i < size; i++) {
        if(persona_alta < var[i].altura) {
            persona_alta = var[i].altura;
            i_persona_alta = i;
        }
    }

    persona_mas_alta = var[i_persona_alta];

    return persona_mas_alta;
}
void cantidadHombresMujeres(persona *var, int size) {
    int i, hombres = 0, mujeres = 0;
    for(i = 0; i < size; i++) {
        if(var[i].genero == 'M' || var[i].genero == 'm') {
            hombres++;
        }
        else if(var[i].genero == 'F' || var[i].genero == 'f') {
            mujeres++;
        }
    }
    printf("Cantidad de hombres | %d \nCantidad de mujeres | %d\n", hombres, mujeres);
}