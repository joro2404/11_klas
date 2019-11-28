#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd = open("a.txt", O_RDONLY);
    char buff[256];
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