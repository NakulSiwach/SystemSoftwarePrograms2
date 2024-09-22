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
    pid_t pid;

    printf("Enter the PID of the process to stop: ");
    scanf("%d", &pid); 

    if (kill(pid, SIGSTOP) == -1) {
        perror("Failed to send SIGSTOP");
        exit(EXIT_FAILURE);
    }

    printf("SIGSTOP signal sent to process with PID: %d\n", pid);

    return 0;
}

// ./a.out 
// Enter the PID of the process to stop: 4779
// SIGSTOP signal sent to process with PID: 4779