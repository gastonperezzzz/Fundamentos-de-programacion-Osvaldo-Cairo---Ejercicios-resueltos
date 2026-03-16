#include <stdio.h>
#include <string.h>

main() {

    char text1[20], text2[20];

    printf ("Ingrese una cadena de texto: ");
    fgets(text1, sizeof(text1), stdin);
    text1[strcspn(text1, "\n")] = 0;

    printf ("Ingrese otra cadena de texto: ");
    fgets(text2, sizeof(text2), stdin);
    text2[strcspn(text2, "\n")] = 0;

    if (strcmp(text1, text2) == 0) {
        printf ("Las cadenas son iguales...");
    } else {
        printf ("Las cadenas son distintas...\n");
        if (strcmp(text1, text2) < 0) {
            printf ("%s esta antes que %s...", text1, text2);
        } else {
            printf ("%s esta antes que %s...", text2, text1);
        }
    }
}