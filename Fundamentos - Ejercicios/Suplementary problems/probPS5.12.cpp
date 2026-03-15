#include <stdio.h>

void cargaVec(int *, int);
int palindromeVec(int *, int);
void printVec(int *, int);

int main() {
    int tam;

    do {
        printf("Ingrese el tamaño del array: ");
        scanf("%d", &tam);
        if(tam < 1 || tam > 100) {
            printf("Error: tamaño invalido.\n");
        }
    } while(tam < 1 || tam > 100);

    int vec[tam];

    cargaVec(vec, tam);

    if(palindromeVec(vec, tam)) {
        printf("El vector es palindrome.\n");
    }
    else {
        printf("El vector NO es palindrome.\n");
    }

    return 0;
}

int palindromeVec(int *arr, int size) {
    int vectest[size], i, pali = 0, flag = 0;
    for(i = 0; i < size; i++) {
        vectest[i] = arr[i];
    }
    for(i = 0; i < size; i++) {
        if(arr[i] == vectest[size - i - 1]) {
            pali++;
        }
    }
    if(pali == size) {
        flag = 1;
    }
    return flag;
}
void cargaVec(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%d", &arr[i]);
    }
}
void printVec(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Posicion [%d]: %d\n", i, arr[i]);
    }
}