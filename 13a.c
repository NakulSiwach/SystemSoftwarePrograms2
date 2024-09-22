/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Waiting to receive SIGSTOP... (PID: %d)\n", getpid());

    while (1) {
        pause(); 
    }

    return 0;
}

//  ./a.out 
// Waiting to receive SIGSTOP... (PID: 4779)

// [1]+  Stopped                 ./a.out