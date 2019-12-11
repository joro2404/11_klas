//------------------------------------------------------------------------
// NAME: Aneta Tsvetkova
// CLASS: XIa
// NUMBER: 3
// PROBLEM: pass
// FILE NAME: shell.c
// FILE PURPOSE:
// shell terminal
//------------------------------------------------------------------------
 
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
//------------------------------------------------------------------------
// FUNCTION: parse_cmdline
// the same as split(..., ' ');
// PARAMETERS:
// const char* cmdline - cstring to be parsed 
// int *args_size - number of the parsed args
//------------------------------------------------------------------------
char** parse_cmdline(const char* cmdline, int *args_size);
 
int main(int argc, char const *argv[])
{
    while(1)
    {
        char** arguments;
        char* line;
        size_t size = 0;
        int args_in_arguments;
 
        printf("$ ");
        if (getline(&line, &size, stdin) < 0)
        {
            free(line);
            break;
        }
 
        arguments = parse_cmdline(line, &args_in_arguments);
 
        int child_process = fork();
 
        if (child_process == 0)
        {
            int err = execvp(arguments[0], arguments) == -1;
            if (err)
            {
                perror(arguments[0]);
 
                free(line);
                for (int i = 0; i <= args_in_arguments; ++i)
                {
                    free(arguments[i]);
                }
                free(arguments);
                break;
            }
        }
        else if (child_process == -1)
        {
            perror("fork");
        }
 
        wait(&child_process);
 
        free(line);
        for (int i = 0; i <= args_in_arguments; ++i)
        {
            free(arguments[i]);
        }
        free(arguments);
    }
    return 0;
}
 
char** parse_cmdline(const char* cmdline, int *args_size)
{
    char** args;
    char* word;
    int size = strlen(cmdline);
    args = (char**)malloc(sizeof(char*) * size);
    word = (char*)malloc(sizeof(char) * 1);
    int arg = 0;
    int reall = 1;
 
    for (int i = 0, j = 0; i < size - 1; ++i, ++j)
    {
        if (cmdline[i] == ' ')
        {
            word[j] = '\0';
            if (strlen(word) != 0)
            {
                args[arg] = word;
                arg++;
                reall = 1;
                word = (char*)malloc(sizeof(char) * 1);
            }
            j = -1;
            continue;
        }
        word[j] = cmdline[i];
        word = (char*)realloc(word, sizeof(char) * ++reall);
    }
 
    args[arg] = word;
    *args_size = arg;
    return args;
}