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
#include <sys/time.h>
#include<unistd.h>

void sigvtalrm_handler(int signal) {
    printf("Caught SIGVTALRM: Virtual timer expired\n");
}

int main() {
    signal(SIGVTALRM, sigvtalrm_handler); 
    struct itimerval timer;
    timer.it_value.tv_sec = 2;        
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;     
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Failed to set virtual timer");
        return 1;
    }
    

    printf("Performing CPU-intensive work...\n");
    for (long long i = 0; i < 1e9; ++i) {
        int x = i * i;
    }
    return 0;
}

// output 
// ./a.out 
// Performing CPU-intensive work...
// Caught SIGVTALRM: Virtual timer expired