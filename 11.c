/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Custom handler that ignores SIGINT
void ignore_sigint(int signum) {
    printf("SIGINT signal ignored\n");
}

int main() {
    struct sigaction sa;

    // Set up the sigaction to ignore SIGINT
    sa.sa_handler = ignore_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is now ignored. Try pressing Ctrl+C.\n");
    sleep(5);  // Sleep for 5 seconds to demonstrate ignoring SIGINT

    // Reset the sigaction to the default action for SIGINT
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT action reset to default. Try pressing Ctrl+C again.\n");
    sleep(5);  // Sleep for another 5 seconds to demonstrate default SIGINT action

    printf("Program exiting normally.\n");
    return 0;
}



/*
SIGINT is now ignored. Try pressing Ctrl+C.
SIGINT action reset to default. Try pressing Ctrl+C again.
Program exiting normally.
*/