//------------------------------------------------------------------------
// NAME: Georgi Lyubenov
// CLASS: XIb
// NUMBER: 10
// PROBLEM: #1
// FILE NAME: tail.c
// FILE PURPOSE:
// realisation of the linux command tail
// ...
//------------------------------------------------------------------------


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main (int argc, char **argv){

    //creating for cycle for each of the arguments and some variables to help us solve the problem
    for(int i = 1; i < argc; i++){
        int fd = open(argv[i], O_RDONLY);
        char filename[100];
        char* content_of_file = (char*)malloc(sizeof(char));

        //showing name of the files when we have multiple of them
        if(argc > 2){
            strcpy(filename, (i > 1) ? "\n==> " : "==> ");
            strcat(filename, argv[i]);
            strcat(filename, " <==\n");
            write(STDOUT_FILENO, filename, strlen(filename));
        }

        //counting how wlong the file is and then saving it in content_of_file
        int red = 1;
        int count_size = 0;
        while(red > 0){
            count_size++;
            content_of_file = realloc(content_of_file, count_size*sizeof(char));
            red = read(fd, content_of_file, 1);
        }
        fd = open(argv[i], O_RDONLY);
        read(fd, content_of_file, count_size);

        //count how many new lines have the given file
        int count_new_lines = 0;
        for (int i = 0; i < strlen(content_of_file); i++){
            if(content_of_file[i] == '\n')count_new_lines++;
        }
        
        //with the information of how many new lines we have we create resultvariable to store the last 10 lines
        //also checking if the file has 10 lines or less
        char* result = (char*)malloc(sizeof(char));
        int new_char = 0;
        if(count_new_lines <= 9)write(STDOUT_FILENO, content_of_file, strlen(content_of_file));
        else {
            int lines_to_pass = count_new_lines - 9;
            for (int i = 0; i < strlen(content_of_file); i++){
                if(content_of_file[i] == '\n' && lines_to_pass > 0)lines_to_pass--;
                else if(lines_to_pass == 0){
                    new_char++;
                    result = realloc(result, new_char*sizeof(char));
                    result[new_char-1] = content_of_file[i];
                }
            }
        }
        write(STDOUT_FILENO, result, strlen(result));
        
        close(fd);
        free(content_of_file);
        free(result);
    }

}