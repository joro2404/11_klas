#include <pthread.h>
#include <stdio.h>

#define DRIVERS 20
#define CARS 5

pthread_mutex_t cars[CARS];

void* take(void* arg) {
    long counter = (long)arg;
    while (1) {
        for (int i = 0; i < CARS; i++) {
            if (pthread_mutex_trylock(&cars[i]) == 0) {
                printf("Buyer %ld takes car %d.\n", counter, i);
                if (pthread_mutex_unlock(&cars[i]) == -1) {
                    perror("pthread mutex unlock failed");
                }
                printf("Buyer %ld returns car %d.\n", counter, i);
                return NULL;
            }
        }
    }
    return NULL;
}

int main() {
    pthread_t drivers[DRIVERS];

    for (int i = 0; i < CARS; i++) {
        pthread_mutex_init(&cars[i], NULL);
    }
    
    for (long i = 0; i < DRIVERS; i++) {
        pthread_create(&drivers[i], NULL, take, (void*)(i));
    }

    for (long i = 0; i < DRIVERS; i++) {
        pthread_join(drivers[i], NULL);
    }
    
    for (int i = 0; i < CARS; i++) {
        pthread_mutex_destroy(&cars[i]);
    }
    
    return 0;
}