//--------------------------------------------
// NAME: Patrick Mihaylov
// CLASS: XIb
// NUMBER: 21
// PROBLEM: #3
// FILE NAME: starcraft.c
// FILE PURPOSE:
//--------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

int *crystals, minerals_arg, mined_minerals=0, trained_marines=0, are_empty=0;
long workers_count=5;
pthread_mutex_t *minerals, command_center;
pthread_t *workers, input;

void* digging(void *worker_id);
void* input_fn();

int main(int argc, char **argv){
    minerals_arg = 0;

    if(argc > 1){
       minerals_arg = atoi(argv[1]);
    } else {
        minerals_arg = 2;
    }

    minerals = (pthread_mutex_t*) malloc(sizeof(pthread_mutex_t)*minerals_arg);
    crystals = (int*) malloc(sizeof(int)*minerals_arg);
    workers = (pthread_t*) malloc(sizeof(pthread_t)*workers_count);

    pthread_mutex_init(&command_center, NULL);
    for(long i = 0; i < minerals_arg; i++){
        crystals[i] = 500;
        pthread_mutex_init(&minerals[i], NULL);
    }

    if(pthread_create(&input, NULL, input_fn, NULL)!=0) {
        perror("pthread_create");
        exit(1);
    }
    for(long i = 0; i < workers_count; i++){
        if(pthread_create(&workers[i], NULL, digging, (void*) i+1)!=0) {
            perror("pthread_create");
            exit(1);
        }
    }

    if(pthread_join(input, NULL)!=0) {
        perror("pthread_join");
        exit(1);
    }
    for (long i = 0; i < workers_count; i++){
        if(pthread_join(workers[i], NULL)!=0){
            perror("pthread_join");
            exit(1);
        }
    }

    pthread_mutex_destroy(&command_center);
    for(long i = 0; i < minerals_arg; i++){
        pthread_mutex_destroy(&minerals[i]);
    }

    printf("Map minerals %d, player minerals %d, SCVs %ld, Marines %d\n", minerals_arg*500, mined_minerals, workers_count, trained_marines);
    free(workers);
    free(crystals);
    free(minerals);
    return 0;
}

void* digging(void* id){
    while(1){
        for (long i = 0; i < minerals_arg;){
            sleep(3); //simulira vreme za tursene
            int final_kopane = 0;
            pthread_mutex_lock(&minerals[i]);
            if(crystals[i] > 0){
                pthread_mutex_unlock(&minerals[i]);
                if(pthread_mutex_trylock(&minerals[i]) == 0) {
                    printf("SCV %ld is mining from mineral block %ld\n", (long) id, i+1);
                    if(crystals[i] >= 8){
                        final_kopane = 8;
                        crystals[i] -= 8;
                    } else if(crystals[i] < 8 && crystals[i] > 0) {
                        final_kopane = 4;
                        crystals[i] -= 4; //poslednite 4 ostanali kristala
                    }
                    pthread_mutex_unlock(&minerals[i]);

                    printf("SCV %ld is transporting minerals\n", (long) id);
                    sleep(2); //simulira vremeto za nosene

                    pthread_mutex_lock(&command_center);   
                    mined_minerals += final_kopane;
                    printf("SCV %ld delivered minerals to the Command center\n", (long) id);
                    pthread_mutex_unlock(&command_center);
                }
            } else {
                pthread_mutex_unlock(&minerals[i]);
                i++;
            }
        }
        for (long i = 0; i < minerals_arg; i++){
            pthread_mutex_lock(&minerals[i]);
            if(crystals[i] <= 0){
                are_empty++;
            }
            pthread_mutex_unlock(&minerals[i]);
        }
        
        if(are_empty == minerals_arg){
            return NULL;
        }
        are_empty = 0;
    }
}

void* input_fn(){
    while(1){
        char ch = getchar(); getchar();
        switch(ch){
            case 's':
                pthread_mutex_lock(&command_center);
                if(mined_minerals >= 50){
                    pthread_mutex_unlock(&command_center);
                    workers = (pthread_t*) realloc(workers, (++workers_count)*sizeof(pthread_t));
                    sleep(4); //4 sekundi shte sa ni nujni
                    if(pthread_create(&workers[workers_count-1], NULL, digging, (void*) workers_count)!=0){
                        perror("pthread_create");
                        exit(1);
                    }
                    printf("SCV good to go, sir.\n");
                    pthread_mutex_lock(&command_center);
                    mined_minerals -= 50;
                    pthread_mutex_unlock(&command_center);
                } else {
                    pthread_mutex_unlock(&command_center);
                    printf("Not enough minerals.\n");
                }
                break;
            case 'm':
                pthread_mutex_lock(&command_center);
                if(mined_minerals >= 50){
                    pthread_mutex_unlock(&command_center);
                    sleep(1);
                    trained_marines++;
                    printf("You wanna piece of me, boy?\n");
                    pthread_mutex_lock(&command_center);
                    mined_minerals -= 50;
                    pthread_mutex_unlock(&command_center);
                } else {
                    pthread_mutex_unlock(&command_center);
                    printf("Not enough minerals.\n");
                }
                break;
            default:
                break;
        }
        if(trained_marines == 20) {
            return NULL;
        }
    }   
}