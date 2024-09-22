/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_PATH "my_fifo"
#define BUFFER_SIZE 100

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    fd_set read_fds;
    struct timeval timeout;
    int ret;

    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd = open(FIFO_PATH, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for data in FIFO with a 10-second timeout...\n");

    FD_ZERO(&read_fds);      
    FD_SET(fd, &read_fds);      

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    ret = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Timeout: No data was written to the FIFO within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &read_fds)) {
            int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';  
                printf("Data received from FIFO: %s\n", buffer);
            } else {
                printf("Error reading from FIFO or no data available.\n");
            }
        }
    }

    close(fd);
    unlink(FIFO_PATH); 
    return 0;
}



    
/*
// ./a.out 
// Waiting for data in FIFO with a 10-second timeout...
// Data received from FIFO: Hello from FIFO
*/