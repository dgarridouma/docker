// cpu_hog.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Consumiendo CPU al 100%%...\n");
    printf("Presiona Ctrl+C para detener\n");
    
    volatile long long counter = 0;
    while (1) {
        counter++;
        if (counter % 100000000 == 0) {
            printf("Iteraciones: %lld\n", counter);
        }
    }
    return 0;
}