/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int pipe1[2], pipe2[2];  // Two pipes: pipe1 for parent-to-child, pipe2 for child-to-parent
    pid_t pid;
    char parent_message[] = "Hello, Child!";
    char child_message[] = "Hello, Parent!";
    char buffer[100];

    // Create the first pipe
    if (pipe(pipe1) == -1) {
        perror("Pipe1 failed");
        exit(EXIT_FAILURE);
    }

    // Create the second pipe
    if (pipe(pipe2) == -1) {
        perror("Pipe2 failed");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {  // Parent process
        // Close unnecessary ends
        close(pipe1[0]);  // Close read end of pipe1
        close(pipe2[1]);  // Close write end of pipe2

        // Write a message to the child through pipe1
        write(pipe1[1], parent_message, strlen(parent_message) + 1);
        // Close the write end of pipe1
        close(pipe1[1]);

        // Read a message from the child through pipe2
        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        
        // Close the read end of pipe2
        close(pipe2[0]);
    } else {  // Child process
        // Close unnecessary ends
        close(pipe1[1]);  // Close write end of pipe1
        close(pipe2[0]);  // Close read end of pipe2

        // Read a message from the parent through pipe1
        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        
        // Close the read end of pipe1
        close(pipe1[0]);

        // Write a message to the parent through pipe2
        write(pipe2[1], child_message, strlen(child_message) + 1);
        // Close the write end of pipe2
        close(pipe2[1]);
    }

    return 0;
}


/*
Child received: Hello, Child!
Parent received: Hello, Parent!

*/