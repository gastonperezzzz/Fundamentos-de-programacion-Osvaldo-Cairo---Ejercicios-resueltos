#include <stdio.h>
#include <string.h>

void deleteNewLine(char *string);

const int max_chars = 50;

int main() {
    char cad1[max_chars], cad2[max_chars], cad3[max_chars * 2];
    int i = 0, j = 0, k = 0, cont = 0;
    bool flag = true;

    printf("Ingrese la primera cadena de caracteres: ");
    fgets(cad1, sizeof(cad1), stdin);
    deleteNewLine(cad1);

    printf("Ingrese la segunda cadena de caracteres: ");
    fgets(cad2, sizeof(cad2), stdin);
    deleteNewLine(cad2);

    while(cont < max_chars * 2) {
        if(flag) {
            while(cad1[i] != '\0') {
                cad3[j] = cad1[i];
                j++;
                if(cad1[i] == ' ') {
                    i++;
                    break;
                }
                if(cad1[i + 1] == '\0') {
                    cad1[i + 1] = ' ';
                }
                i++;
            }
            flag = false;
        }
        else {
            while(cad2[k] != '\0') {
                cad3[j] = cad2[k];
                j++;
                if(cad2[k] == ' ') {
                    k++;
                    break;
                }
                else if(cad2[k + 1] == '\0') {
                    cad2[k + 1] = ' '; 
                }
                k++;
            }
            flag = true;
        }
        cont++;
    }
    
    puts(cad3);

    return 0;
}

void deleteNewLine(char *string) {
    if(string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }
}