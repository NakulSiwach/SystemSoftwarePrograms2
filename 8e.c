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

void sigalrm_handler(int signal) {
    printf("Caught SIGALRM: Timer expired (using setitimer)\n");
}

int main() {
    signal(SIGALRM, sigalrm_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;       
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;     
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);

    printf("Waiting for the alarm...\n");
    pause();  

    return 0;
}


// output 
// ./a.out 
// Waiting for the alarm...
// Caught SIGALRM: Timer expired (using setitimer)