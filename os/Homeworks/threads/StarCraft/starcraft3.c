//--------------------------------------------
// NAME: Georgi Lyubenov    
// CLASS: 11b
// NUMBER: 10
// PROBLEM: #3
// FILE NAME: starcraft3.c
// FILE PURPOSE:
// prototype of the game Star Craft 
//---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define WALKING 3000
#define TRANSPORTING 2000

int count_of_workers = 5;
int count_of_soldiers = 0;
int count_of_mineral_blocks = 2;
int* minerals_blocks;

pthread_t* workers;
pthread_mutex_t unload_minerals;
pthread_mutex_t train_woker;
// pthread_mutex_t train_soldier;
pthread_mutex_t* mining_minerals;
pthread_mutex_t current_minerals;

void init(int count_of_mineral_blocks){
    int* minerals_blocks = malloc(sizeof(int) * count_of_mineral_blocks);
    for (int i = 0; i < count_of_mineral_blocks; i++){
            minerals_blocks[count_of_mineral_blocks] = 500;
        }

    if(pthread_mutex_init(&unload_minerals, NULL) != 0){
        perror("pthread_mutex_init");
    }

    if(pthread_mutex_init(&train_woker, NULL) != 0){
        perror("pthread_mutex_init");
    }

    for (int i = 0; i < count_of_mineral_blocks; i++){
        if(pthread_mutex_init(&mining_minerals[i], NULL) != 0){
            perror("pthread_mutex_init");
        }
    }
    
    workers = malloc(sizeof(pthread_t) * count_of_workers);
    for (int i = 0; i < count_of_workers; i++){
        if(pthread_create(&workers[i], NULL, mine, (void*)i) != 0){
            perror("pthread_create");
        }
    }
    
    if(pthread_mutex_init(&current_minerals, NULL) != 0){
        perror("pthread_mutex_init");
    }
}
void* mine(void* arg){
    
    
    
}

int main(int argc, char** argv){
    if(argc == 2){
        count_of_mineral_blocks = atoi(argv[1]);
    }
}