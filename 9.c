/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function to ignore SIGINT
void sigint_ignore_handler(int signum) {
    printf("SIGINT signal ignored\n");
}

int main() {
    // Set the handler for SIGINT to the custom ignore handler
    signal(SIGINT, sigint_ignore_handler);
    printf("SIGINT is now ignored. Try pressing Ctrl+C.\n");

    // Sleep for 5 seconds to allow user to test SIGINT
    sleep(5);

    // Reset the handler for SIGINT to the default action
    signal(SIGINT, SIG_DFL);
    printf("SIGINT action reset to default. Try pressing Ctrl+C again.\n");

    // Sleep for another 5 seconds to allow user to test SIGINT again
    sleep(5);

    printf("Program exiting normally.\n");
    return 0;
}



/*
SIGINT is now ignored. Try pressing Ctrl+C.
SIGINT action reset to default. Try pressing Ctrl+C again.
Program exiting normally
*/