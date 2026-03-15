#include <stdio.h>
#include <string.h>

const int max_chars = 50;

typedef struct {
    char plataforma[max_chars];
    char email[max_chars];
    char nom_usuario[max_chars];
    char password[max_chars];
} usuario;

void lecturaUsuario(FILE *);
void mostrarUsuarios(FILE *);
void deleteNewLine(char *);

int main() {
    FILE *apuntador_archivo;
    int option;

    apuntador_archivo = fopen("gestorusuarios.dat", "r+");

    if(apuntador_archivo == NULL) {
        printf("No se pudo abrir el archivo...\n");
        fclose(apuntador_archivo);
    }
    else {
        do {
            do {
                printf("GESTOR DE CUENTAS\n");
                printf("1. Agregar cuenta\n2. Mostrar todas las cuentas \n3. Salir \nOpcion: ");
                scanf("%d", &option);
                getchar();
            } while(option < 1 || option > 3);
            switch(option) {
                case 1:
                    lecturaUsuario(apuntador_archivo);
                    break;
                case 2:
                    mostrarUsuarios(apuntador_archivo);
                    break;
            }
        } while(option != 3);
    }

    return 0;
}
void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}
void lecturaUsuario(FILE *pointer) {
    usuario user;

    fseek(pointer, 0 * sizeof(usuario), SEEK_END);

    printf("Ingrese el nombre de la plataforma: ");
    fgets(user.plataforma, max_chars, stdin);
    deleteNewLine(user.plataforma);

    printf("Ingrese el email registrado: ");
    fgets(user.email, max_chars, stdin);
    deleteNewLine(user.email);

    printf("Ingrese el nombre de usuario registrado: ");
    fgets(user.nom_usuario, max_chars, stdin);
    deleteNewLine(user.nom_usuario);

    printf("Ingrese la contraseña: ");
    fgets(user.password, max_chars, stdin);
    deleteNewLine(user.password);

    fwrite(&user, sizeof(usuario), 1, pointer);
}
void mostrarUsuarios(FILE *pointer) {
    usuario user;

    rewind(pointer);
    fread(&user, sizeof(usuario), 1, pointer);
    while(!(feof(pointer))) {
        printf("Plataforma: %s\n", user.plataforma);
        printf("Email: %s\n", user.email);
        printf("Nombre de usuario: %s\n", user.nom_usuario);
        printf("Contraseña: %s\n", user.password);
        fread(&user, sizeof(usuario), 1, pointer);
        printf("\n");
    }
    printf("\n");
}