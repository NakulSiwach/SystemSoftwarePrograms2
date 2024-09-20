/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd1[2], pipefd2[2];
    pid_t pid1, pid2;

    // Create the first pipe for "ls -l" to "grep ^d"
    if (pipe(pipefd1) == -1) {
        perror("pipe1");
        exit(EXIT_FAILURE);
    }

    // Fork the first child for "ls -l"
    if ((pid1 = fork()) == -1) {
        perror("fork1");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) { // First child process
        // Close the read end of the first pipe
        close(pipefd1[0]);
        // Redirect stdout to the write end of the first pipe
        dup2(pipefd1[1], STDOUT_FILENO);
        // Close the original write end of the pipe
        close(pipefd1[1]);

        // Execute "ls -l"
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(EXIT_FAILURE);
    } else {
        // Create the second pipe for "grep ^d" to "wc -l"
        if (pipe(pipefd2) == -1) {
            perror("pipe2");
            exit(EXIT_FAILURE);
        }

        // Fork the second child for "grep ^d"
        if ((pid2 = fork()) == -1) {
            perror("fork2");
            exit(EXIT_FAILURE);
        }

        if (pid2 == 0) { // Second child process
            // Close the write end of the first pipe
            close(pipefd1[1]);
            // Redirect stdin to the read end of the first pipe
            dup2(pipefd1[0], STDIN_FILENO);
            // Close the original read end of the pipe
            close(pipefd1[0]);

            // Close the read end of the second pipe
            close(pipefd2[0]);
            // Redirect stdout to the write end of the second pipe
            dup2(pipefd2[1], STDOUT_FILENO);
            // Close the original write end of the pipe
            close(pipefd2[1]);

            // Execute "grep ^d"
            execlp("grep", "grep", "^d", NULL);
            perror("execlp grep");
            exit(EXIT_FAILURE);
        } else { // Parent process
            // Close unused ends of pipes
            close(pipefd1[0]);
            close(pipefd1[1]);
            close(pipefd2[1]);

            // Redirect stdin to the read end of the second pipe
            dup2(pipefd2[0], STDIN_FILENO);
            // Close the original read end of the second pipe
            close(pipefd2[0]);

            // Execute "wc -l" to count the number of directories
            execlp("wc", "wc", "-l", NULL);
            perror("execlp wc");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}


    
/*
0
*/