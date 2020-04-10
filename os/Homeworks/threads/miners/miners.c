#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
long in_storage = 0;
int ticks_per_unit = 20;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* mine(void* arg){
    long counter = *(long*)arg;
    for (int i = 0; i < ticks_per_unit; i++){
        pthread_mutex_lock(&mutex);
        in_storage += 10;
        pthread_mutex_unlock(&mutex);
        printf("Miner %ld gathered 10 gold\n", counter + 1);
        sleep(2);
    }
    return NULL;
}

void* trade(void* arg){
    long counter = *(long*)arg;
    for (int i = 0; i < ticks_per_unit; i++) {
        if (in_storage > 0) {
            pthread_mutex_lock(&mutex);
            in_storage -= 10;
            pthread_mutex_unlock(&mutex);
            printf("Trader %ld sold 10 gold\n", counter + 1);
        }
        else {
            printf("The warehouse is empty, cannot sell\n");
        }
        sleep(2);
    }
    return NULL;
}

int main(int argc, char** argv){

    long miners = 1, traders = 1;
    if(argc == 3){
        miners = atoi(argv[1]);
        traders = atoi(argv[2]);
    }

    pthread_t threads_miners[miners];
    pthread_t threads_traders[traders];
    for (long i = 0; i < miners; i++){
        if(pthread_create(&threads_miners[i], NULL, mine, (void*)i) == -1){
            perror("pthreat_create");
            return 1;
        }
    }

    for (long i = 0; i < miners; i++){
        if(pthread_join(threads_miners[i], NULL) == -1){
            perror("pthread_join");
            return 1;
        }
    }

    for (long i = 0; i < traders; i++){
        if(pthread_create(&threads_traders[i], NULL, trade, (void*)i) == -1){
            perror("pthreat_create");
            return 1;
        }
    }

    for (long i = 0; i < traders; i++){
        if(pthread_join(threads_traders[i], NULL) == -1){
            perror("pthread_join");
            return 1;
        }
    }
    
    printf("Gold: %ld\n", in_storage);
    return 0;
}