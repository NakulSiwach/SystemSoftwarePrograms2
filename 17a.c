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

        // Redirect stdout to pipe's write end
        dup(pipefd[1]);
        close(pipefd[1]);

        // Execute "ls -l"
        execlp("ls", "ls", "-l", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    } else { // Parent process
        // Close unused write end of pipe
        close(pipefd[1]);

        // Redirect stdin to pipe's read end
        dup(pipefd[0]);
        close(pipefd[0]);

        // Execute "wc"
        execlp("wc", "wc", NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    return 0;
}



/*
total 84
-rw-rw-r-- 1 administrator administrator  1822 Sep 19 17:49 10.c
-rw-rw-r-- 1 administrator administrator  1245 Sep 19 18:14 11.c
-rw-rw-r-- 1 administrator administrator  1570 Sep 19 18:17 12.c
-rw-rw-r-- 1 administrator administrator  1431 Sep 19 18:23 13.c
-rw-rw-r-- 1 administrator administrator  1514 Sep 19 18:29 14.c
-rw-rw-r-- 1 administrator administrator  1427 Sep 19 23:58 15.c
-rw-rw-r-- 1 administrator administrator  2139 Sep 19 23:59 16.c
-rw-rw-r-- 1 administrator administrator  1119 Sep 20 14:52 17a.c
-rw-rw-r-- 1 administrator administrator    68 Sep 19 18:24 1.c
-rw-rw-r-- 1 administrator administrator  2173 Sep 18 16:19 2.c
-rw-rw-r-- 1 administrator administrator  1648 Sep 18 16:22 3.c
-rw-rw-r-- 1 administrator administrator  1182 Sep 18 16:34 4.c
-rw-rw-r-- 1 administrator administrator  2860 Sep 18 16:40 5.c
-rw-rw-r-- 1 administrator administrator  1320 Sep 18 16:42 6.c
-rw-rw-r-- 1 administrator administrator  1115 Sep 18 16:47 7.c
-rw-rw-r-- 1 administrator administrator   721 Sep 19 16:53 8.c
-rw-rw-r-- 1 administrator administrator  1066 Sep 19 17:03 9.c
-rwxrwxr-x 1 administrator administrator 16208 Sep 20 14:53 a.out

*/