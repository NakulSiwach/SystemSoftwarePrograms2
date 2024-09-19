/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 15. Write a simple program to send some data from parent to the child process.

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int pipefd[2];  // Array to hold the two ends of the pipe: pipefd[0] for reading, pipefd[1] for writing
    pid_t pid;
    char message[] = "Hello, Child Process!";
    char buffer[100];

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {  // Parent process
        // Close the read end of the pipe in the parent process
        close(pipefd[0]);
        // Write data to the pipe
        write(pipefd[1], message, strlen(message) + 1);  // +1 to include the null terminator
        // Close the write end of the pipe
        close(pipefd[1]);
    } else {  // Child process
        // Close the write end of the pipe in the child process
        close(pipefd[1]);
        // Read data from the pipe
        read(pipefd[0], buffer, sizeof(buffer));
        // Print the received message
        printf("Child received: %s\n", buffer);
        // Close the read end of the pipe
        close(pipefd[0]);
    }

    return 0;
}



/*
Child received: Hello, Child Process!
*/