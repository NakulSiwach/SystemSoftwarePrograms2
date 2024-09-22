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
#include <unistd.h>

void sigalrm_handler(int signal) {
    printf("Caught SIGALRM: Timer expired (using alarm)\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler); 

    alarm(3);

    printf("Waiting for the alarm...\n");
    pause();  

    return 0;
}

// output 
// ./a.out 
// Waiting for the alarm...
// Caught SIGALRM: Timer expired (using alarm)