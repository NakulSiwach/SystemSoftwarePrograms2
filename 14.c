/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];  // Array to hold pipe file descriptors
    pid_t pid;
    char write_msg[] = "Hello, this is a message from the pipe!";
    char read_msg[100];

    // Create the pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process: Close the read end of the pipe
        close(fd[0]);

        // Write a message to the pipe
        write(fd[1], write_msg, strlen(write_msg) + 1); // +1 to include the null terminator
        printf("Child: Wrote to the pipe: \"%s\"\n", write_msg);

        // Close the write end of the pipe
        close(fd[1]);
    } else {
        // Parent process: Close the write end of the pipe
        close(fd[1]);

        // Read from the pipe
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Parent: Read from the pipe: \"%s\"\n", read_msg);

        // Close the read end of the pipe
        close(fd[0]);
    }

    return 0;
}




/*
Child: Wrote to the pipe: "Hello, this is a message from the pipe!"
Parent: Read from the pipe: "Hello, this is a message from the pipe!"
*/