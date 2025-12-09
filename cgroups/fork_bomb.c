// fork_bomb.c - VERSION CONTROLADA
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int num_forks = 20;
    if (argc > 1) num_forks = atoi(argv[1]);
    
    printf("Intentando crear %d procesos...\n", num_forks);
    
    for (int i = 0; i < num_forks; i++) {
        pid_t pid = fork();
        
        if (pid < 0) {
            printf("Fork #%d FALLÓ (límite alcanzado)\n", i+1);
            break;
        } else if (pid == 0) {
            // Proceso hijo
            printf("Proceso hijo #%d creado (PID: %d)\n", i+1, getpid());
            sleep(30);
            exit(0);
        } else {
            // Proceso padre
            printf("Fork #%d exitoso (PID hijo: %d)\n", i+1, pid);
        }
        usleep(100000); // 0.1 segundos
    }
    
    // Esperar a todos los hijos
    while (wait(NULL) > 0);
    
    return 0;
}