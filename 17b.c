/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipefd[2];
    pid_t pid;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        // Close unused read end of pipe
        close(pipefd[0]);

        // Redirect stdout to pipe's write end using dup2
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        // Execute "ls -l"
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Close unused write end of pipe
        close(pipefd[1]);

        // Redirect stdin to pipe's read end using dup2
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);

        // Execute "wc"
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}


/*
     21     182    1304
*/