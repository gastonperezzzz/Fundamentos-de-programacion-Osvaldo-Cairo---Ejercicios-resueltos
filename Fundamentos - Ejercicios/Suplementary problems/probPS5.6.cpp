#include <stdio.h>

void loadVec(float *, int);
void printVec(float *, int);
float promGeneral(float *, int);
float percentApproved(float *, int);
int bestStudents(float *, int);

int main() {
    int n;

    do {
        printf("Ingrese el tamaño del array: ");
        scanf("%d", &n);
        if(n < 1 || n > 100) {
            printf("Error: tamaño invalido.\n");
        }
    } while(n < 1 || n > 100);

    float alumnos[n];

    loadVec(alumnos, n);
    printf("El promedio general es: %.2f\n", promGeneral(alumnos, n));
    printf("El porcentaje de aprobados es del %.2f porciento.\n", percentApproved(alumnos, n));
    printf("Alumnos con puntuacion o igual a 1500: %d\n", bestStudents(alumnos, n));

    return 0;
}
void loadVec(float *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Ingrese un valor para la posicion [%d]: ", i);
        scanf("%f", &arr[i]);
    }
}
void printVec(float *arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("Position [%d]. %f\n", i, arr[i]);
    }
}
float promGeneral(float *arr, int size) {
    float sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (sum / size);
}
float percentApproved(float *arr, int size) {
    int aprob = 0;
    float percent;
    for(int i = 0; i < size; i++) {
        if(arr[i] > 1300) {
            aprob++;
        }
    }
    percent = ((float)aprob / size) * 100;
    return percent;
}
int bestStudents(float *arr, int size) {
    int best_student = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] >= 1500) {
            best_student++;
        }
    }
    return best_student;
}