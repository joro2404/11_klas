//------------------------------------------------------------------------
// NAME: Georgi Lyubenov
// CLASS: XIb
// NUMBER: 10
// PROBLEM: #1
// FILE NAME: tail.c
// FILE PURPOSE:
// implementation of the linux command tail
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
        char filename[100];
        char* content_of_file = (char*)malloc(sizeof(char));
        int error_detector = 1;

        //Detecting for error: for no such file or directory
        int fd = open(argv[i], O_RDONLY);
        char error_no_such_file[100] = "tail: cannot open '";
        int count_size_error_no_such_file = 0;
        strcat(error_no_such_file, argv[i]);
        strcat(error_no_such_file, "' for reading: ");

        if(fd < 0){
            write(STDERR_FILENO, error_no_such_file, strlen(error_no_such_file));
            perror("");
            error_detector = 0;
        }
        //showing name of the files when we have multiple of them
        if(argc > 2){
            if(error_detector){
                strcpy(filename, (i > 1) ? "\n==> " : "==> ");
                strcat(filename, argv[i]);
                strcat(filename, " <==\n");
                write(STDOUT_FILENO, filename, strlen(filename));
            }
            
        }

        //counting how wlong the file is and then saving it in content_of_file
        int red = 1;
        int count_size = 0;
        while(red > 0){
            if(red = read(fd, content_of_file, 1)){
                count_size++;
                content_of_file = realloc(content_of_file, count_size*sizeof(char));
            }
        }
        lseek(fd, 0, SEEK_SET);
        
        int check = 1;
        while(check > 0){    
            check = read(fd, content_of_file, count_size);
        }

        //count how many new lines have the given file
        int count_new_lines = 0;
        for (int i = 0; i < count_size; i++){
            if(content_of_file[i] == '\n')count_new_lines++;
        }
        

        //with the information of how many new lines we have we create resultvariable to store the last 10 lines
        //also checking if the file has 10 lines or less
        char* result = (char*)malloc(sizeof(char));
        int new_char = 0;
        if(count_new_lines <= 10)write(STDOUT_FILENO, content_of_file, count_size);
        else {
            int lines_to_pass = count_new_lines - 10;
            for (int i = 0; i < count_size; i++){
                if(content_of_file[i] == '\n' && lines_to_pass > 0)lines_to_pass--;
                else if(lines_to_pass == 0){
                    new_char++;
                    result = realloc(result, new_char*sizeof(char));
                    result[new_char-1] = content_of_file[i];
                }
            }
            write(STDOUT_FILENO, result, new_char);
        }

        close(fd);
        free(content_of_file);
        free(result);
    }

}