/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define BUFFER_SIZE 100

int main() {
    char buffer[BUFFER_SIZE];
    int fd1, fd2;

    mkfifo(FIFO1, 0666);
    mkfifo(FIFO2, 0666);

    while (1) {
        fd1 = open(FIFO1, O_WRONLY);
        printf("Program 1: Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        write(fd1, buffer, strlen(buffer) + 1);
        close(fd1);

        fd2 = open(FIFO2, O_RDONLY);
        read(fd2, buffer, sizeof(buffer));
        printf("Program 2 says: %s\n", buffer);
        close(fd2);
    }

    return 0;
}

    
/*

*/