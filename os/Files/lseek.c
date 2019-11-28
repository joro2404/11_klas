#include <stdio.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <fcntl.h> 

typedef struct
{
    char data;
    unsigned char nextElementAdress;
} block;


int main (int argc, char** argv){
    char buff[256];
    block block;
    int fd = open(argv[1], O_RDONLY);


    while(block.nextElementAdress){
        read(fd, &block, sizeof(block));
        lseek(fd, block.nextElementAdress, SEEK_SET);
        write(STDOUT_FILENO, &block.data, 1);
    }

   // write(STDOUT_FILENO, "\n" , 1);
    close(fd);
    return 0;
}