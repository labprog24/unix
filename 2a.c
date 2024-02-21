#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main() {
    char buff;
    int fd_one, fd_two;
    
    fd_one = open("first.txt", O_RDONLY);
    fd_two = open("second.txt", O_WRONLY);
    
    while (read(fd_one, &buff, 1)) {
        write(fd_two, &buff, 1);
    }
    
    printf("\ncopied\n");
    
    close(fd_one);
    close(fd_two);
}

