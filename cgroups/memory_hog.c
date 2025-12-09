// memory_hog.c
// Programa que consume memoria agresivamente
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MB (1024 * 1024)

int main(int argc, char *argv[]) {
    int megabytes = 100; // Por defecto 100MB
    
    if (argc > 1) {
        megabytes = atoi(argv[1]);
    }
    
    printf("Intentando consumir %d MB de memoria...\n", megabytes);
    
    for (int i = 0; i < megabytes; i++) {
        // Pedir 1MB
        char *ptr = malloc(MB);
        
        if (ptr == NULL) {
            printf("ERROR: malloc falló en %d MB\n", i);
            return 1;
        }
        
        // IMPORTANTE: Escribir en la memoria para que se asigne de verdad
        memset(ptr, 'A', MB);
        
        printf("Consumido: %d MB\n", i + 1);
        fflush(stdout);
        
        // Pausa breve para ver el progreso
        usleep(100000); // 0.1 segundos
    }
    
    printf("Memoria asignada exitosamente. Esperando...\n");
    sleep(30); // Mantener la memoria 30 segundos
    
    return 0;
}

/* 
 * INSTRUCCIONES DE USO:
 * 
 * 1. COMPILAR:
 *    gcc -o memory_hog memory_hog.c
 * 
 * 2. CREAR CGROUP:
 *    sudo mkdir -p /sys/fs/cgroup/test_memory
 * 
 * 3. ESTABLECER LÍMITE DE 20MB:
 *    echo 20971520 | sudo tee /sys/fs/cgroup/test_memory/memory.max
 * 
 * 4. EJECUTAR EL PROGRAMA PIDIENDO 100MB (será matado):
 *    sudo sh -c "echo $$ > /sys/fs/cgroup/test_memory/cgroup.procs && ./memory_hog 100"
 * 
 * 5. VERIFICAR EL OOM KILL:
 *    cat /sys/fs/cgroup/test_memory/memory.events | grep oom_kill
 * 
 * 6. LIMPIAR:
 *    sudo rmdir /sys/fs/cgroup/test_memory
 * 
 * RESULTADO ESPERADO:
 * El programa imprimirá algo como:
 *   Consumido: 1 MB
 *   Consumido: 2 MB
 *   ...
 *   Consumido: 19 MB
 *   Consumido: 20 MB
 *   Killed
 */