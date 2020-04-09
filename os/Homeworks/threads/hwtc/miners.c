//--------------------------------------------
// NAME: Veselin Angelov
// CLASS: XI b
// NUMBER: 7
// PROBLEM: #1
//---------------------------------------------
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t lock;

int sum = 0;

void* mine(void* arg) {
    long tid = (long)arg;
    for (int i = 0; i < 20; i++) {
        pthread_mutex_lock(&lock);
        sum += 10;
        pthread_mutex_unlock(&lock);
        printf("Miner %ld gathered 10 gold\n", tid + 1);
        sleep(2);
    }
    return NULL;
}

void* sell(void* arg) {
    long tid = (long)arg;
    for (int i = 0; i < 20; i++) {
        if (sum > 0) {
            pthread_mutex_lock(&lock);
            sum -= 10;
            pthread_mutex_unlock(&lock);
            printf("Trader %ld sold 10 gold\n", tid + 1);
        }
        else {
            printf("The warehouse is empty, cannot sell\n");
        }
        sleep(2);
    }
    return NULL;
}

int main(int argc, char **argv) {
    long miners = 1;
    long traders = 1;
    if (argc == 3) {
        miners = atoi(argv[1]);
        traders = atoi(argv[2]);
    }
    
    pthread_t threads_m[miners];
    pthread_t threads_t[traders];
    for (long i = 0; i < miners; i++) {
        if (pthread_create(&threads_m[i], NULL, mine, (void*)i) == -1) {
            perror("pthread_create");
            return 1;
        }
    }
    for (long i = 0; i < miners; i++) {
        if (pthread_join(threads_m[i], NULL) == -1) {
            perror("pthread_join");
            return 1;
        }
    }
    for (long i = 0; i < traders; i++) {
        if (pthread_create(&threads_t[i], NULL, sell, (void*)i) == -1) {
            perror("pthread_create");
            return 1;
        }
    }
    for (long i = 0; i < traders; i++) {
        if (pthread_join(threads_t[i], NULL) == -1) {
            perror("pthread_join");
            return 1;
        }
    }
    printf("Gold: %d\n", sum);
    return 0;
}