/*

Name : Nakul Siwach
Roll No : MT2024096
Program : 10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINTc. SIGFPE

*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Handler for SIGSEGV (Segmentation Fault)
void handle_sigsegv(int signum) {
    printf("Caught SIGSEGV: Segmentation Fault\n");
    exit(EXIT_FAILURE); // Exit the program after handling the signal
}

// Handler for SIGINT (Interrupt Signal)
void handle_sigint(int signum) {
    printf("Caught SIGINT: Interrupt Signal (Ctrl+C)\n");
    // Continue running the program, do not exit
}

// Handler for SIGFPE (Floating Point Exception)
void handle_sigfpe(int signum) {
    printf("Caught SIGFPE: Floating Point Exception\n");
    exit(EXIT_FAILURE); // Exit the program after handling the signal
}

int main() {
    struct sigaction sa;

    // Setting up the handler for SIGSEGV
    sa.sa_handler = handle_sigsegv;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, NULL);

    // Setting up the handler for SIGINT
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    // Setting up the handler for SIGFPE
    sa.sa_handler = handle_sigfpe;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGFPE, &sa, NULL);

    printf("Signal handlers are set up. Try triggering them:\n");
    printf("1. Press Ctrl+C to trigger SIGINT.\n");
    printf("2. Cause a segmentation fault by dereferencing a NULL pointer.\n");
    printf("3. Cause a floating-point exception (e.g., divide by zero).\n");

    // Infinite loop to keep the program running and responsive to signals
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}




/*

*/