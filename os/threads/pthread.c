#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_OF_THREADS 5

void* printHello(void* arg){

    long thread_id = (long)arg;
    printf("Hello from thread %ld!\n", thread_id);
    return (void*)(thread_id*thread_id);
}

int main() {

    pthread_t threads[NUM_OF_THREADS];
    void* return_value;

    for (long i = 0; i < NUM_OF_THREADS; i++){
    
        if(pthread_create(&threads[0], NULL, printHello, (void*)i) == -1){
            perror("pthread_create");
            return 1;
        }

        if(pthread_join(threads[i], &return_value) == -1){

            perror("pthread_join");
            return 2;
        }
        long return_value_long = (long)return_value;
        printf("Return Value of thread %ld is %ld\n", i, return_value_long);
    }

    printf("Hello!\n");
    return 0;

}