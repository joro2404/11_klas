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
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//--------------------------------------------
// FUNCTION: parse_cmdline
// предназначение на функцията: to make from a string an array of strings separated by ' '
// PARAMETERS: one string
//----------------------------------------------
char** parse_cmdline (const char* cmdline ) {
    
    char** help;
    help[0] = malloc(sizeof(char));
    int count_of_words = 0;
    int count_of_chars = 0;

    for (int i = 0; i < strlen(cmdline); i++){
        if(cmdline[i] == ' '){
            printf("test\n");
            count_of_chars = 0;
            count_of_words++;
            help[count_of_words] = malloc(sizeof(char));
        }
        else{
            help[count_of_words][count_of_chars] = cmdline[i];
            printf("test\n");
            count_of_chars++;
            help[count_of_words] = realloc(help[count_of_chars], sizeof(char));
        }
    }

    return help;
    
}

int main(){

    // char* test = "/bin/ls -l /usr/include";
    char** result = parse_cmdline("/bin/ls -l /usr/include");

    for (int j = 0; j<3; j++){
        printf("%s", result[j]);
        printf("\n");
    }
}