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
#include <inttypes.h>

#define WALKING 3
#define TRANSPORTING 2
#define MINNED 8
#define MAX_MINERALS 500
#define MAX_TROOPS 200
#define COST_OF_SOLDIER 50
#define COST_OF_WORKER 50
#define TRAINING_TIME_SOLDIER 1
#define TRAINING_TIME_WORKER 4

int count_of_workers = 5;
int count_of_soldiers = 0;
int count_of_mineral_blocks = 2;
int* mineral_blocks;

pthread_t* workers;
pthread_mutex_t unload_minerals;
pthread_mutex_t train_worker;
// pthread_mutex_t train_soldier;
pthread_mutex_t* mining_minerals;
pthread_mutex_t command_center_storage;

int current_minerals;

//--------------------------------------------
// FUNCTION: mine (име на функцията)
// implementng the logic of the workers and their work
// PARAMETERS: single parameter to keep track of the id of the threa
//----------------------------------------------

void* mine(void* arg){int
    long id = (long)arg;

    int local_mineral_blocks[count_of_mineral_blocks];
    for (int i = 0; i < count_of_mineral_blocks; i++){
        local_mineral_blocks[i] = MAX_MINERALS;
    }
    
    while (1){
        sleep(WALKING);

        int current_block = 0;
        while (1){
            current_block %= count_of_mineral_blocks;

            if(local_mineral_blocks[current_block] > 0 && pthread_mutex_trylock(&mining_minerals[current_block]) == 0){
                break;
            }
            else{//checking if every mine is empty
                int checker = 0;
                for (int i = 0; i < count_of_mineral_blocks; i++){
                    if(local_mineral_blocks[i] == 0)checker++;
                }
                if(checker == count_of_mineral_blocks)return 0;
                
            }
            current_block++;
            sleep(WALKING);
        }
        
        printf("SCV %ld is mining from mineral block %d\n", id+1, current_block+1);
        
        if(pthread_mutex_unlock(&mining_minerals[current_block]) != 0){
            perror("pthread_mutex_unlock");
        }

        //checking if the mine has less minerals then MINNED
        if(mineral_blocks[current_block] < MINNED){
            mineral_blocks[current_block] = 0;
            
            if(pthread_mutex_lock(&command_center_storage) != 0){
                perror("pthread_mutex_lock");
            }

            current_minerals += local_mineral_blocks[current_block];

            if(pthread_mutex_unlock(&command_center_storage) != 0){
                perror("pthread_mutex_unlock");
            }
            local_mineral_blocks[current_block] = 0;
        }

        // if mine has more minerals than MINNED
        else{
            mineral_blocks[current_block] -= MINNED;
            local_mineral_blocks[current_block] -= MINNED;
            if(pthread_mutex_lock(&command_center_storage) != 0){
                perror("pthread_mutex_lock");
            }

            current_minerals += MINNED;

            if(pthread_mutex_unlock(&command_center_storage) != 0){
                perror("pthread_mutex_unlock");
            }
        }

        printf("SCV %ld is transporting minerals\n", id+1);
        sleep(TRANSPORTING);
        printf("SCV %ld delivered minerals to the Command center\n", id+1);
    }
    
    
}

//--------------------------------------------
// FUNCTION: build_soldier (име на функцията)
// simpleexecution of player's command to build soldier
// PARAMETERS: None
//----------------------------------------------
void build_soldier(){

    if(pthread_mutex_lock(&command_center_storage) != 0){
        perror("pthread_mutex_lock");
    }

    if(current_minerals < COST_OF_SOLDIER){
        if(pthread_mutex_unlock(&command_center_storage) != 0){
           perror("pthread_mutex_unlock");
        }
        printf("Not enough minerals.\n");
    }
    else{

        current_minerals -= COST_OF_SOLDIER;
        if(pthread_mutex_unlock(&command_center_storage) != 0){
            perror("pthread_mutex_unlock");
        }
        sleep(TRAINING_TIME_SOLDIER);
        printf("You wanna piece of me, boy?\n");
        count_of_soldiers++;
    }
}

//--------------------------------------------
// FUNCTION: build_worker (име на функцията)
// simpleexecution of player's command to build worker
// PARAMETERS: None
//----------------------------------------------
void build_worker(){
    if(pthread_mutex_lock(&command_center_storage) != 0){
        perror("pthread_mutex_lock");
    }
    if(pthread_mutex_lock(&train_worker) != 0){
        perror("pthread_mutex_lock");
    }

    if(current_minerals < COST_OF_WORKER){
        if(pthread_mutex_unlock(&command_center_storage) != 0){
            perror("pthread_mutex_unlock");
        }
        printf("Not enough minerals!\n");
    }
    else{

        current_minerals -= COST_OF_WORKER;
        if(pthread_mutex_unlock(&command_center_storage) != 0){
            perror("pthread_mutex_unlock");
        }
        count_of_workers++;

        workers = (pthread_t*)realloc(workers, sizeof(pthread_t) * count_of_workers);
        if(pthread_create(&workers[count_of_workers-1], NULL, mine, (void*)((intptr_t)(count_of_workers-1))) != 0){
            perror("pthread_create");
        }
        printf("SCV good to go, sir.\n");
    }
}

int main(int argc, char** argv){
    if(argc == 2){
        count_of_mineral_blocks = atoi(argv[1]);
    }

    //setting up every mutex and thread
    mineral_blocks = malloc(sizeof(int) * count_of_mineral_blocks);
    for (int i = 0; i < count_of_mineral_blocks; i++){
        mineral_blocks[count_of_mineral_blocks] = MAX_MINERALS;
    }
    

    mining_minerals = malloc(sizeof(pthread_mutex_t) * count_of_mineral_blocks);
    for (int i = 0; i < count_of_mineral_blocks; i++){
        if(pthread_mutex_init(&mining_minerals[i], NULL) != 0){
            perror("pthread_mutex_init");
        }
    }
    
    
    if(pthread_mutex_init(&unload_minerals, NULL) != 0){
        perror("pthread_mutex_init");
    }

    if(pthread_mutex_init(&train_worker, NULL) != 0){
        perror("pthread_mutex_init");
    }

    for (int i = 0; i < count_of_mineral_blocks; i++){
        if(pthread_mutex_init(&mining_minerals[i], NULL) != 0){
            perror("pthread_mutex_init");
        }
    }
    printf("test\n");


    workers = malloc(sizeof(pthread_t) * count_of_workers);
    // printf("test\n");
    for (intptr_t i = 0; i < count_of_workers; i++){
        if(pthread_create(&workers[i], NULL, mine, (void*)i) != 0){
            perror("pthread_create");
        }
        printf("test\n");
    }
    // printf("test\n");


    if(pthread_mutex_init(&command_center_storage, NULL) != 0){
        perror("pthread_mutex_init");
    }

    //logic
    while(1){

        if(pthread_mutex_lock(&command_center_storage) != 0){
            perror("pthread_mutex_lock");
        }
        if(count_of_soldiers >= 20 && ((count_of_mineral_blocks * MAX_MINERALS) == ((count_of_soldiers * COST_OF_SOLDIER) + ((count_of_workers - 5) * COST_OF_WORKER) + current_minerals))){
            if(pthread_mutex_lock(&command_center_storage) != 0){
                perror("pthread_mutex_lock");
            }
            break;
        }

        if(pthread_mutex_lock(&command_center_storage) != 0){
            perror("pthread_mutex_lock");
        }

        char input[1];
        fgets(input, 1, stdin);
        if(input[0] == 's'){
            build_worker();
        }
        if(input[0] == 'm'){
            build_soldier();
        }
    }

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", count_of_mineral_blocks * MAX_MINERALS, current_minerals, count_of_workers, count_of_soldiers);

    //waiting everything to finish, destroying and freeing
    if(pthread_mutex_destroy(&unload_minerals) != 0){
        perror("pthread_mutex_destroy");
    }

    if(pthread_mutex_destroy(&train_worker) != 0){
        perror("pthread_mutex_destroy");
    }

    for (int i = 0; i < count_of_mineral_blocks; i++){
        if(pthread_mutex_destroy(&mining_minerals[i]) != 0){
            perror("pthread_mutex_destroy");
        }
    }

    for (int i = 0; i < count_of_workers; i++){
        if (pthread_join(workers[i], NULL) != 0){
			perror("pthread_join");
		}
    }

    if(pthread_mutex_destroy(&command_center_storage) != 0){
        perror("pthread_mutex_destroy");
    }

    for (int i = 0; i < count_of_mineral_blocks; i++){
        if(pthread_mutex_destroy(&mining_minerals[i]) != 0){
            perror("pthread_mutex_destroy");
        }
    }

    free(workers);
    free(mineral_blocks);
    free(mining_minerals);

    return 0;
}