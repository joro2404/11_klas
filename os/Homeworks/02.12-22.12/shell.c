//------------------------------------------------------------------------
// NAME: Georgi Lyubenov
// CLASS: 11b
// NUMBER: 10
// PROBLEM: #1
// FILE NAME: shell.c
// FILE PURPOSE: to create shell terminal
//------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//--------------------------------------------
// FUNCTION: parse_cmdline
// предназначение на функцията: to make from a string an array of strings separated by ' '
// PARAMETERS: one string
//----------------------------------------------
char **parse_cmdline(const char *cmdline){

    // help is 2 diemnssional array to store the arrays of strings
    //I use count_of_chars and count_of_words to track and help with the index
    char **help;
    int count_of_chars = 0;
    int count_of_words = 0;
    help = malloc(sizeof(char *) * 1);
    help[0] = malloc(sizeof(char) * 1);

    for (int i = 0; i < strlen(cmdline); i++){
        //if we have space that means we have new word
        if (cmdline[i] == ' ' || cmdline[i] == '\n'){
            help[count_of_words][count_of_chars] = '\0';
            count_of_words++;
            help = realloc(help, (count_of_words + 1) * sizeof(char *));
            if (cmdline[i] == '\n')break;
            help[count_of_words] = malloc(sizeof(char) * 1);
            count_of_chars = 0;
        }
        //adding the chars of the string pretty simple
        else{
            help[count_of_words][count_of_chars] = cmdline[i];
            count_of_chars++;
            help[count_of_words] = realloc(help[count_of_words], (count_of_chars + 1) * sizeof(char));
        }
    }

    help[count_of_words] = NULL;
    return help;
}

//--------------------------------------------
// FUNCTION: free_memory
// предназначение на функцията: to free the allocated memory for each of the parameters
// PARAMETERS: array of string(arguments) and a input from the console
//----------------------------------------------
void free_memory(char **argv, char *input){
    free(input);
    for (int i = 0; argv[i] != NULL; i++){
        free(argv[i]);
    }
    free(argv);
}

int main(){

    while (1){
        printf("$ ");
        char *input = NULL;
        size_t size = 0;
        //handling Ctrl+D
        if (getline(&input, &size, stdin) <= 0){
            free(input);
            break;
        }
        //handling Enter - to give a new line not throw an error
        if (strlen(input) <= 1){
            free(input);
            continue;
        }

        char **argv = parse_cmdline(input);

        //creating the child process
        pid_t pid = fork();
        
        //handling errors
        if (pid == 0){
            int check = execvp(argv[0], argv);
            if (check != 0){
                perror(argv[0]);
                free_memory(argv, input);
                break;
            }
        }
        else if (pid == -1){
            perror("fork");
        }
        //waiting the child to finish the process and then kill it
        wait(&pid);
        //using function to free the memory
        free_memory(argv, input);
    }
}