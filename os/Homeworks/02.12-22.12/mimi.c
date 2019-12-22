//--------------------------------------------
// NAME: Petar-Gabriel Matev
// CLASS: XIb
// NUMBER: 22
// PROBLEM: #2
// FILE NAME: main.c
// FILE PURPOSE:
// shell
//---------------------------------------------

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

char** parse_cmdline(const char* cmdline){
    char** array;
    array = malloc(sizeof(char*)*1);
    array[0] = malloc(sizeof(char)*1);
    char delim[] = " ";
    char *ptr = strtok(cmdline, delim);
    while(ptr != NULL)
	{
        printf("%s", ptr);
		ptr = strtok(NULL, delim);
	}

    return array;
}

int main()
{
	char *input;
    size_t size = 32;
    input = (char *)malloc(size * sizeof(char));
    getline(&input,&size,stdin);

	// char delim[] = " ";
	// char *ptr = strtok(input, delim);


    pid_t pid;
    int status;

	// while(ptr != NULL)
	// {

	// 	ptr = strtok(NULL, delim);
	// }
	return 0;
}