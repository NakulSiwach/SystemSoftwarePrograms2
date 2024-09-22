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

void sigfpe_handler(int signal) {
    printf("Caught SIGFPE: Floating Point Exception\n");
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);

    int a = 5;
    int b = 0;
    int c = a / b;

    return 0;
}

// output 
// ./a.out 
// Caught SIGFPE: Floating Point Exception