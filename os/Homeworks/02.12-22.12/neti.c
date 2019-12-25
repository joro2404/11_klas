//--------------------------------------------
// NAME: Petar-Gabriel Matev
// CLASS: XIb
// NUMBER: 22
// PROBLEM: #2
// FILE NAME: shell.c
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

char** parse_cmdline(char* cmdline){
    //strtok makes a pointer(ptr) to every word after " "(delim) which then is char by char translated into an array(array)
    char** array;
    array = malloc(sizeof(char*)*1);
    array[0] = malloc(sizeof(char)*1);
    int counter = 0;
    char delim[] = " ";
    int i = 0;
    char *ptr = strtok(cmdline, delim);
    while(ptr != NULL)
	{
        printf("%ld\n", strlen(ptr));
        for(int i = 0; i < strlen(ptr)+1; i++){
            if(ptr[i] == '\n')continue; //this if fixes a problem where one of the elements of the array is "\n"
            array[counter] = realloc(array[counter], sizeof(char)*(i+1));
            
            if(i >= strlen(ptr)){
                array[counter][i] = '\0';
            }
            else{
                array[counter][i] = ptr[i];
            }
        }
        printf("%ld\n", strlen(array[0]));
        counter++;
        array = realloc(array, sizeof(char*)*(counter+1));
		ptr = strtok(NULL, delim);
	}
    array[counter] = NULL;
    return array;
}

int main()
{
    
    while(1){
        printf("$ ");
        //gets the stdin and translates it in a string (cmd)
        size_t size;
        char *cmd;
        cmd = (char *)malloc(size * sizeof(char));
        if(getline(&cmd,&size,stdin)<=0){
            return -1;
        }
        else{


            char** exec_array = parse_cmdline(cmd);
            for (int i = 0; exec_array[i] != NULL; i++){
                printf("%s\n",exec_array[i]);
            }
            
            

            pid_t pid;
            pid = fork();
            if(pid == 0){
                if(execvp(exec_array[0], exec_array) != 0){
                    perror(exec_array[0]);
                    for(int i = 0; exec_array[i] != NULL; i++){
                        free(exec_array[i]);
                    }
                    //free(exec_array);
                    free(cmd);
                    return -1;
                }
            }
            else if(pid < 0) { //why doesnt this handle fork errors??!?!!?
                perror("fork");
                //j'abandonne
            } 

            wait(&pid);

			for(int i = 0; exec_array[i] != NULL; i++){
                free(exec_array[i]);
            }
            //free(exec_array);
            free(cmd);
        }
    }
    	return 0;
}