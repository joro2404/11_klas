//------------------------------------------------------------------------
// NAME: Georgi Lyubenov
// CLASS: XIb
// NUMBER: 10
// PROBLEM: #1
// FILE NAME: prime.c
// FILE PURPOSE:
// to use threadsd to print nubmer of primes till N
// ...
//------------------------------------------------------------------------

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define NUM_OF_THREADS 500

//------------------------------------------------------------------------
// FUNCTION: get_primes
// to get all the rime numers till N
// PARAMETERS:
// one number to count to
//------------------------------------------------------------------------
void* get_primes(void* num){

    long n = (long)num;
    long total;
    for (long  i = 2; i < n; i++){
        int counter = 0;
        for (long j = 1; j <= i ; j++){
            if(i % j == 0)counter++;
        }
        if(counter == 2)total++;
    }

    printf("Number of primes for N=%ld is %ld\n", n, total);
}

int main() {

	int num_of_threads = 0;
    
    void* return_value;
    char command[24];
    char number[10];

    while(1){

        long n = 0;
		num_of_threads++;
		pthread_t threads[num_of_threads];
        fgets(command, 24, stdin);
        if(command != 'e' && command[0] != 'p')printf("Supported commands:\np N - Starts a new calculation for the number of primes from 1 to N\ne - Waits for all calculations to finish and exits\n");
        else if(command[0] == 'e')pthread_exit(NULL);
        else if(command[0] == 'p'){
            for (int i = 2; command[i] != '\0'; i++){
                number[i-2] = command[i];
            }
            
            n = (long)atoi(number);
            if(pthread_create(&threads[0], NULL, get_primes, (void*)n) == -1){
                perror("pthread_create");
                return 1;
            }
        }
        printf("Prime calculation started for N=%ld\n", n);
    }

}
