/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)

*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include<unistd.h>

void sigint_handler(int signal) {
    printf("Caught SIGINT: Interrupt Signal (Ctrl+C)\n");
    exit(1);
}

int main() {
    signal(SIGINT, sigint_handler);  

    while (1) {
        printf("Running... Press Ctrl+C to trigger SIGINT.\n");
        sleep(1);
    }

    return 0;
}

// output 
// ./a.out 
// Running... Press Ctrl+C to trigger SIGINT.
// Running... Press Ctrl+C to trigger SIGINT.
// Running... Press Ctrl+C to trigger SIGINT.
// ^CCaught SIGINT: Interrupt Signal (Ctrl+C)