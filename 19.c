/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {


    // mkfifo my_fifo

    // mkfifo my_fifo

    // strace mknod my_fifo p
    // mknod("my_fifo", S_IFIFO | 0666, 0) = 0

    // strace mkfifo my_fifo
    // mkfifo("my_fifo", 0666) = 0


    // Create a FIFO named "my_fifo" with read/write permissions for user, group, and others
    if (mknod("my_fifo1", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        exit(EXIT_FAILURE);
    }

    printf("FIFO 'my_fifo' created using mknod system call.\n");


    // Create a FIFO named "my_fifo" with read/write permissions for user, group, and others
    if (mkfifo("my_fifo2", 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO 'my_fifo' created using mkfifo library function.\n");

    return 0;
}



    
/*
FIFO 'my_fifo' created using mknod system call.
FIFO 'my_fifo' created using mkfifo library function.
*/