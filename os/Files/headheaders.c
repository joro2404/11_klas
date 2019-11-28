#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv){
    for (int i = 1; i < argc; i++){
        int fd = open(argv[i], O_RDONLY);
        char buff[256];
        char filename[100];
        if(argc > 2){
            strcpy(filename, (i > 1) ? "\n==> " : "==> ");
            strcat(filename, argv[i]);
            strcat(filename, " <==\n");
            write(STDOUT_FILENO, filename, strlen(filename));
        }
        int status;
        int count = 0;
        while((status = read(fd, buff, 256)) != 0){
            int written = 0;
            while(written < status){
                if(count == 10)break;
                written += write(STDOUT_FILENO, buff + written, 1);
                if(buff[written-1] == '\n'){
                    count ++;
                }
            }
        }
        close(fd);
    }
}