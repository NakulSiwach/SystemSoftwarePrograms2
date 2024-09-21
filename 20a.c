/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 20. Write two programs so that both can communicate by FIFO -Use one way communication.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_NAME "myfifo"

int main() {
    int fd;
    char *message = "Hello from the sender!";

    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, message, sizeof(message));
    printf("Sender: Wrote message to FIFO\n");

    close(fd);
    
    return 0;
}

    
/*
Sender: Wrote message to FIFO
*/