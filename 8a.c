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

void sigsegv_handler(int signum) {
    printf("Caught signal SIGSEGV (Segmentation Fault)\n");
    exit(1);  // Exit after catching signal
}

int main() {
    signal(SIGSEGV, sigsegv_handler);

    // Trigger a segmentation fault
    int *p = NULL;
    *p = 10;

    return 0;
}





/*
Caught signal SIGSEGV (Segmentation Fault)
*/