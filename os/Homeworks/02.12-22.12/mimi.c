#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
char **separate(char *command)
{
	char separate[] =" ";
	int i=0;
    
	char **array;
    array = malloc(sizeof(char*));
    array[0] = malloc(sizeof(char));
	char *ptr = strtok(command,separate);
	while(ptr !=NULL)
	{
        for (int j = 0; j < strlen(ptr); j++){
            if(ptr[j] == '\n')continue;
            array[i] = realloc(array[i], (j+1)*sizeof(char));
            array[i][j] = ptr[j];
        }
        i++;
        array = realloc(array, i*sizeof(char*));
		ptr = strtok(NULL,separate);
	}
    array[i] = NULL;
	return array;
}
int main()
{	while(1){
        printf("$ ");
        int status;
        char command[1024];
        fgets(command,1024,stdin);
        char **array=separate(command);

        // for (int i = 0; array[i] != NULL; i++){
        //     printf("%s\n",array[i]);
        // }
        
        int process = fork();
        if(process == 0){
            if(execvp(array[0], array) != 0){
                perror(array[0]);
                break;
            }
        } else if(process == -1) {
            perror("fork");
        }

        if(waitpid(process, &status, 0) != process) {
            perror("");
            return -1;
        }
    }

}