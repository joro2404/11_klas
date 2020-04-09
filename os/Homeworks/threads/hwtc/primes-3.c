#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int is_prime(int n) {
    if (n <= 1)
        return 0;
    for (int i = 2; i < n; i++)
        if (n % i == 0) 
            return 0;
    return 1;
}

void* calc_primes(void* arg) {
    long n = (long)arg;
    long count = 0;
    for (long i = 2; i < n; i++) {
        if (is_prime(i))
            count++;
    }
    printf("Number of primes for N=%ld is %ld\n", n, count);
}

int main() {
    int num_of_threads = 0;
    while (1) {
        long number;
        char input[256];
        fgets(input, 256, stdin);
        if (input[0] != 'p' && input[0] != 'e') {
            printf("Supported commands:\np N - Starts a new calculation for the number of primes from 1 to N\ne - Waits for all calculations to finish and exits\n");
        }
        else if (input[0] == 'e') {
            pthread_exit(NULL);
        }
        else if (input[0] == 'p') {
            char input_number[256];
            for (int i = 2; i < strlen(input); i++) {
                input_number[i-2] = input[i];
                number = atoi(input_number);
            }
            num_of_threads++;
        }
        pthread_t threads[num_of_threads];
        if (pthread_create(&threads[num_of_threads - 1], NULL, calc_primes, (void*)number) == -1) {
            perror("pthread_create");
            return 1;
        }
        printf("Prime calculation started for N=%ld\n", number);
    }
    return 0;
}
