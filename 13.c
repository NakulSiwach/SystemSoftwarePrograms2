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


// Handler for signals
void signal_handler(int signum) {
    printf("Caught signal: %d\n", signum);
}

int main() {
    // Register signal handler for SIGINT and SIGCONT
    signal(SIGINT, signal_handler);  // Catch Ctrl+C
    signal(SIGCONT, signal_handler); // Catch continue signal

    printf("Process PID: %d is waiting for SIGSTOP or SIGCONT signal.\n", getpid());

    // Infinite loop to keep the process alive
    while (1) {
        pause();  // Wait for signals
    }

    pid_t pid;

    printf("Enter the PID of the first program to send SIGSTOP: ");
    scanf("%d", &pid);

    // Send SIGSTOP to the given process
    if (kill(pid, SIGSTOP) == 0) {
        printf("SIGSTOP signal sent to process %d successfully.\n", pid);
    } else {
        perror("Failed to send SIGSTOP signal");
    }

    sleep(2);

    // Optionally send SIGCONT to resume the process
    if (kill(pid, SIGCONT) == 0) {
        printf("SIGCONT signal sent to process %d successfully.\n", pid);
    } else {
        perror("Failed to send SIGCONT signal");
    }

    return 0;
}





/*

*/