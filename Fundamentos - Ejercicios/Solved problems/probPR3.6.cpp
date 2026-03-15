#include <stdio.h>

int main() {
    long int first, sec = 1, next, i;

    for(i = 0; i <= 50; i++) {
        next = first + sec;
        first = sec;
        sec = next;
        printf("%ld ", next);
    }
}