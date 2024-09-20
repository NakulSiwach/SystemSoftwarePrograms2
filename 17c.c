/*

Name : Nakul Siwach
Roll No : MT2024096
Program : Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl

*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

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

        // Use fcntl to set up the file descriptor
        fcntl(pipefd[1], F_DUPFD, STDOUT_FILENO);
        close(pipefd[1]);

        // Execute "ls -l"
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Close unused write end of pipe
        close(pipefd[1]);

        // Use fcntl to set up the file descriptor
        fcntl(pipefd[0], F_DUPFD, STDIN_FILENO);
        close(pipefd[0]);

        // Execute "wc"
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}



/*
total 92
-rw-rw-r-- 1 administrator administrator  1822 Sep 19 17:49 10.c
-rw-rw-r-- 1 administrator administrator  1245 Sep 19 18:14 11.c
-rw-rw-r-- 1 administrator administrator  1570 Sep 19 18:17 12.c
-rw-rw-r-- 1 administrator administrator  1431 Sep 19 18:23 13.c
-rw-rw-r-- 1 administrator administrator  1514 Sep 19 18:29 14.c
-rw-rw-r-- 1 administrator administrator  1427 Sep 19 23:58 15.c
-rw-rw-r-- 1 administrator administrator  2139 Sep 19 23:59 16.c
-rw-rw-r-- 1 administrator administrator  2291 Sep 20 14:53 17a.c
-rw-rw-r-- 1 administrator administrator  1194 Sep 20 15:06 17b.c
-rw-rw-r-- 1 administrator administrator  1195 Sep 20 15:07 17c.c
-rw-rw-r-- 1 administrator administrator   142 Sep 20 15:05 1.c
-rw-rw-r-- 1 administrator administrator  2173 Sep 18 16:19 2.c
-rw-rw-r-- 1 administrator administrator  1648 Sep 18 16:22 3.c
-rw-rw-r-- 1 administrator administrator  1182 Sep 18 16:34 4.c
-rw-rw-r-- 1 administrator administrator  2860 Sep 18 16:40 5.c
-rw-rw-r-- 1 administrator administrator  1320 Sep 18 16:42 6.c
-rw-rw-r-- 1 administrator administrator  1115 Sep 18 16:47 7.c
-rw-rw-r-- 1 administrator administrator   721 Sep 19 16:53 8.c
-rw-rw-r-- 1 administrator administrator  1066 Sep 19 17:03 9.c
-rwxrwxr-x 1 administrator administrator 16208 Sep 20 15:07 a.out
*/