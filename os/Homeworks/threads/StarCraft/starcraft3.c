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

long count_of_workers = 5;
int count_of_soldiers = 0;
int count_of_mines = 2;
int mines[MAX_MINERALS];

pthread_t workers[MAX_TROOPS];
pthread_mutex_t unload_minerals;
pthread_mutex_t train_worker;
pthread_mutex_t train_soldier;
pthread_mutex_t current_minned_mines[MAX_MINERALS];
pthread_mutex_t command_center_storage;

int current_minerals;

//--------------------------------------------
// FUNCTION: mine (име на функцията)
// implementng the logic of the workers and their work
// PARAMETERS: single parameter to keep track of the id of the threa
//----------------------------------------------

void* mine(void* arg){
    long id = (long)arg;

    // for (int i = 0; i < count_of_mines; i++){
    //     mines[i] = MAX_MINERALS;
    // }
    
    // printf("%d - %d\n", mines[0], mines[1]);
    while (1){
        sleep(WALKING);

        int current_minne = 0;
        while (1){
            current_minne %= count_of_mines;

            if (mines[current_minne] > 0 && pthread_mutex_trylock(&current_minned_mines[current_minne]) == 0){
                break;
            }
            else{//checking if every mine is empty
                int checker = 0;
                for (int i = 0; i < count_of_mines; i++){
                    if(mines[i] == 0)checker++;
                }
                if(checker == count_of_mines)return NULL;
                
            }
            current_minne++;
            sleep(WALKING);
        }
        
        printf("SCV %ld is mining from mineral block %d\n", id+1, current_minne+1);
    
        
        // printf("In mine %d, ther is %d crystals\n", current_minne, mines[current_minne]);
        //checking if the mine has less minerals then MINNED
        if(mines[current_minne] < MINNED){
            
            int to_be_adedd = mines[current_minne];
            mines[current_minne] = 0;
            if(pthread_mutex_unlock(&current_minned_mines[current_minne]) != 0){
                perror("pthread_mutex_unlock");
            }
            
            if(pthread_mutex_lock(&command_center_storage) != 0){
                perror("pthread_mutex_lock");
            }

            current_minerals += to_be_adedd;
            

            if(pthread_mutex_unlock(&command_center_storage) != 0){
                perror("pthread_mutex_unlock");
            }
            
        }

        // if mine has more minerals than MINNED
        else{
            mines[current_minne] -= MINNED;
            if(pthread_mutex_unlock(&current_minned_mines[current_minne]) != 0){
                perror("pthread_mutex_unlock");
            }

            if(pthread_mutex_lock(&command_center_storage) != 0){
                perror("pthread_mutex_lock");
            }

            current_minerals += MINNED;
            
            // printf("Current minerls in the command cneter %d\n", current_minerals);
            if(pthread_mutex_unlock(&command_center_storage) != 0){
                perror("pthread_mutex_unlock");
            }
        }

        
        printf("SCV %ld delivered minerals to the Command center\n", id+1);
    }
    
}

//--------------------------------------------
// FUNCTION: build_soldier (име на функцията)
// simpleexecution of player's command to build soldier
// PARAMETERS: None
//----------------------------------------------
void build_soldier(){

    // if(pthread_mutex_lock(&train_soldier) != 0){
    //     perror("pthread_mutex_lock");
    // }

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

    // if(pthread_mutex_unlock(&train_soldier) != 0){
    //     perror("pthread_mutex_unlock");
    // }
}

//--------------------------------------------
// FUNCTION: build_worker (име на функцията)
// simpleexecution of player's command to build worker
// PARAMETERS: None
//----------------------------------------------
void build_worker(){
    
    // if(pthread_mutex_lock(&train_worker) != 0){
    //     perror("pthread_mutex_lock");
    //     // exit(1);
    // }

    if(pthread_mutex_lock(&command_center_storage) != 0){
        perror("pthread_mutex_lock");
        // exit(1);
    }
    
    if(current_minerals < COST_OF_WORKER){
        if(pthread_mutex_unlock(&command_center_storage) != 0){
            perror("pthread_mutex_unlock");
        }
        printf("Not enough minerals.\n");
    }
    else{

        current_minerals -= COST_OF_WORKER;
        if(pthread_mutex_unlock(&command_center_storage) != 0){
            perror("pthread_mutex_unlock");
        }
        sleep(TRAINING_TIME_WORKER);
        count_of_workers++;

        // workers = (pthread_t*)realloc(workers, sizeof(pthread_t) * count_of_workers);
        if(pthread_create(&workers[count_of_workers-1], NULL, mine, (void*)(count_of_workers-1)) != 0){
            perror("pthread_create");
        }
        printf("SCV good to go, sir.\n");
    }

    // if(pthread_mutex_unlock(&train_worker) != 0){
    //     perror("pthread_mutex_unlock");
    // }
}

int main(int argc, char** argv){
    if(argc == 2){
        count_of_mines = atoi(argv[1]);
    }

    //setting up every mutex and thread
    // mines = (int*)malloc(sizeof(int) * count_of_mines);
    for (int i = 0; i < count_of_mines; i++){
        mines[i] = MAX_MINERALS;
        // printf("Mines %d get value -> %d\n", i, mines[i]);
    }
    

    // current_minned_mines = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * count_of_mines);
    for (int i = 0; i < count_of_mines; i++){
        if(pthread_mutex_init(&current_minned_mines[i], NULL) != 0){
            perror("pthread_mutex_init");
        }
    }
    
    
    if(pthread_mutex_init(&unload_minerals, NULL) != 0){
        perror("pthread_mutex_init");
    }

    if(pthread_mutex_init(&train_worker, NULL) != 0){
        perror("pthread_mutex_init");
    }

    for (int i = 0; i < count_of_mines; i++){
        if(pthread_mutex_init(&current_minned_mines[i], NULL) != 0){
            perror("pthread_mutex_init");
        }
    }
    // printf("test\n");


    // workers = (pthread_t*)malloc(sizeof(pthread_t) * count_of_workers);
    // printf("test\n");
    for (long i = 0; i < count_of_workers; i++){
        if(pthread_create(&workers[i], NULL, mine, (void*)i) != 0){
            perror("pthread_create");
            exit(1);
        }
        // printf("test\n");
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
        //((count_of_mines * MAX_MINERALS) == ((count_of_soldiers * COST_OF_SOLDIER) + ((count_of_workers - 5) * COST_OF_WORKER) + current_minerals))
        if(count_of_soldiers >= 20){
            if(pthread_mutex_unlock(&command_center_storage) != 0){
                perror("pthread_mutex_unlock");
            }
            break;
        }

        if(pthread_mutex_unlock(&command_center_storage) != 0){
            perror("pthread_mutex_unlock");
        }
        // for (int i = 0; i < count_of_mines; i++){
        //     printf("In mine %d, there is %d minerals\n", i+1, mines[i]);
        // }
        char input= getchar();getchar();
        // fgets(input, 1, stdin);
        // if(input[0] == 's'){
        //     build_worker();
        // }
        // if(input[0] == 'm'){
        //     build_soldier();
        // }
        switch(input){
            case 's':
                build_worker();
                break;
            case 'm':
                build_soldier();
                break;
            default:
                break;
        }
    }

    for (int i = 0; i < count_of_workers; i++){
        if (pthread_join(workers[i], NULL) != 0){
			perror("pthread_join");
            exit(1);
		}
    }
    
    printf("Map minerals %d, player minerals %d, SCVs %ld, Marines %d\n", count_of_mines * MAX_MINERALS, current_minerals, count_of_workers, count_of_soldiers);

    // for (int i = 0; i < count_of_mines; i++){
    //     printf("In mine %d, there is %d minerals\n", i+1, mines[i]);
    // }

    //waiting everything to finish, destroying and freeing
    if(pthread_mutex_destroy(&unload_minerals) != 0){
        perror("pthread_mutex_destroy");
    }
    

    if(pthread_mutex_destroy(&train_worker) != 0){
        perror("pthread_mutex_destroy");
    }

    for (int i = 0; i < count_of_mines; i++){
        if(pthread_mutex_destroy(&current_minned_mines[i]) != 0){
            perror("pthread_mutex_destroy");
        }
    }

    

    if(pthread_mutex_destroy(&command_center_storage) != 0){
        perror("pthread_mutex_destroy");
    }

    for (int i = 0; i < count_of_mines; i++){
        if(pthread_mutex_destroy(&current_minned_mines[i]) != 0){
            perror("pthread_mutex_destroy");
        }
    }

    // free(workers);
    // free(mines);
    // free(current_minned_mines);

    return 0;
}